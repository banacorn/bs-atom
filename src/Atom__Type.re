module BufferedNodeProcess = {
  type t;
};

module BufferedProcess = {
  type t;
};

module Color = {
  type t;
};

module CompositeDisposable = {
  type t;
};

module Cursor = {
  type t;
};

module Decoration = {
  type t;
};

module Directory = {
  type t;
};

module DisplayMarker = {
  type t;
  type validity = [ | `never | `surround | `overlap | `inside | `touch];
};

module DisplayMarkerLayer = {
  type t;
};

module Disposable = {
  type t;
};

module Dock = {
  type t;
};

module Emitter = {
  type t;
};

module File = {
  type t;
};

module GitRepository = {
  type t;
};

module Grammar = {
  type t;
};

module Gutter = {
  type t;
};

module LayerDecoration = {
  type t;
};

module MarkerLayer = {
  type t;
  type marker;
};

module Notification = {
  type t;
};

module Package = {
  type t;
};

module WorkspaceCenter = {
  type t;
};

module Pane = {
  type t;
};

module Workspace = {
  type t;
  type item;
  type paneContainer =
    | Dock(Dock.t)
    | WorkspaceCenter(WorkspaceCenter.t);
};

module TextEditorMarker = {
  type t;
};

type panel;

module HistoryProject = {
  type historyProject;
  type t = historyProject;
};
module PathWatcher = {
  type pathWatcher;
  type t = pathWatcher;
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

module Selection = {
  type selection;
  type t = selection;
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

module Panel = {
  type panel;
  type t = panel;
};

type tooltip;

type selection;
