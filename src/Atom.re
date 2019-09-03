module Type = Atom__Type;

/*************************************************************************************************************
  Atom Environment
 ************************************************************************************************************/

/* https://flight-manual.atom.io/api/v1.40.1/AtomEnvironment/#instance-tooltips */

// atom.clipboard
module Clipboard = Atom__Clipboard;
[@bs.val] [@bs.scope "atom"] external clipboard: Clipboard.t = "clipboard";

// atom.deserializers
module Deserializers = Atom__Deserializers;
[@bs.val] [@bs.scope "atom"]
external deserializers: Deserializers.t = "deserializers";

// atom.views
module Views = Atom__ViewRegistry;
[@bs.val] [@bs.scope "atom"] external views: Views.t = "views";

// atom.notifications
module Notifications = Atom__NotificationManager;
[@bs.val] [@bs.scope "atom"]
external notifications: Notifications.t = "notifications";

// atom.config
module Config = Atom__Config;
[@bs.val] [@bs.scope "atom"] external config: Config.t = "config";

// atom.keymaps
module Keymaps = Atom__KeymapManager;
[@bs.val] [@bs.scope "atom"] external keymaps: Keymaps.t = "keymaps";

// atom.tooltips
module Tooltips = Atom__TooltipManager;
[@bs.val] [@bs.scope "atom"] external tooltips: Tooltips.t = "tooltips";

// atom.commands
module Commands = Atom__CommandRegistry;
[@bs.val] [@bs.scope "atom"] external commands: Commands.t = "commands";

// atom.grammars
module Grammars = Atom__GrammarRegistry;
[@bs.val] [@bs.scope "atom"] external grammars: Grammars.t = "grammars";

// atom.styles
module Styles = Atom__StyleManager;
[@bs.val] [@bs.scope "atom"] external styles: Styles.t = "styles";

// atom.packages
module Packages = Atom__PackageManager;
[@bs.val] [@bs.scope "atom"] external packages: Packages.t = "packages";

// atom.themes
module Themes = Atom__ThemeManager;
[@bs.val] [@bs.scope "atom"] external themes: Themes.t = "themes";

// atom.menu
module Menu = Atom__MenuManager;
[@bs.val] [@bs.scope "atom"] external menu: Menu.t = "menu";

// atom.contextMenu
module ContextMenu = Atom__ContextMenuManager;
[@bs.val] [@bs.scope "atom"]
external contextMenu: ContextMenu.t = "contextMenu";

// atom.project
module Project = Atom__Project;
[@bs.val] [@bs.scope "atom"] external project: Project.t = "project";

// atom.textEditors
module TextEditors = Atom__TextEditorRegistry;
[@bs.val] [@bs.scope "atom"]
external textEditors: TextEditors.t = "textEditors";

// atom.workspace
module Workspace = Atom__Workspace;
[@bs.val] [@bs.scope "atom"] external workspace: Workspace.t = "workspace";

// atom.history
module History = Atom__HistoryManager;
[@bs.val] [@bs.scope "atom"] external history: History.t = "history";

/*************************************************************************************************************
  Classes
 ************************************************************************************************************/

module BufferedNodeProcess = Atom__BufferedNodeProcess;
module BufferedProcess = Atom__BufferedProcess;
module Color = Atom__Color;
module CompositeDisposable = Atom__CompositeDisposable;
module Cursor = Atom__Cursor;
module Decoration = Atom__Decoration;
module Directory = Atom__Directory;
module DisplayMarker = Atom__DisplayMarker;
module DisplayMarkerLayer = Atom__DisplayMarkerLayer;
module Disposable = Atom__Disposable;
module Dock = Atom__Dock;
module Emitter = Atom__Emitter;
module File = Atom__File;
module GitRepository = Atom__GitRepository;
module Grammar = Atom__Grammar;
module Gutter = Atom__Gutter;
module LayerDecoration = Atom__LayerDecoration;
module MarkerLayer = Atom__MarkerLayer;
module Notification = Atom__Notification;
module Package = Atom__Package;
module Pane = Atom__Pane;
module Panel = Atom__Panel;
module PathWatcher = Atom__PathWatcher;
module Point = Atom__Point;
module Range = Atom__Range;
module ScopeDescriptor = Atom__ScopeDescriptor;
module Selection = Atom__Selection;
module Task = Atom__Task;
module TextBuffer = Atom__TextBuffer;
module TextEditor = Atom__TextEditor;
module WorkspaceCenter = Atom__WorkspaceCenter;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidBeep */
[@bs.val] [@bs.scope "atom"]
external onDidBeep: (unit => unit) => Disposable.t = "onDidBeep";

/* onWillThrowError */
[@bs.val] [@bs.scope "atom"]
external onWillThrowError:
  (
    {
      .
      "originalError": Js.t({.}),
      "message": string,
      "url": string,
      "line": int,
      "column": int,
      "preventDefault": unit => unit,
    } =>
    unit
  ) =>
  Disposable.t =
  "onWillThrowError";

