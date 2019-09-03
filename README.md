# bs-atom

Complete Atom API bindings for BuckleScript (as for `1.40.1`)

**All pull request are welcome**

## Installation

```bash
npm install --save @banacorn/bs-atom
```

Then add `@banacorn/bs-atom` to `bs-dependencies` in your `bsconfig.json`:

```js
{
  ...
  "bs-dependencies": ["@banacorn/bs-atom"]
}
```

## Usage

For managers like `ViewRegistry` or `Config` that are instantiated by Atom under the `atom` global.
Access them from the `Atom` module:

```reason
Atom.Config.set("core.themes", [|"atom-light-ui", "atom-light-syntax"|]);
```

Instances of class like `TextEditor` would have type `Atom.TextEditor.t`.
Methods are invoked in the  **pipe last** fashion:

```reason
textEditor
  |> Atom.TextEditor.getTextInBufferRange(range);
```

Use `make` to construct instances of classes like `Point`s or `Range`s:

```reason
let p = Atom.Point.make(0, 3);
```

also, they come with getters:

```reason
let row = p.row;
```

## Uncharted modules

* [TextEditorRegistry](https://github.com/atom/atom/blob/v1.40.0/src/text-editor-registry.js)

## How to deal with optional arguments

Some functions may have options. Take `Atom.TextEditor.setText` for example:

```
setText: (string, t) => unit
```

`setText` may take an an extra JS object as the second argument. We suffix these "opinionated" functions with `_`.

```
setText_: (string, {. "bypassReadOnly": bool}, t) => unit
```

### Options with optional fields

`atom.config.set` may take an extra argument:

```js
atom.config.set('editor.tabLength', 2, {
  scopeSelector: ['source.js'],
  scope: ['someFile']
})
```

Both `scopeSelector` and `scope` in the object may be omitted.
Instead of having 4 variants of `setText_`, we simply type those optional fields as `option(...)`.

```reason
set_: (string, value, {
  .
  "scopeSelector": option(string),
  "source": option(string),
}) => bool
```

```reason
Atom.config.set_("core.themes", [|"atom-light-ui"|], {
  .
  "scopeSelector": Some([|"source.js"|]),
  "source": None
});
```

**Note**: not all optional fields of options are typed this way
