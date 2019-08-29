open Atom__Type;

include Dock;

/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

/* activate */
[@bs.send.pipe: t] external activate: unit = "activate";

/* show */
[@bs.send.pipe: t] external show: unit = "show";

/* hide */
[@bs.send.pipe: t] external hide: unit = "hide";

/* toggle */
[@bs.send.pipe: t] external toggle: unit = "toggle";

/* isVisible */
[@bs.send.pipe: t] external isVisible: bool = "isVisible";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChangeVisible */
[@bs.send.pipe: t]
external onDidChangeVisible: (bool => unit) => Disposable.t =
  "onDidChangeVisible";

/* observeVisible */
[@bs.send.pipe: t]
external observeVisible: (bool => unit) => Disposable.t = "observeVisible";

/* observePaneItems */
[@bs.send.pipe: t]
external observePaneItems: (Workspace.item => unit) => Disposable.t =
  "observePaneItems";

/* onDidChangeActivePaneItem */
[@bs.send.pipe: t]
external onDidChangeActivePaneItem: (Workspace.item => unit) => Disposable.t =
  "onDidChangeActivePaneItem";

/* onDidStopChangingActivePaneItem */
[@bs.send.pipe: t]
external onDidStopChangingActivePaneItem:
  (Workspace.item => unit) => Disposable.t =
  "onDidStopChangingActivePaneItem";

/* observeActivePaneItem */
[@bs.send.pipe: t]
external observeActivePaneItem: (Workspace.item => unit) => Disposable.t =
  "observeActivePaneItem";

/* onDidAddPane */
[@bs.send.pipe: t]
external onDidAddPane: ({. "pane": Pane.t} => unit) => Disposable.t =
  "onDidAddPane";

/* onWillDestroyPane */
[@bs.send.pipe: t]
external onWillDestroyPane: ({. "pane": Pane.t} => unit) => Disposable.t =
  "onWillDestroyPane";

/* onDidDestroyPane */
[@bs.send.pipe: t]
external onDidDestroyPane: ({. "pane": Pane.t} => unit) => Disposable.t =
  "onDidDestroyPane";

/* observePanes */
[@bs.send.pipe: t]
external observePanes: (Pane.t => unit) => Disposable.t = "observePanes";

/* onDidChangeActivePane */
[@bs.send.pipe: t]
external onDidChangeActivePane: (Pane.t => unit) => Disposable.t =
  "onDidChangeActivePane";

/* observeActivePane */
[@bs.send.pipe: t]
external observeActivePane: (Pane.t => unit) => Disposable.t =
  "observeActivePane";

/* onDidAddPaneItem */
[@bs.send.pipe: t]
external onDidAddPaneItem:
  (
    {
      .
      "item": Workspace.item,
      "pane": Pane.t,
      "index": int,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidAddPaneItem";

/* onWillDestroyPaneItem */
[@bs.send.pipe: t]
external onWillDestroyPaneItem:
  (
    {
      .
      "item": Workspace.item,
      "pane": Pane.t,
      "index": int,
    } =>
    unit
  ) =>
  Disposable.t =
  "onWillDestroyPaneItem";

/* onDidDestroyPaneItem */
[@bs.send.pipe: t]
external onDidDestroyPaneItem:
  (
    {
      .
      "item": Workspace.item,
      "pane": Pane.t,
      "index": int,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidDestroyPaneItem";

/* onDidChangeHovered */
[@bs.send.pipe: t]
external onDidChangeHovered: (bool => unit) => Disposable.t =
  "onDidChangeHovered";

/*************************************************************************************************************
  Pane Items
 ************************************************************************************************************/

/* getPaneItems */
[@bs.send.pipe: t]
external getPaneItems: array(Workspace.item) = "getPaneItems";

/* getActivePaneItem */
[@bs.send.pipe: t]
external getActivePaneItem: Workspace.item = "getActivePaneItem";

/*************************************************************************************************************
  Panes
 ************************************************************************************************************/

/* getPanes */
[@bs.send.pipe: t] external getPanes: array(Pane.t) = "getPanes";

/* getActivePane */
[@bs.send.pipe: t] external getActivePane: Pane.t = "getActivePane";

/* activateNextPane */
[@bs.send.pipe: t] external activateNextPane: unit = "activateNextPane";

/* activatePreviousPane */
[@bs.send.pipe: t]
external activatePreviousPane: unit = "activatePreviousPane";
