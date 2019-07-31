open Atom__Type;

include Pane;

/* Pane Items */
[@bs.send.pipe: item] external getTitle: string = "";

/* Event Subscription */
[@bs.send.pipe: t]
external onDidChangeFlexScale: (int => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external observeFlexScale: (int => unit) => Disposable.t = "";

[@bs.send.pipe: t] external onDidActivate: (unit => unit) => Disposable.t = "";

[@bs.send.pipe: t] external onWillDestroy: (unit => unit) => Disposable.t = "";

[@bs.send.pipe: t] external onDidDestroy: (unit => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external onDidChangeActive: (bool => unit) => Disposable.t = "";

[@bs.send.pipe: t] external observeActive: (bool => unit) => Disposable.t = "";

type itemEvent = {
  .
  "item": item,
  "index": int,
};

type itemMoveEvent = {
  .
  "item": item,
  "oldIndex": int,
  "newIndex": int,
};

[@bs.send.pipe: t]
external onDidAddItem: (itemEvent => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external onDidRemoveItem: (itemEvent => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external onWillRemoveItem: (itemEvent => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external onDidMoveItem: (itemMoveEvent => unit) => Disposable.t = "";

[@bs.send.pipe: t] external observeItems: (item => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external onDidChangeActiveItem: (item => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external onChooseNextMRUItem: (item => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external onChooseLastMRUItem: (item => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external onDoneChoosingMRUItem: (unit => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external observeActiveItem: (item => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external onWillDestroyItem: (itemEvent => unit) => Disposable.t = "";

/* Items */

[@bs.send.pipe: t] external getItems: array(item) = "";
[@bs.send.pipe: t] external getActiveItem: item = "";
[@bs.send.pipe: t] external itemAtIndex: int => option(item) = "";
[@bs.send.pipe: t] external activateNextItem: unit = "";
[@bs.send.pipe: t] external activatePreviousItem: unit = "";
[@bs.send.pipe: t] external moveItemRight: unit = "";
[@bs.send.pipe: t] external moveItemLeft: unit = "";
[@bs.send.pipe: t] external getActiveItemIndex: int = "";
[@bs.send.pipe: t] external activateItemAtIndex: int => unit = "";
[@bs.send.pipe: t] external activateItem: item => unit = "";
[@bs.send.pipe: t]
external activateItem_: (item, {. "pending": bool}) => unit = "activateItem";
[@bs.send.pipe: t] external addItem: item => item = "";
[@bs.send.pipe: t]
external addItem_:
  (
    item,
    {
      .
      "index": int,
      "pending": bool,
    }
  ) =>
  item =
  "addItem";
[@bs.send.pipe: t] external addItems: (item, array(int)) => array(item) = "";
[@bs.send.pipe: t] external moveItem: (item, int) => unit = "";
[@bs.send.pipe: t] external moveItemToPane: (item, pane, int) => unit = "";
[@bs.send.pipe: t] external destroyActiveItem: Js.Promise.t(unit) = "";
[@bs.send.pipe: t] external destroyItem: item => Js.Promise.t(bool) = "";
[@bs.send.pipe: t] external destroyItem_: (item, bool) => Js.Promise.t(bool) = "destroyItem";
[@bs.send.pipe: t] external destroyItems: unit = "";
[@bs.send.pipe: t] external destroyInactiveItems: unit = "";
[@bs.send.pipe: t] external saveActiveItem: unit = "";
[@bs.send.pipe: t] external saveActiveItemAs: Js.Promise.t(unit) = "";
[@bs.send.pipe: t]
external saveActiveItemAs_: (unit => unit) => Js.Promise.t(unit) =
  "saveActiveItemAs";

[@bs.send.pipe: t] external saveItem: item => Js.Promise.t(unit) = "";
[@bs.send.pipe: t]
external saveItem_: (item, unit => unit) => Js.Promise.t(unit) = "saveItem";

[@bs.send.pipe: t] external saveItemAs: item => unit = "";
[@bs.send.pipe: t]
external saveItemAs_: (item, unit => unit) => unit = "saveItemAs";
[@bs.send.pipe: t] external saveItems: unit = "";
[@bs.send.pipe: t] external itemForURI: string => option(item) = "";
[@bs.send.pipe: t] external activateItemForURI: string => bool = "";

/* Lifecycle */

[@bs.send.pipe: t] external isActive: bool = "";
[@bs.send.pipe: t] external activate: unit = "";
[@bs.send.pipe: t] external destroy: unit = "";
[@bs.send.pipe: t] external isDestroyed: bool = "";
