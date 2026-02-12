const encoder = new TextEncoder();
const decoder = new TextDecoder();

/**
 * @typedef {object} TexprintfExports
 * @property {WebAssembly.Memory} memory
 * @property {(size: number) => number} malloc
 * @property {(ptr: number) => void} free
 * @property {(inputPtr: number) => number} texstring
 * @property {(outputPtr: number) => void} texfree
 */

/**
 * @typedef {WebAssembly.Instance & { exports: TexprintfExports }} TexprintfInstance
 */

/**
 * Create a renderer from an already instantiated libtexprintf WASM instance.
 *
 * @param {TexprintfInstance} instance
 * @returns {(latex: string) => string}
 */
export function createRender(instance) {
  if (!(instance instanceof WebAssembly.Instance)) {
    throw new TypeError("createRender expects a WebAssembly.Instance");
  }

  /** @type {TexprintfExports} */
  const { memory, malloc, free, texstring, texfree } = instance.exports;
  if (!memory || !malloc || !free || !texstring || !texfree) {
    throw new Error("WASM module is missing one or more required exports");
  }

  return function render(latex) {
    const input = encoder.encode(String(latex) + "\0");
    const inputPtr = malloc(input.length);

    try {
      new Uint8Array(memory.buffer, inputPtr, input.length).set(input);
      const outputPtr = texstring(inputPtr);

      try {
        const mem = new Uint8Array(memory.buffer);
        let end = outputPtr;
        while (mem[end] !== 0) {
          end += 1;
        }
        return decoder.decode(mem.subarray(outputPtr, end));
      } finally {
        texfree(outputPtr);
      }
    } finally {
      free(inputPtr);
    }
  };
}
