open Atom__Type;

include Pane;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChangeFlexScale */
[@bs.send.pipe: t]
external onDidChangeFlexScale: (int => unit) => Disposable.t =
  "onDidChangeFlexScale";

/* observeFlexScale */
[@bs.send.pipe: t]
external observeFlexScale: (int => unit) => Disposable.t = "observeFlexScale";

/* onDidActivate */
[@bs.send.pipe: t]
external onDidActivate: (unit => unit) => Disposable.t = "onDidActivate";

/* onWillDestroy */
[@bs.send.pipe: t]
external onWillDestroy: (unit => unit) => Disposable.t = "onWillDestroy";

/* onDidDestroy */
[@bs.send.pipe: t]
external onDidDestroy: (unit => unit) => Disposable.t = "onDidDestroy";

/* onDidChangeActive */
[@bs.send.pipe: t]
external onDidChangeActive: (bool => unit) => Disposable.t =
  "onDidChangeActive";

/* observeActive */
[@bs.send.pipe: t]
external observeActive: (bool => unit) => Disposable.t = "observeActive";

type itemEvent = {
  .
  "item": Workspace.item,
  "index": int,
};

type itemMoveEvent = {
  .
  "item": Workspace.item,
  "oldIndex": int,
  "newIndex": int,
};

/* onDidAddItem */
[@bs.send.pipe: t]
external onDidAddItem: (itemEvent => unit) => Disposable.t = "onDidAddItem";

/* onDidRemoveItem */
[@bs.send.pipe: t]
external onDidRemoveItem: (itemEvent => unit) => Disposable.t =
  "onDidRemoveItem";

/* onWillRemoveItem */
[@bs.send.pipe: t]
external onWillRemoveItem: (itemEvent => unit) => Disposable.t =
  "onWillRemoveItem";

/* onDidMoveItem */
[@bs.send.pipe: t]
external onDidMoveItem: (itemMoveEvent => unit) => Disposable.t =
  "onDidMoveItem";

/* observeItems */
[@bs.send.pipe: t]
external observeItems: (Workspace.item => unit) => Disposable.t =
  "observeItems";

/* onDidChangeActiveItem */
[@bs.send.pipe: t]
external onDidChangeActiveItem: (Workspace.item => unit) => Disposable.t =
  "onDidChangeActiveItem";

/* onChooseNextMRUItem */
[@bs.send.pipe: t]
external onChooseNextMRUItem: (Workspace.item => unit) => Disposable.t =
  "onChooseNextMRUItem";

/* onChooseLastMRUItem */
[@bs.send.pipe: t]
external onChooseLastMRUItem: (Workspace.item => unit) => Disposable.t =
  "onChooseLastMRUItem";

/* onDoneChoosingMRUItem */
[@bs.send.pipe: t]
external onDoneChoosingMRUItem: (unit => unit) => Disposable.t =
  "onDoneChoosingMRUItem";

/* observeActiveItem */
[@bs.send.pipe: t]
external observeActiveItem: (Workspace.item => unit) => Disposable.t =
  "observeActiveItem";

/* onWillDestroyItem */
[@bs.send.pipe: t]
external onWillDestroyItem: (itemEvent => unit) => Disposable.t =
  "onWillDestroyItem";

/*************************************************************************************************************
  Items
 ************************************************************************************************************/

/* getItems */
[@bs.send.pipe: t] external getItems: array(Workspace.item) = "getItems";

/* getActiveItem */
[@bs.send.pipe: t] external getActiveItem: Workspace.item = "getActiveItem";

/* itemAtIndex */
[@bs.send.pipe: t]
external itemAtIndex: int => option(Workspace.item) = "itemAtIndex";

/* activateNextItem */
[@bs.send.pipe: t] external activateNextItem: unit = "activateNextItem";

/* activatePreviousItem */
[@bs.send.pipe: t]
external activatePreviousItem: unit = "activatePreviousItem";

/* moveItemRight */
[@bs.send.pipe: t] external moveItemRight: unit = "moveItemRight";

/* moveItemLeft */
[@bs.send.pipe: t] external moveItemLeft: unit = "moveItemLeft";

/* getActiveItemIndex */
[@bs.send.pipe: t] external getActiveItemIndex: int = "getActiveItemIndex";

