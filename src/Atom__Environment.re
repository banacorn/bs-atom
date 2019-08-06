open Atom__Type;

/* GrammarRegistry */
module Grammar = {
  [@bs.val] [@bs.scope ("atom", "grammars")]
  external grammarForScopeName: string => grammar = "";
};

/* PackageManager */
module Packages = {
  /* Enabling and disabling packages */
  [@bs.val] [@bs.scope ("atom", "packages")]
  external enablePackage: string => Js.Nullable.t(Package.t) = "";
  [@bs.val] [@bs.scope ("atom", "packages")]
  external disablePackage: string => Js.Nullable.t(Package.t) = "";
  [@bs.val] [@bs.scope ("atom", "packages")]
  external sPackageDisabled: unit => bool = "";

  /* Accessing active packages */
  [@bs.val] [@bs.scope ("atom", "packages")]
  external getActivePackages: unit => array(Package.t) = "";
  [@bs.val] [@bs.scope ("atom", "packages")]
  external getActivePackage: string => option(Package.t) = "";
  [@bs.val] [@bs.scope ("atom", "packages")]
  external isPackageActive: string => bool = "";
  [@bs.val] [@bs.scope ("atom", "packages")]
  external hasActivatedInitialPackages: unit => bool = "";

  /* Accessing loaded packages */
  [@bs.val] [@bs.scope ("atom", "packages")]
  external getLoadedPackages: unit => array(Package.t) = "";
  [@bs.val] [@bs.scope ("atom", "packages")]
  external getLoadedPackage: string => option(Package.t) = "";
  [@bs.val] [@bs.scope ("atom", "packages")]
  external isPackageLoaded: string => bool = "";
  [@bs.val] [@bs.scope ("atom", "packages")]
  external hasActivatedInitialPackages: unit => bool = "";
  /* Activate/Deactivate packages */
  [@bs.val] [@bs.scope ("atom", "packages")]
  external loadPackages: unit => unit = "";
  [@bs.val] [@bs.scope ("atom", "packages")]
  external loadPackage: string => Package.t = "";
  [@bs.val] [@bs.scope ("atom", "packages")]
  external activatePackage: string => Js.Promise.t(unit) = "";
  [@bs.val] [@bs.scope ("atom", "packages")]
  external deactivatePackage: (string, bool) => Js.Promise.t(unit) = "";
};

/* WorkspaceCenter */
module Workspace = {
  /* Event Subscription */
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external observeTextEditors: (TextEditor.t => unit) => Disposable.t = "";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external observeActiveTextEditor: (TextEditor.t => unit) => Disposable.t =
    "";

  [@bs.val] [@bs.scope ("atom", "workspace")]
  external onDidChangeActivePaneItem: (Pane.item => unit) => Disposable.t = "";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external onDidStopChangingActivePaneItem: (Pane.item => unit) => Disposable.t =
    "";

  [@bs.val] [@bs.scope ("atom", "workspace")]
  external onDidChangeActiveTextEditor:
    (option(TextEditor.t) => unit) => Disposable.t =
    "";

  [@bs.val] [@bs.scope ("atom", "workspace")]
  external observeActivePaneItem: (Pane.item => unit) => Disposable.t = "";

  [@bs.val] [@bs.scope ("atom", "workspace")]
  external observeActiveTextEditor:
    (option(TextEditor.t) => unit) => Disposable.t =
    "";

  [@bs.val] [@bs.scope ("atom", "workspace")]
  external onDidOpen:
    (
      {
        .
        "uri": option(string),
        "item": Pane.item,
        "pane": Pane.t,
        "index": int,
      } =>
      unit
    ) =>
    Disposable.t =
    "";

  [@bs.val] [@bs.scope ("atom", "workspace")]
  external getActivePane: unit => Pane.pane = "";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external getActivePaneItem: unit => Pane.item = "";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external paneForURI: string => option(Pane.t) = "";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external paneForItem: TextEditor.t => option(Pane.t) = "";

  /* Panels */
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external addModalPanel: Js.t({..}) => panel = "";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external addRightPanel: Js.t({..}) => panel = "";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external addBottomPanel: Js.t({..}) => panel = "";
  /* Opening */
  type openingOptions = {
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
  external openWithOnlyURI: string => Js.Promise.t(TextEditor.t) = "open";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external openWithOnlyOptions: openingOptions => Js.Promise.t(TextEditor.t) =
    "open";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external open_: (string, openingOptions) => Js.Promise.t(TextEditor.t) =
    "open";
  type opener = {
    .
    "element": Dom.element,
    "getTitle": unit => string,
  };
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external addOpener: (string => option(opener)) => Disposable.t = "";
  /* Pane Items */
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external getActiveTextEditor: unit => option(TextEditor.t) = "";
};

/* TooltipManager */
module Tooltips = {
  [@bs.val] [@bs.scope ("atom", "tooltips")]
  external add: (Dom.htmlElement, Js.t({..})) => Disposable.t = "add";
  [@bs.val] [@bs.scope ("atom", "tooltips")]
  external findTooltips: Dom.htmlElement => array(tooltip) = "findTooltips";
};

// Atom Details
[@bs.val] [@bs.scope "atom"] external inDevMode: unit => bool = "";
[@bs.val] [@bs.scope "atom"] external inSafeMode: unit => bool = "";
[@bs.val] [@bs.scope "atom"] external inSpecMode: unit => bool = "";
[@bs.val] [@bs.scope "atom"] external getVersion: unit => string = "";
[@bs.val] [@bs.scope "atom"] external getReleaseChannel: unit => string = "";
[@bs.val] [@bs.scope "atom"] external isReleasedVersion: unit => bool = "";
[@bs.val] [@bs.scope "atom"] external getWindowLoadTime: unit => int = "";
[@bs.val] [@bs.scope "atom"]
external getLoadSettings: unit => Js.t({..}) = "";
/* module type HooksSpec = {
     type state;
     type serializedState;

     let activate : option(serializedState) => state;
     let serialize : state => serializedState;
     let deactivate : state => unit;
   };

   module Hooks (Spec: HooksSpec) = {
     type self = {
       mutable state: Spec.state
     };

     let activate = ( (self, serializedState) => {
       self.state = Spec.activate (Js.Undefined.to_opt(serializedState));
     }) [@bs.this];

     let serialize = ((self) => Spec.serialize(self.state)) [@bs.this];

     let deactivate = ((self) => Spec.deactivate(self.state)) [@bs.this];
   }; */
