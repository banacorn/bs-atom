/*************************************************************************************************************
  Atom Environment
 ************************************************************************************************************/

/* https://flight-manual.atom.io/api/v1.39.1/AtomEnvironment/#instance-tooltips */

module Clipboard = Atom__Clipboard;
module ContextMenu = Atom__ContextMenuManager;
module Deserializers = Atom__Deserializers;
module Views = Atom__ViewRegistry;
module Notifications = Atom__NotificationManager;
module Config = Atom__Config;
module Keymaps = Atom__KeymapManager;
module Tooltips = Atom__TooltipManager;
module Commands = Atom__CommandRegistry;
module Grammars = Atom__GrammarRegistry;
module Styles = Atom__StyleManager;
module Packages = Atom__PackageManager;
module Themes = Atom__ThemeManager;
module Menu = Atom__MenuManager;
module Project = Atom__Project;
module Workspace = Atom__Workspace;
module History = Atom__HistoryManager;

/* add */
[@bs.val] [@bs.scope "atom"] external workspace: Workspace.t = "workspace";

/*************************************************************************************************************
  Classes
 ************************************************************************************************************/

module BufferedNodeProcess = Atom__BufferedNodeProcess;
module BufferedProcess = Atom__BufferedProcess;
module Color = Atom__Color;
module CompositeDisposable = Atom__CompositeDisposable;
module Decoration = Atom__Decoration;

module ScopeDescriptor = Atom__ScopeDescriptor;
module Notification = Atom__Notification;
module Package = Atom__Package;

module Disposable = Atom__Disposable;

module Cursor = Atom__Cursor;

module Environment = Atom__Environment;

module LanguageMode = Atom__LanguageMode;

module Pane = Atom__Pane;

module Panel = Atom__Panel;

module TextEditor = Atom__TextEditor;

module TextBuffer = Atom__TextBuffer;

module TreeSitter = Atom__TreeSitter;

module Selection = Atom__Selection;

module Point = Atom__Point;

module DisplayMarker = Atom__DisplayMarker;

module Range = Atom__Range;

module Type = Atom__Type;
