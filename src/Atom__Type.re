type compositeDisposable;

type disposable;

type panel;

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
};

module TreeSitter = {
  [@bs.deriving abstract]
  type syntaxNode = {
    children: array(syntaxNode),
    namedChildren: array(syntaxNode),
    range,
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

module TextEditor = {
  [@bs.deriving abstract]
  type textEditor = {languageMode: LanguageMode.t};
  type t = textEditor;
};

module Pane = {
  type paneItem;
  type pane;
  type t = pane;
};

type cursor;

type tooltip;

type grammar;
