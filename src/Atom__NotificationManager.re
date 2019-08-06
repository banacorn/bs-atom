open Atom__Type;

/*
     Events
 */

/* onDidAddNotification() */
[@bs.val] [@bs.scope ("atom", "notifications")]
external onDidAddNotification: (Notification.t => unit) => Disposable.t =
  "onDidAddNotification";

/* onDidClearNotifications() */
[@bs.val] [@bs.scope ("atom", "notifications")]
external onDidClearNotifications: (unit => unit) => Disposable.t =
  "onDidClearNotifications";

/*
     Adding Notifications
 */

type button =
  | Button(string, option(string), option(unit => unit));

type options;

[@bs.obj]
external mkOptions':
  (
    ~buttons: array(button)=?,
    ~description: string=?,
    ~detail: string=?,
    ~dismissable: bool=?,
    ~icon: string=?,
    unit
  ) =>
  options =
  "";

let mkOptions =
    (~buttons=?, ~description=?, ~detail=?, ~dismissable=?, ~icon="check", ()) =>
  mkOptions'(~buttons?, ~description?, ~detail?, ~dismissable?, ~icon, ());

/* addSuccess() */
[@bs.val] [@bs.scope ("atom", "notifications")]
external addSuccess: (string, options) => Notification.t = "addSuccess";

/* addInfo() */
[@bs.val] [@bs.scope ("atom", "notifications")]
external addInfo: (string, options) => Notification.t = "addInfo";

/* addWarning() */
[@bs.val] [@bs.scope ("atom", "notifications")]
external addWarning: (string, options) => Notification.t = "addWarning";

/* addError() */
[@bs.val] [@bs.scope ("atom", "notifications")]
external addError: (string, options) => Notification.t = "addError";

/* addFatalError() */
[@bs.val] [@bs.scope ("atom", "notifications")]
external addFatalError: (string, options) => Notification.t = "addFatalError";

/*
     Getting Notifications
 */

/* getNotifications() */
[@bs.val] [@bs.scope ("atom", "notifications")]
external getNotifications: unit => array(Notification.t) = "getNotifications";

/*
     Managing Notifications
 */

/* clear() */
[@bs.val] [@bs.scope ("atom", "notifications")]
external clear: unit => unit = "clear";
