module BufferedNodeProcess = {
  type t;
};

module BufferedProcess = {
  type t;
};

module Color = {
  type t;
};

module Commands = {
  type t;
};

module CompositeDisposable = {
  type t;
};

module Config = {
  type t;
};

module ContextMenu = {
  type t;
};

module Cursor = {
  type t;
};

module Decoration = {
  type t;
};

module Deserializers = {
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

module Grammars = {
  type t;
};

module Gutter = {
  type t;
};

module HistoryProject = {
  type t;
};

module Keymaps = {
  type t;
};

module LayerDecoration = {
  type t;
};

module MarkerLayer = {
  type t;
  type marker;
};

module Menu = {
  type t;
};

module Notification = {
  type t;
};

module Notifications = {
  type t;
};

module Package = {
  type t;
};

module Packages = {
  type t;
};

module Pane = {
  type t;
};

module Panel = {
  type t;
};

module PathWatcher = {
  type t;
};

module Point = {
  type t;
};

module Project = {
  type t;
};

module Range = {
  type t;
};

module WorkspaceCenter = {
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

module KeyBinding = {
  type keyBinding;
  type t = keyBinding;
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

type tooltip;

type selection;
