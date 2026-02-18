// test/libtexprintf.test.js
import test from "node:test";
import assert from "node:assert/strict";
import { createRender, loadInstance } from "./libtexprintf.js";

/* ------------------------------------------------------------------
 * createRender sanity – non‑instance argument
 * ------------------------------------------------------------------*/
test("createRender rejects non‑WebAssembly instances", () => {
  assert.throws(
    () => createRender({}),
    /createRender expects a WebAssembly\.Instance/
  );
});

/* ------------------------------------------------------------------
 * basic rendering
 * ------------------------------------------------------------------*/
test("render fraction", async () => {
  const instance = await loadInstance();
  const render = createRender(instance);
  const { output, errors } = render("\\frac{\\alpha}{\\beta+x}");

  assert.deepEqual(errors, [], "no errors should be reported");
  assert.equal(
    output,
    " α\n───\nβ+x",
    "fraction should match the expected string"
  );
});

/* ------------------------------------------------------------------
 * set font style
 * ------------------------------------------------------------------*/
test("setFontstyle changes rendering", async () => {
  const instance = await loadInstance();
  const render = createRender(instance);

  // Switch to a different font.  `text` is a valid font style in libtexprintf.
  assert.doesNotThrow(() => render.setFontstyle("mathnormal"),
    "setFontstyle('mathnormal') should not throw");

  const { output } = render("\\frac{\\alpha}{\\beta+x}");
  assert.equal(
    output,
    " α\n───\nβ+𝑥",
    "fraction in should match the expected string in mathnormal style"
  );
});

/* ------------------------------------------------------------------
 * invalid input
 * ------------------------------------------------------------------*/
test("render with invalid LaTeX reports errors", async () => {
  const instance = await loadInstance();

  const render = createRender(instance);

  const { output, errors } = render("\\invalid{\\alpha");

  assert.ok(
    errors.length > 0,
    "renderer should report at least one error"
  );

  assert.ok(
    typeof output === "string",
    "output should still be a string even on error"
  );
});


/* ------------------------------------------------------------------
 * onError callback
 * ------------------------------------------------------------------*/
test("onError callback receives errors", async () => {
  const instance = await loadInstance();

  const callbackErrors = [];
  const render = createRender(instance, {
    onError: (errs) => callbackErrors.push(...errs),
  });

  render("\\invalid{\\alpha"); /*  triggers error  */

  assert.ok(
    callbackErrors.length > 0,
    "onError callback should have been called with error(s)"
  );
});

/* ------------------------------------------------------------------
 * throwOnError option
 * ------------------------------------------------------------------*/
test("throwOnError makes render throw on any error", async () => {
  const instance = await loadInstance();

  const renderThrow = createRender(instance, { throwOnError: true });

  assert.throws(
    () => renderThrow("\\invalid{\\alpha"),
    /Error: .+/,
    "render should throw an Error when throwOnError is true"
  );
});

/* ------------------------------------------------------------------
 * throwOnError wins over onError
 * ------------------------------------------------------------------*/
test("throwOnError overrides onError callback", async () => {
  const instance = await loadInstance();

  const callbackErrors = [];
  const renderThrow = createRender(instance, {
    onError: (errs) => callbackErrors.push(...errs),
    throwOnError: true,
  });

  assert.throws(
    () => renderThrow("\\invalid{\\alpha"),
    /Error: .+/,
    "render should throw, even if onError is set"
  );

  assert.strictEqual(
    callbackErrors.length,
    0,
    "onError callback should **not** have been invoked"
  );
});

/* ------------------------------------------------------------------
 * loadInstance sanity 
 * ------------------------------------------------------------------*/
test("loadInstance provides a functional WebAssembly instance", async () => {
  const instance = await loadInstance();
  // Basic sanity‑check: ensure all required exports exist
  const required = [
    "memory",
    "malloc",
    "free",
    "texstring",
    "texerrors_str",
    "SetRootFont",
  ];
  required.forEach((name) => {
    assert.ok(
      instance.exports[name],
      `WASM instance is missing required export '${name}'`
    );
  });

  // Quick round‑trip: create a renderer and render something trivial
  const render = createRender(instance);
  const { output } = render("1+2");

  assert.ok(
    typeof output === "string" && output.length > 0,
    "rendering must produce a non‑empty string"
  );
});
