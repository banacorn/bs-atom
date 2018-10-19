open Type;

/* CommandRegistry */
module Commands = {
  /* Registering One Command */
  [@bs.val] [@bs.scope ("atom", "commands")]
  external add :
    (
      [@bs.unwrap] [ | `CSSSelector(string) | `DOMElement(Dom.element)],
      string,
      (
        ~displayName: string,
        ~description: string,
        ~hiddenInCommandPalette: bool
      ) =>
      unit
    ) =>
    disposable =
    "add";
  /* Registering Multiple Command */
  [@bs.val] [@bs.scope ("atom", "commands")]
  external addMany :
    (
      [@bs.unwrap] [ | `CSSSelector(string) | `DOMElement(Dom.element)],
      Js.t({..})
    ) =>
    disposable =
    "add";
  [@bs.val] [@bs.scope ("atom", "commands")]
  external addToElement :
    (Dom.element, string, Dom.event => unit) => disposable =
    "add";
};

/* ViewRegistry */
module Views = {
  [@bs.val] [@bs.scope ("atom", "views")]
  external getView : 'a => Dom.element = "getView";
};

/* WorkspaceCenter */
module Workspace = {
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external addModalPanel : Js.t({..}) => panel = "addModalPanel";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external observeTextEditors : (textEditor => unit) => disposable =
    "observeTextEditors";
};

/* TooltipManager */
module Tooltips = {
  [@bs.val] [@bs.scope ("atom", "tooltips")]
  external add : (Dom.element, Js.t({..})) => disposable = "add";
  [@bs.val] [@bs.scope ("atom", "tooltips")]
  external findTooltips : Dom.element => array(tooltip) = "findTooltips";
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
