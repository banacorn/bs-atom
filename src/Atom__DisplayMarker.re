open Atom__Type;

include DisplayMarker;

/* Construction and Destruction */
[@bs.send.pipe: t] external destroy: unit = "";

[@bs.send.pipe: t] external copy: Js.t({.}) => DisplayMarker.t = "";

/* Event Subscription */
type onDidChangeEvent = {
  .
  "oldHeadBufferPosition": Point.t,
  "newHeadBufferPosition": Point.t,
  "oldTailBufferPosition": Point.t,
  "newTailBufferPosition": Point.t,
  "oldHeadScreenPosition": Point.t,
  "newHeadScreenPosition": Point.t,
  "oldTailScreenPosition": Point.t,
  "newTailScreenPosition": Point.t,
  "wasValid": bool,
  "isValid": bool,
  "hadTail": bool,
  "oldProperties": Js.t({.}),
  "newProperties": Js.t({.}),
  "textChanged": bool,
};

[@bs.send.pipe: t]
external onDidChange: (onDidChangeEvent => unit) => Disposable.t = "";

[@bs.send.pipe: t] external onDidDestroy: (unit => unit) => Disposable.t = "";

/* Managing the marker's range */
[@bs.send.pipe: t] external getBufferRange: Range.t = "";

[@bs.send.pipe: t] external setBufferRange: Range.t => unit = "";
[@bs.send.pipe: t]
external setBufferRange_: (Range.t, {. "reversed": bool}) => unit =
  "setBufferRange";
