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

module KeymapManager = {
  type keybinding;
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

module ScopeDescriptor = {
  type t;
};

module Selection = {
  type t;
};

module StyleManager = {
  type t;
};

module Task = {
  type t;
};

module TextBuffer = {
  type t;
};

// module TreeSitter = {
//   [@bs.deriving abstract]
//   type syntaxNode = {
//     children: array(syntaxNode),
//     namedChildren: array(syntaxNode),
//     range: Range.t,
//     startIndex: int,
//     endIndex: int,
//     text: string,
//     [@bs.as "type"]
//     type_: string,
//   };
//   [@bs.deriving abstract]
//   type tree = {rootNode: syntaxNode};
// };
// module LanguageMode = {
//   type t = {tree: TreeSitter.tree};
// };

module TextEditor = {
  type t;
};

module ThemeManager = {
  type theme;
  type t;
};

module TooltipManager = {
  type tooltip;
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
