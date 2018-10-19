type compositeDisposable;

type cursor;

type disposable;

type panel;

type textEditor;

type view;

module CompositeDisposable = {
  type t = compositeDisposable;
  [@bs.module "atom"] [@bs.new]
  external make : unit => t = "CompositeDisposable";
  [@bs.send] external add : (t, disposable) => unit = "";
  [@bs.send] external destroy : t => unit = "";
};

/* CommandRegistry */
module Commands = {
  [@bs.val] [@bs.scope ("atom", "commands")]
  external add : (string, Js.t({..})) => disposable = "add";
  [@bs.val] [@bs.scope ("atom", "commands")]
  external addToElement :
    (Dom.element, string, Dom.event => unit) => disposable =
    "add";
};

module Cursor = {
  type t = cursor;
  [@bs.send] external getScreenRow : unit => int = "getScreenRow";
  [@bs.send] external moveUp : unit => unit = "moveUp";
  [@bs.send] external moveUpBy : int => unit = "moveUpBy";
  [@bs.send] external moveDown : unit => unit = "moveDown";
  [@bs.send] external moveDownBy : int => unit = "moveDownBy";
  [@bs.send] external moveLeft : unit => unit = "moveLeft";
  [@bs.send] external moveLeftBy : int => unit = "moveLeftBy";
  [@bs.send] external moveRight : unit => unit = "moveRight";
  [@bs.send] external moveRightBy : int => unit = "moveRightBy";
};

module Panel = {
  type t = panel;
  [@bs.send] external isVisible : unit => bool = "isVisible";
  [@bs.send] external hide : unit => unit = "hide";
  [@bs.send] external show : unit => unit = "show";
  [@bs.send] external destroy : unit => unit = "destroy";
};

module TextEditor = {
  type t = textEditor;
  [@bs.send] external getCursors : unit => array(cursor) = "getCursors";
  [@bs.send] external isMini : unit => bool = "isMini";
  /* extension */
  [@bs.val] [@bs.scope ("atom", "views")]
  external getView : t => Dom.element = "getView";
};

/* ViewRegistry */
module Views = {
  [@bs.val] [@bs.scope ("atom", "views")]
  external getView : 'a => Dom.element = "getView";
};

module Workspace = {
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external addModalPanel : Js.t({..}) => panel = "addModalPanel";
  [@bs.val] [@bs.scope ("atom", "workspace")]
  external observeTextEditors : (textEditor => unit) => disposable =
    "observeTextEditors";
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
