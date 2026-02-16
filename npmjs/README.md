Node.js binding to libtexprintf
===============================

This package provides Node.js bindings to [libtexprintf](https://github.com/bartp5/libtexprintf).

Intallation
---------------
Install from npm (recommended):

```sh
npm install libtexprintf
```

Usage:
---------------
After installation

```js
import { loadInstance, createRender } from "libtexprintf";

const instance = await loadInstance();
const render = createRender(instance);
console.log(render("\\frac{\\alpha}{\\beta+x}"));
```

Build:
---------------
Build from source (`libtexprintf.wasm` as standalone WASM with `texstring` export):

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
  -Wl,--export=texfree \
  -Wl,--export=malloc \
  -Wl,--export=free \
  -o libtexprintf.wasm \
  src/.libs/libtexprintf.a
```
