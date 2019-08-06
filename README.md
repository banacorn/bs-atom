# bs-atom

(Incomplete) Atom bindings for BuckleScript

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

For classes like `Point`s and `Range`s, instead of 

```js
const p = new Point(0, 3);
```

use `make` to construct them:

```reason
let p = Atom.Point.make(0, 3);
```

also, they come with getters:

```reason
let row = p.row;
```
