open Atom__Type;

include Selection;

/* Managing the selection range */
[@bs.send.pipe: t] external getBufferRange : Range.t = "";

[@bs.send.pipe: t] external setBufferRange : Range.t => unit = "";

[@bs.send.pipe: t]
external setBufferRange' :
  (
    Range.t,
    {
      .
      "preserveFolds": bool,
      "autoscroll": bool,
    }
  ) =>
  unit =
  "setBufferRange";

/* Modifying the selected range */
[@bs.send.pipe: t] external clear : unit = "";

[@bs.send.pipe: t] external clear' : Js.t({.}) => unit = "clear";
