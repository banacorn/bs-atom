open Atom__Type;

include Workspace;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* observeTextEditors */
[@bs.val] [@bs.scope ("atom", "workspace")]
external observeTextEditors: (TextEditor.t => unit) => Disposable.t =
  "observeTextEditors";

/* observePaneItems */
[@bs.val] [@bs.scope ("atom", "workspace")]
external observePaneItems: (item => unit) => Disposable.t = "observePaneItems";

/* onDidChangeActivePaneItem */
[@bs.val] [@bs.scope ("atom", "workspace")]
external onDidChangeActivePaneItem: (item => unit) => Disposable.t =
  "onDidChangeActivePaneItem";

/* onDidStopChangingActivePaneItem */
[@bs.val] [@bs.scope ("atom", "workspace")]
external onDidStopChangingActivePaneItem: (item => unit) => Disposable.t =
  "onDidStopChangingActivePaneItem";

/* onDidChangeActiveTextEditor */
[@bs.val] [@bs.scope ("atom", "workspace")]
external onDidChangeActiveTextEditor:
  (option(TextEditor.t) => unit) => Disposable.t =
  "onDidChangeActiveTextEditor";

/* observeActivePaneItem */
[@bs.val] [@bs.scope ("atom", "workspace")]
external observeActivePaneItem: (item => unit) => Disposable.t =
  "observeActivePaneItem";

/* observeActiveTextEditor */
[@bs.val] [@bs.scope ("atom", "workspace")]
external observeActiveTextEditor:
  (option(TextEditor.t) => unit) => Disposable.t =
  "observeActiveTextEditor";

