open Atom__Type;

include Gutter;

/*************************************************************************************************************
  Gutter Destruction
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
  Visibility
 ************************************************************************************************************/

/* hide */
[@bs.send.pipe: t] external hide: unit = "hide";

/* show */
[@bs.send.pipe: t] external show: unit = "show";

/* isVisible */
[@bs.send.pipe: t] external isVisible: bool = "isVisible";

/* decorateMarker */
[@bs.send.pipe: t]
external decorateMarker: (DisplayMarker.t, {. "type": string}) => Decoration.t =
  "decorateMarker";
