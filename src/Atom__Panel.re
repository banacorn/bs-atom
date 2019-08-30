open Atom__Type;

include Panel;

/*************************************************************************************************************
  Construction and Destruction
 ************************************************************************************************************/

/* destroy */
[@bs.send.pipe: t] external destroy: unit = "destroy";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChangeVisible */
[@bs.send.pipe: t]
external onDidChangeVisible: (Gutter.t => unit) => Disposable.t =
  "onDidChangeVisible";

/* onDidDestroy */
[@bs.send.pipe: t]
external onDidDestroy: (unit => unit) => Disposable.t = "onDidDestroy";

/*************************************************************************************************************
  Panel Details
 ************************************************************************************************************/

/* getItem */
[@bs.send.pipe: t] external getItem: Workspace.item = "getItem";

/* getPriority */
[@bs.send.pipe: t] external getPriority: int = "getPriority";

/* isVisible */
[@bs.send.pipe: t] external isVisible: bool = "isVisible";

/* hide */
[@bs.send.pipe: t] external hide: unit = "hide";

/* show */
[@bs.send.pipe: t] external show: unit = "show";
