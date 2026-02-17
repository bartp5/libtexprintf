// test/libtexprintf.test.js
import test from "node:test";
import assert from "node:assert/strict";
import { createRender, loadInstance } from "./libtexprintf.js";

test("createRender rejects non‑WebAssembly instances", () => {
  assert.throws(
    () => createRender({}),
    /createRender expects a WebAssembly\.Instance/
  );
});

test("render fraction", async () => {
  const instance = await loadInstance();
  const render = createRender(instance);

  assert.equal(
    render("\\frac{\\alpha}{\\beta+x}"),
    " α\n───\nβ+x",
    "fraction should match the expected string"
  );
});

test("setFontstyle changes rendering", async () => {
  const instance = await loadInstance();
  const render = createRender(instance);

  // Switch to a different font.  `text` is a valid font style in libtexprintf.
  assert.doesNotThrow(() => render.setFontstyle("mathnormal"),
    "setFontstyle('mathnormal') should not throw");

  assert.equal(
    render("\\frac{\\alpha}{\\beta+x}"),
    " α\n───\nβ+𝑥",
    "fraction in should match the expected string in mathnormal style"
  );
});

test("loadInstance provides a functional WebAssembly instance", async () => {
  const instance = await loadInstance();

  // Basic sanity‑check: ensure all required exports exist
  const required =
    ["memory", "malloc", "free", "texstring", "texerrors_str", "SetRootFont"];
  required.forEach((name) => {
    assert.ok(
      instance.exports[name],
      `WASM instance is missing required export '${name}'`
    );
  });

  // Quick round‑trip: create a renderer and render something trivial
  const render = createRender(instance);
  const out = render("1+2");
  assert.ok(
    typeof out === "string" && out.length > 0,
    "rendering must produce a non‑empty string"
  );
});
