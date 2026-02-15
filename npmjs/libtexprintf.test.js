import test from "node:test";
import assert from "node:assert/strict";
import { readFile } from "node:fs/promises";

import { createRender } from "./libtexprintf.js";

async function createInstance() {
  const wasmBytes = await readFile(new URL("../libtexprintf.wasm", import.meta.url));
  const imports = {
    wasi_snapshot_preview1: {
      proc_exit(code) {
        throw new Error(`WASM requested proc_exit(${code})`);
      },
      fd_close() {
        return 0;
      },
      fd_write() {
        return 0;
      },
      fd_seek() {
        return 0;
      },
    },
  };
  const { instance } = await WebAssembly.instantiate(wasmBytes, imports);
  return instance;
}

test("createRender rejects non-WebAssembly instances", () => {
  assert.throws(
    () => createRender({}),
    /createRender expects a WebAssembly\.Instance/
  );
});

test("render fraction", async () => {
  const instance = await createInstance();
  const render = createRender(instance);
  assert.equal(render("\\frac{\\alpha}{\\beta+x}"), " α\n───\nβ+x");
});
