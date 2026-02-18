Node.js binding to libtexprintf
===============================

`libtexprintf` is a JavaScript wrapper around the C library [libtexprintf](https://github.com/bartp5/libtexprintf).  
It lets you turn LaTeX expressions into plain‑text “renderings”.


Intallation
---------------
Install from npm (recommended):

```sh
npm install libtexprintf
```

Optional: If you want to develop the native side or rebuild the WASM file, see
the build‑section below.

Quick Start:
---------------

```js
import { loadInstance, createRender } from "libtexprintf";

async function demo() {
  // Load the WASM binary
  const wasmInstance = await loadInstance(); // returns a `WebAssembly.Instance`

  // Create a renderer
  const render = createRender(wasmInstance);

  // Render a LaTeX string
  const { output, errors } = render("\\frac{\\alpha}{\\beta+x}");

  console.log(output);
  console.error(errors); // [] – nothing went wrong

  // Switch font
  render.setFontstyle("mathnormal");
  console.log(render("Hello")); // ← 𝐻𝐸𝐿𝐿𝑂
}
demo().catch(console.error);
```

API Reference
---------------

| Export | Type | Description |
|--------|------|-------------|
| `loadInstance()` | `Promise<WebAssembly.Instance>` | Loads the bundled `libtexprintf.wasm` and returns an instantiated module. |
| `createRender(instance, options)` | `(latex: string) ⇒ { output: string, errors: string[] }` | Wraps the WASM module and returns a **rendering function**.<br>**Options**:<br>• `onError? (errs: string[]) ⇒ void` – callback for error messages.<br>• `throwOnError? boolean` – if `true`, `render()` throws a JS Error whenever libtexprintf emits an error (takes precedence over `onError`). |

### The render function

```js
const { output, errors } = render(latexString);
```

- `output` – the rendered plain‑text string (multi‑line, may contain Unicode math symbols). 
- `errors` - an array of error messages reported by libtexprintf. Empty when rendering succeeds.

If you set throwOnError: true, render() will throw instead of returning an errors array.

### Font styles

```js
render.setFontstyle("mathnormal");   // other names: "text", "mathfrak", etc.
```
See the libtexprintf documentation for the avialable styles.


### Error handling
#### Default behavior

```js
const { output, errors } = render("\\invalid{\\alpha");
//  errors: [ 'Unknown command (1x)' ]
```

#### Custom callback
```js
const render = createRender(instance, {
  onError: (errs) => console.warn("libtexprintf says:", ...errs),
});
```

#### Throwing
```js
const render = createRender(instance, { throwOnError: true });

try {
  render("\\invalid{\\alpha");
} catch (e) {
  console.error("Render failed:", e.message);
}
```
If both onError and throwOnError: true are supplied, the exception is thrown and the callback is not invoked.


Building from source
--------------------
To build the WASM object you need to first obtain the libtexprintf C code at [libtexprintf](https://github.com/bartp5/libtexprintf).  
Build the `libtexprintf.wasm` as standalone WASM with `texstring` export:

```sh
emconfigure ./configure \
  --host=wasm32-unknown-emscripten \
  --disable-shared \
  --enable-static \
  CFLAGS='-O3' LDFLAGS='-s STANDALONE_WASM=1'
emmake make -j4

emcc -O3 -s STANDALONE_WASM=1 \
  -Wl,--no-entry \
  -Wl,--export=texstring \
  -Wl,--export=texstring \
  -Wl,--export=texerrors_str \
  -Wl,--export=malloc \
  -Wl,--export=free \
  -Wl,--export=SetRootFont \
  -o libtexprintf.wasm \
  src/.libs/libtexprintf.a
```