/* onDidThrowError */
[@bs.val] [@bs.scope "atom"]
external onDidThrowError:
  (
    {
      .
      "originalError": Js.t({.}),
      "message": string,
      "url": string,
      "line": int,
      "column": int,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidThrowError";

/*************************************************************************************************************
  Atom Details
 ************************************************************************************************************/

/* inDevMode */
[@bs.val] [@bs.scope "atom"] external inDevMode: unit => bool = "inDevMode";

/* inSafeMode */
[@bs.val] [@bs.scope "atom"] external inSafeMode: unit => bool = "inSafeMode";

/* inSpecMode */
[@bs.val] [@bs.scope "atom"] external inSpecMode: unit => bool = "inSpecMode";

/* getAppName */
[@bs.val] [@bs.scope "atom"]
external getAppName: unit => string = "getAppName";

/* getVersion */
[@bs.val] [@bs.scope "atom"]
external getVersion: unit => string = "getVersion";

/* getReleaseChannel */
[@bs.val] [@bs.scope "atom"]
external getReleaseChannel: unit => string = "getReleaseChannel";

/* isReleasedVersion */
[@bs.val] [@bs.scope "atom"]
external isReleasedVersion: unit => bool = "isReleasedVersion";

/* getWindowLoadTime */
[@bs.val] [@bs.scope "atom"]
external getWindowLoadTime: unit => Js.Nullable.t(int) = "getWindowLoadTime";

/* getStartupMarkers */
[@bs.val] [@bs.scope "atom"]
external getStartupMarkers:
  unit =>
  array({
    .
    "label": string,
    "time": int,
  }) =
  "getStartupMarkers";

/* getLoadSettings */
[@bs.val] [@bs.scope "atom"]
external getLoadSettings: unit => Js.t({..}) = "getLoadSettings";

/*************************************************************************************************************
  Managing The Atom Window
 ************************************************************************************************************/

/* open */
[@bs.val] [@bs.scope "atom"]
external open_:
  {
    .
    "pathsToOpen": array(string),
    "newWindow": bool,
    "devMode": bool,
    "safeMode": bool,
  } =>
  unit =
  "open";

/* close */
[@bs.val] [@bs.scope "atom"] external close: unit => unit = "close";

/* getSize */
[@bs.val] [@bs.scope "atom"]
external getSize:
  unit =>
  {
    .
    "width": int,
    "height": int,
  } =
  "getSize";

/* setSize */
[@bs.val] [@bs.scope "atom"] external setSize: (int, int) => unit = "setSize";

/* getPosition */
[@bs.val] [@bs.scope "atom"]
external getPosition:
  unit =>
  {
    .
    "x": int,
    "y": int,
  } =
  "getPosition";

/* setPosition */
[@bs.val] [@bs.scope "atom"]
external setPosition: (int, int) => unit = "setPosition";

/* pickFolder */
[@bs.val] [@bs.scope "atom"]
external pickFolder: (Js.Nullable.t(array(string)) => unit) => unit =
  "pickFolder";

/* getCurrentWindow */
[@bs.val] [@bs.scope "atom"]
external getCurrentWindow: unit => unit = "getCurrentWindow";

/* center */
[@bs.val] [@bs.scope "atom"] external center: unit => unit = "center";

/* focus */
[@bs.val] [@bs.scope "atom"] external focus: unit => unit = "focus";

/* show */
[@bs.val] [@bs.scope "atom"] external show: unit => unit = "show";

/* hide */
[@bs.val] [@bs.scope "atom"] external hide: unit => unit = "hide";

/* reload */
[@bs.val] [@bs.scope "atom"] external reload: unit => unit = "reload";

/* restartApplication */
[@bs.val] [@bs.scope "atom"]
external restartApplication: unit => unit = "restartApplication";

/* isMaximized */
[@bs.val] [@bs.scope "atom"]
external isMaximized: unit => bool = "isMaximized";

/* isFullScreen */
[@bs.val] [@bs.scope "atom"]
external isFullScreen: unit => bool = "isFullScreen";

/* setFullScreen */
[@bs.val] [@bs.scope "atom"]
external setFullScreen: unit => unit = "setFullScreen";

/* toggleFullScreen */
[@bs.val] [@bs.scope "atom"]
external toggleFullScreen: unit => unit = "toggleFullScreen";

/*************************************************************************************************************
  Messaging the User
 ************************************************************************************************************/

/* beep */
[@bs.val] [@bs.scope "atom"] external beep: unit => unit = "beep";

/* confirm */
[@bs.val] [@bs.scope "atom"]
external confirm:
  (
    {
      .
      "message": string,
      "detailedMessage": string,
      "buttons": array(string),
    },
    int => unit
  ) =>
  option(int) =
  "confirm";

[@bs.val] [@bs.scope "atom"]
external confirm_:
  (
    {
      .
      "message": string,
      "detailedMessage": string,
      "buttons": Js.t({.}),
    },
    int => unit
  ) =>
  option(int) =
  "confirm";

/*************************************************************************************************************
  Managing the Dev Tools
 ************************************************************************************************************/

/* openDevTools */
[@bs.val] [@bs.scope "atom"]
external openDevTools: unit => Js.Promise.t(unit) = "openDevTools";

/* toggleDevTools */
[@bs.val] [@bs.scope "atom"]
external toggleDevTools: unit => Js.Promise.t(unit) = "toggleDevTools";

/* executeJavaScriptInDevTools */
[@bs.val] [@bs.scope "atom"]
external executeJavaScriptInDevTools: unit => unit =
  "executeJavaScriptInDevTools";
