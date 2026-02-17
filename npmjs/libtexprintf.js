// libtexprintf.js
import { readFile } from "node:fs/promises";
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
  const { memory, malloc, free, texstring, texerrors_str, SetRootFont} = instance.exports;
  if (!memory || !malloc || !free || !texstring || !texerrors_str || !SetRootFont) {
    throw new Error("WASM module is missing one or more required exports");
  }
  /* --------------------------------------------------------------
   * read a NUL‑terminated string owned by the WASM module.
   * -------------------------------------------------------------- */
  function decodePtr(ptr, mem, dec) {
    const buf = new Uint8Array(mem.buffer);
    let end = ptr;
    while (buf[end] !== 0) end += 1;
    return dec.decode(buf.subarray(ptr, end));
  }
  
  function setFontstyle(name) {
    const buf = encoder.encode(name + "\0");
    const ptr = malloc(buf.length);
    new Uint8Array(memory.buffer, ptr, buf.length).set(buf);
    SetRootFont(ptr);
    free(ptr);
	const errPtr  = texerrors_str();    
    try {  
		const errText = decodePtr(errPtr, memory, decoder);
	    // see if there are errors
	    if (errText.length > 0) {
		  // `;` is the delimiter used by libtexprintf
		  console.groupCollapsed(`texprintf error(s):`);
		  errText.split(";").filter(Boolean).forEach(msg =>
		  console.error(`  • ${msg}`)
		);
		console.groupEnd();
        }
     } finally {
        free(errPtr);
     }
  }
  function render(latex) {
    const input = encoder.encode(String(latex) + "\0");
    const inputPtr = malloc(input.length);

    try {
      new Uint8Array(memory.buffer, inputPtr, input.length).set(input);
      const outPtr = texstring(inputPtr);
      const errPtr  = texerrors_str();                

      try {
		const outText = decodePtr(outPtr, memory, decoder);  
		const errText = decodePtr(errPtr, memory, decoder);
	    // see if there are errors
	    if (errText.length > 0) {
		  // `;` is the delimiter used by libtexprintf
		  console.groupCollapsed(`texprintf error(s):`);
		  errText.split(";").filter(Boolean).forEach(msg =>
		    console.error(`  • ${msg}`)
		  );
		  console.groupEnd();
        }
		return outText;
      } finally {
        free(outPtr);
        free(errPtr);
      }
    } finally {
      free(inputPtr);
    }
  }
  render.setFontstyle = setFontstyle;
  return render;
}


/** @returns {Promise<WebAssembly.Instance>} */
export async function loadInstance() {
  // Locate the wasm file relative to this module
  const wasmFile = new URL("./libtexprintf.wasm", import.meta.url);

  // Read it (Node) ‑ you can also use `fetch()` in browsers
  const wasmBytes = await readFile(wasmFile);

  // Instantiate with the imports you already defined
  const imports = {
    wasi_snapshot_preview1: {
      proc_exit(code) {
        throw new Error(`WASM requested proc_exit(${code})`);
      },
      fd_close() { return 0; },
      fd_write() { return 0; },
      fd_seek()  { return 0; },
    },
  };
  const { instance } = await WebAssembly.instantiate(wasmBytes, imports);
  return instance;            // <-- caller gets a ready‑to‑use instance
}
