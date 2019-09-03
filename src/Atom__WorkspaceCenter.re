open Atom__Type;

include WorkspaceCenter;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* observeTextEditors */
[@bs.send.pipe: t]
external observeTextEditors: (TextEditor.t => unit) => Disposable.t =
  "observeTextEditors";

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

/* onDidChangeActiveTextEditor */
[@bs.send.pipe: t]
external onDidChangeActiveTextEditor:
  (option(TextEditor.t) => unit) => Disposable.t =
  "onDidChangeActiveTextEditor";

/* observeActivePaneItem */
[@bs.send.pipe: t]
external observeActivePaneItem: (Workspace.item => unit) => Disposable.t =
  "observeActivePaneItem";

/* observeActiveTextEditor */
[@bs.send.pipe: t]
external observeActiveTextEditor:
  (option(TextEditor.t) => unit) => Disposable.t =
  "observeActiveTextEditor";

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

/* onDidAddTextEditor */
[@bs.send.pipe: t]
external onDidAddTextEditor:
  (
    {
      .
      "textEditor": TextEditor.t,
      "pane": Pane.t,
      "index": int,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidAddTextEditor";

/*************************************************************************************************************
  Pane Items
 ************************************************************************************************************/

/* getPaneItems */
[@bs.send.pipe: t]
external getPaneItems: unit => array(Workspace.item) = "getPaneItems";

/* getActivePaneItem */
[@bs.send.pipe: t]
external getActivePaneItem: unit => Workspace.item = "getActivePaneItem";

/* getTextEditors */
[@bs.send.pipe: t]
external getTextEditors: unit => array(TextEditor.t) = "getTextEditors";

/* getActiveTextEditor */
[@bs.send.pipe: t]
external getActiveTextEditor: unit => option(TextEditor.t) =
  "getActiveTextEditor";

/*************************************************************************************************************
  Panes
 ************************************************************************************************************/

/* getPanes */
[@bs.send.pipe: t] external getPanes: unit => array(Pane.t) = "getPanes";

/* getActivePane */
[@bs.send.pipe: t] external getActivePane: unit => Pane.t = "getActivePane";

/* activateNextPane */
[@bs.send.pipe: t]
external activateNextPane: unit => bool = "activateNextPane";

/* activatePreviousPane */
[@bs.send.pipe: t]
external activatePreviousPane: unit => bool = "activatePreviousPane";
