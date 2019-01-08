open Atom__Type;

include Decoration;

/* Construction and Destruction */
[@bs.send.pipe: t] external destroy : unit = "";

/* Event Subscription */
[@bs.send.pipe: t]
external onDidChangeProperties :
  (
    {
      .
      oldProperties: Js.t({.}),
      newProperties: Js.t({.}),
    } =>
    unit
  ) =>
  Disposable.t =
  "";

[@bs.send.pipe: t] external onDidDestroy : (unit => unit) => Disposable.t = "";

/* Decoration Details */
[@bs.send.pipe: t] external getId : int = "";

[@bs.send.pipe: t] external getMarker : DisplayMarker.t = "";

[@bs.send.pipe: t] external isType : array(string) => bool = "";

/* Properties */
[@bs.send.pipe: t] external setProperties : Js.t({.}) => unit = "";

[@bs.send.pipe: t] external getProperties : Js.t({.}) = "";
