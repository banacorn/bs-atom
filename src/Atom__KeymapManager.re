open Atom__Type;

/*************************************************************************************************************
  Class Methods
 ************************************************************************************************************/

/* buildKeydownEvent */
[@bs.val] [@bs.scope ("atom", "keymaps", "constructor")]
external buildKeydownEvent: string => Dom.keyboardEvent = "buildKeydownEvent";

[@bs.val] [@bs.scope ("atom", "keymaps", "constructor")]
external buildKeydownEvent_:
  (
    string,
    {
      .
      "ctrl": bool,
      "alt": bool,
      "shift": bool,
      "cmd": bool,
      "which": int,
      "target": Dom.htmlElement,
    }
  ) =>
  Dom.keyboardEvent =
  "buildKeydownEvent";

/*************************************************************************************************************
  Construction and Destruction
 ************************************************************************************************************/

type t;

[@bs.module "atom"] [@bs.new]
external make: {. "defaultTarget": Dom.element} => t = "KeymapManager";

[@bs.val] [@bs.scope ("atom", "keymaps")]
external clear: unit => unit = "clear";

[@bs.val] [@bs.scope ("atom", "keymaps")]
external destroy: unit => unit = "destroy";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidMatchBinding */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external onDidMatchBinding:
  (
    {
      .
      "keystrokes": string,
      "binding": KeyBinding.t,
      "keyboardEventTarget": Dom.element,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidMatchBinding";

/* onDidPartiallyMatchBindings */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external onDidPartiallyMatchBindings:
  (
    {
      .
      "keystrokes": string,
      "partiallyMatchedBindings": array(KeyBinding.t),
      "keyboardEventTarget": Dom.element,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidPartiallyMatchBindings";

/* onDidFailToMatchBinding */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external onDidFailToMatchBinding:
  (
    {
      .
      "keystrokes": string,
      "keyboardEventTarget": Dom.element,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidFailToMatchBinding";

/* onDidFailToReadFile */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external onDidFailToReadFile:
  (
    {
      .
      "message": string,
      "stack": string,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidFailToReadFile";

/*************************************************************************************************************
  Adding and Removing Bindings
 ************************************************************************************************************/

/* add */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external add: (string, Js.t({.}), int) => unit = "add";

/* build */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external build: (string, Js.t({.}), int) => array(KeyBinding.t) = "build";

/* getKeybindings */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external getKeyBindings: unit => array(KeyBinding.t) = "getKeyBindings";

/* findKeybindings */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external findKeyBindings:
  {
    .
    "keystrokes": string,
    "command": string,
    "target": Dom.element,
  } =>
  array(KeyBinding.t) =
  "findKeyBindings";

/*************************************************************************************************************
  Managing Keymap Files
 ************************************************************************************************************/

/* loadKeymap */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external loadKeymap:
  (
    string
  ) =>
  unit =
  "loadKeymap";
[@bs.val] [@bs.scope ("atom", "keymaps")]
external loadKeymap_:
  (
    string,
    {
      .
      "watch": bool,
      "prioroty": int,
    }
  ) =>
  unit =
  "loadKeymap";

/* watchKeymap */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external watchKeymap: (string, {. "prioroty": int}) => unit = "watchKeymap";

/*************************************************************************************************************
  Managing Keyboard Events
 ************************************************************************************************************/

/* handleKeyboardEvent */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external handleKeyboardEvent: Dom.keyboardEvent => unit =
  "handleKeyboardEvent";

/* keystrokeForKeyboardEvent */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external keystrokeForKeyboardEvent: Dom.keyboardEvent => string =
  "keystrokeForKeyboardEvent";

/* addKeystrokeResolver */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external addKeystrokeResolver:
  ((string, Dom.keyboardEvent, string, Js.t({.})) => string) => Disposable.t =
  "addKeystrokeResolver";

/* getPartialMatchTimeout */
[@bs.val] [@bs.scope ("atom", "keymaps")]
external getPartialMatchTimeout: int => int = "getPartialMatchTimeout";