/* onDidOpen */
[@bs.val] [@bs.scope ("atom", "workspace")]
external onDidOpen:
  (
    {
      .
      "uri": option(string),
      "item": item,
      "pane": Pane.t,
      "index": int,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidOpen";

/* onDidAddPane */
[@bs.val] [@bs.scope ("atom", "workspace")]
external onDidAddPane: ({. "pane": Pane.t} => unit) => Disposable.t =
  "onDidAddPane";

/* onWillDestroyPane */
[@bs.val] [@bs.scope ("atom", "workspace")]
external onWillDestroyPane: ({. "pane": Pane.t} => unit) => Disposable.t =
  "onWillDestroyPane";

/* onDidDestroyPane */
[@bs.val] [@bs.scope ("atom", "workspace")]
external onDidDestroyPane: ({. "pane": Pane.t} => unit) => Disposable.t =
  "onDidDestroyPane";

/* observePanes */
[@bs.val] [@bs.scope ("atom", "workspace")]
external observePanes: (Pane.t => unit) => Disposable.t = "observePanes";

/* onDidChangeActivePane */
[@bs.val] [@bs.scope ("atom", "workspace")]
external onDidChangeActivePane: (Pane.t => unit) => Disposable.t =
  "onDidChangeActivePane";

/* observeActivePane */
[@bs.val] [@bs.scope ("atom", "workspace")]
external observeActivePane: (Pane.t => unit) => Disposable.t =
  "observeActivePane";

/* onDidAddPaneItem */
[@bs.val] [@bs.scope ("atom", "workspace")]
external onDidAddPaneItem:
  (
    {
      .
      "item": item,
      "pane": Pane.t,
      "index": int,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidAddPaneItem";

/* onWillDestroyPaneItem */
[@bs.val] [@bs.scope ("atom", "workspace")]
external onWillDestroyPaneItem:
  (
    {
      .
      "item": item,
      "pane": Pane.t,
      "index": int,
    } =>
    unit
  ) =>
  Disposable.t =
  "onWillDestroyPaneItem";

/* onDidDestroyPaneItem */
[@bs.val] [@bs.scope ("atom", "workspace")]
external onDidDestroyPaneItem:
  (
    {
      .
      "item": item,
      "pane": Pane.t,
      "index": int,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidDestroyPaneItem";

/* onDidAddTextEditor */
[@bs.val] [@bs.scope ("atom", "workspace")]
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
  Opening
 ************************************************************************************************************/

/* open */
type openOptions = {
  .
  "initialLine": int,
  "initialColumn": int,
  "split": string,
  /* "split": [ | `left | `right | `up | `down], */
  "activatePane": bool,
  "activateItem": bool,
  "pending": bool,
  "searchAllPanes": bool,
  "location": option(string),
};

[@bs.val] [@bs.scope ("atom", "workspace")]
external openWithoutOptions: unit => Js.Promise.t(TextEditor.t) = "open";

[@bs.val] [@bs.scope ("atom", "workspace")]
external openWithURI: string => Js.Promise.t(TextEditor.t) = "open";

[@bs.val] [@bs.scope ("atom", "workspace")]
external openWithOptions: openOptions => Js.Promise.t(TextEditor.t) = "open";

[@bs.val] [@bs.scope ("atom", "workspace")]
external open_: (string, openOptions) => Js.Promise.t(TextEditor.t) = "open";

/* hide */
[@bs.val] [@bs.scope ("atom", "workspace")]
external hideItem: item => bool = "hide";

[@bs.val] [@bs.scope ("atom", "workspace")]
external hideWithURI: string => bool = "hide";

/* toggle */
[@bs.val] [@bs.scope ("atom", "workspace")]
external toggleItem: item => Js.Promise.t(unit) = "toggle";

[@bs.val] [@bs.scope ("atom", "workspace")]
external toggleWithURI: string => Js.Promise.t(unit) = "toggle";

/* createItemForURI */
[@bs.val] [@bs.scope ("atom", "workspace")]
external createItemForURI: string => Js.Promise.t(TextEditor.t) =
  "createItemForURI";

/* isTextEditor */
[@bs.val] [@bs.scope ("atom", "workspace")]
external isTextEditor: Js.t({.}) => bool = "isTextEditor";

/* reopenItem */
[@bs.val] [@bs.scope ("atom", "workspace")]
external reopenItem: unit => Js.Promise.t(unit) = "reopenItem";

/* addOpener */
type opener = {
  .
  "element": Dom.element,
  "getTitle": unit => string,
};
[@bs.val] [@bs.scope ("atom", "workspace")]
external addOpener: (string => option(opener)) => Disposable.t = "addOpener";

/* buildTextEditor */
[@bs.val] [@bs.scope ("atom", "workspace")]
external buildTextEditor: unit => TextEditor.t = "buildTextEditor";

/*************************************************************************************************************
  Pane Items
 ************************************************************************************************************/

/* getPaneItems */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getPaneItems: unit => array(item) = "getPaneItems";

/* getActivePaneItem */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getActivePaneItem: unit => item = "getActivePaneItem";

/* getTextEditors */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getTextEditors: unit => array(TextEditor.t) = "getTextEditors";

/* getActiveTextEditor */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getActiveTextEditor: unit => option(TextEditor.t) =
  "getActiveTextEditor";

/*************************************************************************************************************
  Panes
 ************************************************************************************************************/

/* getActivePaneContainer */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getActivePaneContainer_: unit => Js.t({.}) =
  "getActivePaneContainer";

external toDock: Js.t({.}) => Dock.t = "%identity";
external toWorkspaceCenter: Js.t({.}) => WorkspaceCenter.t = "%identity";
let toPaneContainer: Js.t({.}) => paneContainer =
  obj => {
    let isDock: Js.t({.}) => bool = [%raw
      obj => "{return obj.isVisible !== undefined}"
    ];
    if (isDock(obj)) {
      Dock(toDock(obj));
    } else {
      WorkspaceCenter(toWorkspaceCenter(obj));
    };
  };

let getActivePaneContainer: unit => paneContainer =
  () => toPaneContainer(getActivePaneContainer_());

/* getPanes */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getPanes: unit => array(Pane.t) = "getPanes";

/* getActivePane */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getActivePane: unit => Pane.t = "getActivePane";

/* activateNextPane */
[@bs.val] [@bs.scope ("atom", "workspace")]
external activateNextPane: unit => bool = "activateNextPane";

/* activatePreviousPane */
[@bs.val] [@bs.scope ("atom", "workspace")]
external activatePreviousPane: unit => bool = "activatePreviousPane";

/* paneContainerForURI */
[@bs.val] [@bs.scope ("atom", "workspace")]
external paneContainerForURI_: string => option(Js.t({.})) =
  "paneContainerForURI";

let paneContainerForURI: string => option(paneContainer) =
  uri =>
    switch (paneContainerForURI_(uri)) {
    | None => None
    | Some(x) => Some(toPaneContainer(x))
    };

/* paneContainerForItem */
[@bs.val] [@bs.scope ("atom", "workspace")]
external paneContainerForItem_: item => option(Js.t({.})) =
  "paneContainerForItem";

let paneContainerForItem: item => option(paneContainer) =
  item =>
    switch (paneContainerForItem_(item)) {
    | None => None
    | Some(x) => Some(toPaneContainer(x))
    };

/* paneForURI */
[@bs.val] [@bs.scope ("atom", "workspace")]
external paneForURI: string => option(Pane.t) = "paneForURI";

/* paneForItem */
[@bs.val] [@bs.scope ("atom", "workspace")]
external paneForItem: item => option(Pane.t) = "paneForItem";

/*************************************************************************************************************
  Pane Locations
 ************************************************************************************************************/

/* getCenter */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getCenter: unit => WorkspaceCenter.t = "getCenter";

/* getLeftDock */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getLeftDock: unit => Dock.t = "getLeftDock";

/* getRightDock */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getRightDock: unit => Dock.t = "getRightDock";

/* getBottomDock */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getBottomDock: unit => Dock.t = "getBottomDock";

/*************************************************************************************************************
  Panels
 ************************************************************************************************************/

type addPanelOptions = {
  .
  "item": item,
  "visible": bool,
  "priority": int,
};

/* getBottomPanels */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getBottomPanels: unit => array(Panel.t) = "getBottomPanels";

/* addBottomPanel */
[@bs.val] [@bs.scope ("atom", "workspace")]
external addBottomPanel: addPanelOptions => Panel.t = "addBottomPanel";

/* getLeftPanels */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getLeftPanels: unit => array(Panel.t) = "getLeftPanels";

/* addLeftPanel */
[@bs.val] [@bs.scope ("atom", "workspace")]
external addLeftPanel: addPanelOptions => Panel.t = "addLeftPanel";

/* getRightPanels */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getRightPanels: unit => array(Panel.t) = "getRightPanels";

/* addRightPanel */
[@bs.val] [@bs.scope ("atom", "workspace")]
external addRightPanel: addPanelOptions => Panel.t = "addRightPanel";

/* getTopPanels */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getTopPanels: unit => array(Panel.t) = "getTopPanels";

/* addTopPanel */
[@bs.val] [@bs.scope ("atom", "workspace")]
external addTopPanel: addPanelOptions => Panel.t = "addTopPanel";

/* getHeaderPanels */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getHeaderPanels: unit => array(Panel.t) = "getHeaderPanels";

/* addHeaderPanel */
[@bs.val] [@bs.scope ("atom", "workspace")]
external addHeaderPanel: addPanelOptions => Panel.t = "addHeaderPanel";

/* getFooterPanels */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getFooterPanels: unit => array(Panel.t) = "getFooterPanels";

/* addFooterPanel */
[@bs.val] [@bs.scope ("atom", "workspace")]
external addFooterPanel: addPanelOptions => Panel.t = "addFooterPanel";

/* getModalPanels */
[@bs.val] [@bs.scope ("atom", "workspace")]
external getModalPanels: unit => array(Panel.t) = "getModalPanels";

/* addModalPanel */
[@bs.val] [@bs.scope ("atom", "workspace")]
external addModalPanel:
  {
    .
    "item": item,
    "visible": bool,
    "priority": int,
    "autoFocus": bool,
  } =>
  Panel.t =
  "addModalPanel";

/* panelForItem */
[@bs.val] [@bs.scope ("atom", "workspace")]
external panelForItem: item => Js.Nullable.t(Panel.t) = "panelForItem";

/*************************************************************************************************************
  Searching and Replacing
 ************************************************************************************************************/

/* scan */
[@bs.val] [@bs.scope ("atom", "workspace")]
external scan: Js.Re.t => array(Panel.t) = "scan";

[@bs.val] [@bs.scope ("atom", "workspace")]
external scan_:
  (
    Js.Re.t,
    {
      .
      "paths": array(string),
      [@bs.meth] "onPathsSearched": int => unit,
      "leadingContextLineCount": int,
      "trailingContextLineCount": int,
    },
    Js.t({.}) => unit
  ) =>
  Js.Promise.t({. "cancel": unit => unit}) =
  "scan";

/* replace */
[@bs.val] [@bs.scope ("atom", "workspace")]
external replace:
  (
    Js.Re.t,
    string,
    array(string),
    {
      .
      "filePath": string,
      "replacements": array(string),
    } =>
    unit
  ) =>
  Js.Promise.t(unit) =
  "replace";
