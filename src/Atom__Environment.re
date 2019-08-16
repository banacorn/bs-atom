open Atom__Type;

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
