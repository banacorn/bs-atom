open Atom__Type;

include Pane;

/* Pane Item */
[@bs.send.pipe: paneItem] external getTitle : string = "getTitle";

/* Event Subscription */
[@bs.send.pipe: t]
external onDidChangeFlexScale : (int => unit) => disposable =
  "onDidChangeFlexScale";

[@bs.send.pipe: t]
external observeFlexScale : (int => unit) => disposable = "observeFlexScale";

[@bs.send.pipe: t]
external onDidActivate : (unit => unit) => disposable = "onDidActivate";

[@bs.send.pipe: t]
external onWillDestroy : (unit => unit) => disposable = "onWillDestroy";

[@bs.send.pipe: t]
external onDidDestroy : (unit => unit) => disposable = "onDidDestroy";

[@bs.send.pipe: t]
external onDidChangeActive : (bool => unit) => disposable =
  "onDidChangeActive";

[@bs.send.pipe: t]
external observeActive : (bool => unit) => disposable = "observeActive";

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
external onDidAddItem : (paneItemEvent => unit) => disposable =
  "onDidRemoveItem";

[@bs.send.pipe: t]
external onDidRemoveItem : (paneItemEvent => unit) => disposable =
  "onDidRemoveItem";

[@bs.send.pipe: t]
external onWillRemoveItem : (paneItemEvent => unit) => disposable =
  "onWillRemoveItem";

[@bs.send.pipe: t]
external onDidMoveItem : (paneItemMoveEvent => unit) => disposable =
  "onDidMoveItem";

[@bs.send.pipe: t]
external observeItems : (paneItem => unit) => disposable = "observeItems";

[@bs.send.pipe: t]
external onDidChangeActiveItem : (paneItem => unit) => disposable =
  "onDidChangeActiveItem";

[@bs.send.pipe: t]
external onChooseNextMRUItem : (paneItem => unit) => disposable =
  "onChooseNextMRUItem";

[@bs.send.pipe: t]
external onChooseLastMRUItem : (paneItem => unit) => disposable =
  "onChooseLastMRUItem";

[@bs.send.pipe: t]
external onDoneChoosingMRUItem : (unit => unit) => disposable =
  "onDoneChoosingMRUItem";

[@bs.send.pipe: t]
external observeActiveItem : (paneItem => unit) => disposable =
  "observeActiveItem";

[@bs.send.pipe: t]
external onWillDestroyItem : (paneItemEvent => unit) => disposable =
  "onWillDestroyItem";
