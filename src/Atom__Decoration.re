open Atom__Type;

include Decoration;

/*************************************************************************************************************
  Construction and Destruction
 ************************************************************************************************************/

/* destroy */
[@bs.send.pipe: t] external destroy: unit = "destroy";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChangeProperties */
[@bs.send.pipe: t]
external onDidChangeProperties:
  (
    {
      .
      oldProperties: Js.t({.}),
      newProperties: Js.t({.}),
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidChangeProperties";

/* onDidDestroy */
[@bs.send.pipe: t]
external onDidDestroy: (unit => unit) => Disposable.t = "onDidDestroy";

/*************************************************************************************************************
  Decoration Details
 ************************************************************************************************************/

/* getId */
[@bs.send.pipe: t] external getId: int = "getId";

/* getMarker */
[@bs.send.pipe: t] external getMarker: DisplayMarker.t = "getMarker";

/* isType */
[@bs.send.pipe: t] external isType: array(string) => bool = "isType";

/*************************************************************************************************************
  Properties
 ************************************************************************************************************/

/* setProperties */
[@bs.send.pipe: t]
external setProperties: Js.t({.}) => unit = "setProperties";

/* getProperties */
[@bs.send.pipe: t] external getProperties: Js.t({.}) = "getProperties";