/* activateItemAtIndex */
[@bs.send.pipe: t]
external activateItemAtIndex: int => unit = "activateItemAtIndex";

/* activateItem */
[@bs.send.pipe: t]
external activateItem: Workspace.item => unit = "activateItem";

[@bs.send.pipe: t]
external activateItem_: (Workspace.item, {. "pending": bool}) => unit =
  "activateItem";

/* addItem */
[@bs.send.pipe: t]
external addItem: Workspace.item => Workspace.item = "addItem";

[@bs.send.pipe: t]
external addItem_:
  (
    Workspace.item,
    {
      .
      "index": int,
      "pending": bool,
    }
  ) =>
  Workspace.item =
  "addItem";

/* addItems */
[@bs.send.pipe: t]
external addItems: (Workspace.item, array(int)) => array(Workspace.item) =
  "addItems";

/* moveItem */
[@bs.send.pipe: t]
external moveItem: (Workspace.item, int) => unit = "moveItem";

/* moveItemToPane */
[@bs.send.pipe: t]
external moveItemToPane: (Workspace.item, Pane.t, int) => unit =
  "moveItemToPane";

/* destroyActiveItem */
[@bs.send.pipe: t]
external destroyActiveItem: Js.Promise.t(unit) = "destroyActiveItem";

/* destroyItem */
[@bs.send.pipe: t]
external destroyItem: Workspace.item => Js.Promise.t(bool) = "destroyItem";

[@bs.send.pipe: t]
external destroyItem_: (Workspace.item, bool) => Js.Promise.t(bool) =
  "destroyItem";

/* destroyItems */
[@bs.send.pipe: t] external destroyItems: unit = "destroyItems";

/* destroyInactiveItems */
[@bs.send.pipe: t]
external destroyInactiveItems: unit = "destroyInactiveItems";

/* saveActiveItem */
[@bs.send.pipe: t] external saveActiveItem: unit = "saveActiveItem";

/* saveActiveItemAs */
[@bs.send.pipe: t]
external saveActiveItemAs: Js.Promise.t(unit) = "saveActiveItemAs";

[@bs.send.pipe: t]
external saveActiveItemAs_: (unit => unit) => Js.Promise.t(unit) =
  "saveActiveItemAs";

/* saveItem */
[@bs.send.pipe: t]
external saveItem: Workspace.item => Js.Promise.t(unit) = "saveItem";

[@bs.send.pipe: t]
external saveItem_: (Workspace.item, unit => unit) => Js.Promise.t(unit) =
  "saveItem";

/* saveItemAs */
[@bs.send.pipe: t] external saveItemAs: Workspace.item => unit = "saveItemAs";

/*  */
[@bs.send.pipe: t]
external saveItemAs_: (Workspace.item, unit => unit) => unit = "saveItemAs";

/* saveItems */
[@bs.send.pipe: t] external saveItems: unit = "saveItems";

/* itemForURI */
[@bs.send.pipe: t]
external itemForURI: string => option(Workspace.item) = "itemForURI";

/* activateItemForURI */
[@bs.send.pipe: t]
external activateItemForURI: string => bool = "activateItemForURI";

/*************************************************************************************************************
  Lifecycle
 ************************************************************************************************************/

/* isActive */
[@bs.send.pipe: t] external isActive: bool = "isActive";

/* activate */
[@bs.send.pipe: t] external activate: unit = "activate";

/* destroy */
[@bs.send.pipe: t] external destroy: unit = "destroy";

/* isDestroyed */
[@bs.send.pipe: t] external isDestroyed: bool = "isDestroyed";

/*************************************************************************************************************
  Splitting
 ************************************************************************************************************/

type split = {
  .
  "items": array(Workspace.item),
  "copyActiveItem": bool,
};

/* splitLeft */
[@bs.send.pipe: t] external splitLeft: split => Pane.t = "splitLeft";

/* splitRight */
[@bs.send.pipe: t] external splitRight: split => Pane.t = "splitRight";

/* splitUp */
[@bs.send.pipe: t] external splitUp: split => Pane.t = "splitUp";

/* splitDown */
[@bs.send.pipe: t] external splitDown: split => Pane.t = "splitDown";
