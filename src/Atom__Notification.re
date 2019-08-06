open Atom__Type;

include Notification;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidDismiss */
[@bs.send.pipe: t]
external onDidDismiss: (unit => unit) => Disposable.t = "onDidDismiss";

/* onDidDisplay */
[@bs.send.pipe: t]
external onDidDisplay: (unit => unit) => Disposable.t = "onDidDisplay";

/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

/* getType */
[@bs.send.pipe: t] external getType: string = "getType";

/* getMessage */
[@bs.send.pipe: t] external getMessage: string = "getMessage";

/* dismiss */
[@bs.send.pipe: t] external dismiss: unit = "dismiss";
