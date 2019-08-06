open Atom__Type;

/* add: Registering one command */
[@bs.val] [@bs.scope ("atom", "commands")]
external add:
  (
    [@bs.unwrap] [ | `CSSSelector(string) | `HtmlElement(Dom.htmlElement)],
    string,
    Dom.event => unit
  ) =>
  Disposable.t =
  "add";

/* add: Registering multiple commands */
[@bs.val] [@bs.scope ("atom", "commands")]
external addMany:
  (
    [@bs.unwrap] [ | `CSSSelector(string) | `HtmlElement(Dom.htmlElement)],
    Js.t({..})
  ) =>
  Disposable.t =
  "add";

/* findCommand */
type commandDescriptor = {
  .
  "name": string,
  "displayName": string,
  "description": string,
  "tags": array(string),
};
[@bs.val] [@bs.scope ("atom", "commands")]
external findCommand:
  {. "target": Dom.htmlElement} => array(commandDescriptor) =
  "findCommand";

/* dispatch */
[@bs.val] [@bs.scope ("atom", "commands")]
external dispatch: (Dom.htmlElement, string) => option(Js.Promise.t(unit)) =
  "dispatch";

type event;

/* onWillDispatch*/
[@bs.val] [@bs.scope ("atom", "commands")]
external onWillDispatch: (event => unit) => Disposable.t = "onWillDispatch";

/* onDidDispatch*/
[@bs.val] [@bs.scope ("atom", "commands")]
external onDidDispatch: (event => unit) => Disposable.t = "onDidDispatch";
