open Atom__Type;

/* Config */
module Config = {
  [@bs.val] [@bs.scope ("atom", "config")]
  external get : string => 'a = "get";
  [@bs.val] [@bs.scope ("atom", "config")]
  external set : (string, string) => unit = "set";
};

/* CommandRegistry */
module Commands = {
  /* Registering One Command */
  [@bs.val] [@bs.scope ("atom", "commands")]
  external add :
    (
      [@bs.unwrap] [ | `CSSSelector(string) | `HtmlElement(Dom.htmlElement)],
      string,
      Dom.event => unit
    ) =>
    Disposable.t =
    "add";
  /* Registering Multiple Command */
  [@bs.val] [@bs.scope ("atom", "commands")]
  external addMany :
    (
      [@bs.unwrap] [ | `CSSSelector(string) | `HtmlElement(Dom.htmlElement)],
      Js.t({..})
    ) =>
    Disposable.t =
    "add";
  [@bs.val] [@bs.scope ("atom", "commands")]
  external addToElement :
    (Dom.htmlElement, string, Dom.event => unit) => Disposable.t =
    "add";
};

/* ViewRegistry */
module Views = {
  [@bs.val] [@bs.scope ("atom", "views")]
  external getView : 'a => Dom.htmlElement = "getView";
};

/* GrammarRegistry */
module Grammar = {
  [@bs.val] [@bs.scope ("atom", "grammars")]
  external grammarForScopeName : string => grammar = "grammarForScopeName";
};

/* WorkspaceCenter */
module Workspace = {
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external observeTextEditors : (TextEditor.t => unit) => Disposable.t =
    "observeTextEditors";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external observeActiveTextEditor : (TextEditor.t => unit) => Disposable.t =
    "observeActiveTextEditor";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external getActivePane : unit => Pane.pane = "getActivePane";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external getActivePaneItem : unit => Pane.paneItem = "getActivePaneItem";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external paneForItem : TextEditor.t => Pane.t = "paneForItem";
  /* Panels */
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external addModalPanel : Js.t({..}) => panel = "addModalPanel";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external addRightPanel : Js.t({..}) => panel = "addRightPanel";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external addBottomPanel : Js.t({..}) => panel = "addBottomPanel";
  /* Opening */
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external open_ : Js.t({..}) => Js.Promise.t(TextEditor.t) = "open";
  /* Pane Items */
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external getActiveTextEditor : unit => option(TextEditor.t) = "";
};

/* TooltipManager */
module Tooltips = {
  [@bs.val] [@bs.scope ("atom", "tooltips")]
  external add : (Dom.htmlElement, Js.t({..})) => Disposable.t = "add";
  [@bs.val] [@bs.scope ("atom", "tooltips")]
  external findTooltips : Dom.htmlElement => array(tooltip) = "findTooltips";
};
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
