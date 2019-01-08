open Atom__Type;

include Pane;

/* Pane Items */
[@bs.send.pipe: paneItem] external getTitle : string = "getTitle";

/* Event Subscription */
[@bs.send.pipe: t]
external onDidChangeFlexScale : (int => unit) => Disposable.t =
  "onDidChangeFlexScale";

[@bs.send.pipe: t]
external observeFlexScale : (int => unit) => Disposable.t = "observeFlexScale";

[@bs.send.pipe: t]
external onDidActivate : (unit => unit) => Disposable.t = "onDidActivate";

[@bs.send.pipe: t]
external onWillDestroy : (unit => unit) => Disposable.t = "onWillDestroy";

[@bs.send.pipe: t]
external onDidDestroy : (unit => unit) => Disposable.t = "onDidDestroy";

[@bs.send.pipe: t]
external onDidChangeActive : (bool => unit) => Disposable.t =
  "onDidChangeActive";

[@bs.send.pipe: t]
external observeActive : (bool => unit) => Disposable.t = "observeActive";

type paneItemEvent = {
  .
  "item": paneItem,
  "index": int,
};

type paneItemMoveEvent = {
  .
  "item": paneItem,
  "oldIndex": int,
  "newIndex": int,
};

[@bs.send.pipe: t]
external onDidAddItem : (paneItemEvent => unit) => Disposable.t =
  "onDidRemoveItem";

[@bs.send.pipe: t]
external onDidRemoveItem : (paneItemEvent => unit) => Disposable.t =
  "onDidRemoveItem";

[@bs.send.pipe: t]
external onWillRemoveItem : (paneItemEvent => unit) => Disposable.t =
  "onWillRemoveItem";

[@bs.send.pipe: t]
external onDidMoveItem : (paneItemMoveEvent => unit) => Disposable.t =
  "onDidMoveItem";

[@bs.send.pipe: t]
external observeItems : (paneItem => unit) => Disposable.t = "observeItems";

[@bs.send.pipe: t]
external onDidChangeActiveItem : (paneItem => unit) => Disposable.t =
  "onDidChangeActiveItem";

[@bs.send.pipe: t]
external onChooseNextMRUItem : (paneItem => unit) => Disposable.t =
  "onChooseNextMRUItem";

[@bs.send.pipe: t]
external onChooseLastMRUItem : (paneItem => unit) => Disposable.t =
  "onChooseLastMRUItem";

[@bs.send.pipe: t]
external onDoneChoosingMRUItem : (unit => unit) => Disposable.t =
  "onDoneChoosingMRUItem";

[@bs.send.pipe: t]
external observeActiveItem : (paneItem => unit) => Disposable.t =
  "observeActiveItem";

[@bs.send.pipe: t]
external onWillDestroyItem : (paneItemEvent => unit) => Disposable.t =
  "onWillDestroyItem";

/* Items */
[@bs.send.pipe: t]
external destroyItem : (TextEditor.t, ~force: bool=?) => Js.Promise.t(bool) =
  "destroyItem";

[@bs.send.pipe: t]
external activateItem : (TextEditor.t, ~pending: bool=?) => unit =
  "activateItem";
