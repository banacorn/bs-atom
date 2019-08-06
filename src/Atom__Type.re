type compositeDisposable;

type panel;

/*
 [@bs.deriving abstract]
 type point = {
   row: int,
   column: int,
 };

 [@bs.deriving abstract]
 type range = {
   start: point,
   [@bs.as "end"]
   end_: point,
 }; */

module Directory = {
  type directory;
  type t = directory;
};

module GitRepository = {
  type gitRepository;
  type t = gitRepository;
};

module Cursor = {
  type cursor;
  type t = cursor;
};

module Disposable = {
  type disposable;
  type t = disposable;
};

module CompositeDisposable = {
  type compositeDisposable;
  type t = compositeDisposable;
};

module Point = {
  type point;
  type t = point;
};

module KeyBinding = {
  type keyBinding;
  type t = keyBinding;
};

module Range = {
  type range;
  type t = range;
};

module Grammar = {
  type grammar;
  type t = grammar;
};

module DisplayMarker = {
  type displayMarker;
  type t = displayMarker;
  type validity =
    [@bs.string] [ | `never | `surround | `overlap | `inside | `touch];
};

module Package = {
  type package;
  type t = package;
};
module Selection = {
  type selection;
  type t = selection;
};

module Decoration = {
  type decoration;
  type t = decoration;
};

module TreeSitter = {
  [@bs.deriving abstract]
  type syntaxNode = {
    children: array(syntaxNode),
    namedChildren: array(syntaxNode),
    range: Range.t,
    startIndex: int,
    endIndex: int,
    text: string,
    [@bs.as "type"]
    type_: string,
  };
  [@bs.deriving abstract]
  type tree = {rootNode: syntaxNode};
};

module LanguageMode = {
  [@bs.deriving abstract]
  type languageMode = {tree: TreeSitter.tree};
  type t = languageMode;
};

module Notification = {
  [@bs.deriving abstract]
  type notification;
  type t = notification;
};

module ScopeDescriptor = {
  [@bs.deriving abstract]
  type scopeDescriptor;
  type t = scopeDescriptor;
};

module TextBuffer = {
  [@bs.deriving abstract]
  type textBuffer;
  type t = textBuffer;
};

module TextEditor = {
  [@bs.deriving abstract]
  type textEditor = {languageMode: LanguageMode.t};
  type t = textEditor;
};

module Pane = {
  type item = TextEditor.t;
  type pane;
  type t = pane;
};

type tooltip;

type selection;
