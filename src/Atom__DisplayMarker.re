open Atom__Type;

include DisplayMarker;

/*************************************************************************************************************
  Construction and Destruction
 ************************************************************************************************************/

/* destroy */
[@bs.send.pipe: t] external destroy: unit = "destroy";

/* copy */
[@bs.send.pipe: t] external copy: DisplayMarker.t = "copy";

[@bs.send.pipe: t] external copy_: Js.t({.}) => DisplayMarker.t = "copy";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChange */
[@bs.send.pipe: t]
external onDidChange:
  (
    {
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
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidChange";

/* onDidDestroy */
[@bs.send.pipe: t]
external onDidDestroy: (unit => unit) => Disposable.t = "onDidDestroy";

/*************************************************************************************************************
  TextEditorMarker Details
 ************************************************************************************************************/

/* isValid */
[@bs.send.pipe: t] external isValid: bool = "isValid";

/* isDestroyed */
[@bs.send.pipe: t] external isDestroyed: bool = "isDestroyed";

/* isReversed */
[@bs.send.pipe: t] external isReversed: bool = "isReversed";

/* isExclusive */
[@bs.send.pipe: t] external isExclusive: bool = "isExclusive";

/* getInvalidationStrategy */
[@bs.send.pipe: t]
external getInvalidationStrategy: string = "getInvalidationStrategy";

/* getProperties */
[@bs.send.pipe: t] external getProperties: Js.t({.}) = "getProperties";

/* setProperties */
[@bs.send.pipe: t]
external setProperties: Js.t({.}) => unit = "setProperties";

type displayMarkerLayerFindMarkersProperties = Js.t({.});

/* matchesProperties */
[@bs.send.pipe: t]
external matchesProperties: displayMarkerLayerFindMarkersProperties => unit =
  "matchesProperties";

/*************************************************************************************************************
  Comparing to other markers
 ************************************************************************************************************/

/* compare */
[@bs.send.pipe: t] external compare: DisplayMarker.t => int = "compare";

/* isEqual */
[@bs.send.pipe: t] external isEqual: DisplayMarker.t => bool = "isEqual";

/*************************************************************************************************************
  Managing the marker's range
 ************************************************************************************************************/

/* getBufferRange */
[@bs.send.pipe: t] external getBufferRange: Range.t = "getBufferRange";

/* getScreenRange */
[@bs.send.pipe: t] external getScreenRange: Range.t = "getScreenRange";

/* setBufferRange */
[@bs.send.pipe: t] external setBufferRange: Range.t => unit = "setBufferRange";

[@bs.send.pipe: t]
external setBufferRange_: (Range.t, {. "reversed": bool}) => unit =
  "setBufferRange";

/* setScreenRange */
[@bs.send.pipe: t] external setScreenRange: Range.t => unit = "setScreenRange";

[@bs.send.pipe: t]
external setScreenRange_:
  (
    Range.t,
    {
      .
      "reversed": bool,
      "clipDirection": string,
    }
  ) =>
  unit =
  "setScreenRange";

/* getStartScreenPosition */
[@bs.send.pipe: t]
external getStartScreenPosition: Point.t = "getStartScreenPosition";

[@bs.send.pipe: t]
external getStartScreenPosition_: {. "clipDirection": string} => Point.t =
  "getStartScreenPosition";

/* getEndScreenPosition */
[@bs.send.pipe: t]
external getEndScreenPosition: Point.t = "getEndScreenPosition";

[@bs.send.pipe: t]
external getEndScreenPosition_: {. "clipDirection": string} => Point.t =
  "getEndScreenPosition";

/* getHeadBufferPosition */
[@bs.send.pipe: t]
external getHeadBufferPosition: Point.t = "getHeadBufferPosition";

/* setHeadBufferPosition */
[@bs.send.pipe: t]
external setHeadBufferPosition: Point.t => unit = "setHeadBufferPosition";

/* getHeadScreenPosition */
[@bs.send.pipe: t]
external getHeadScreenPosition: Point.t = "getHeadScreenPosition";

[@bs.send.pipe: t]
external getHeadScreenPosition_: {. "clipDirection": string} => Point.t =
  "getHeadScreenPosition";

/* setHeadScreenPosition */
[@bs.send.pipe: t]
external setHeadScreenPosition: Point.t => unit = "setHeadScreenPosition";

[@bs.send.pipe: t]
external setHeadScreenPosition_:
  (Point.t, {. "clipDirection": string}) => unit =
  "setHeadScreenPosition";

/* getTailBufferPosition */
[@bs.send.pipe: t]
external getTailBufferPosition: Point.t = "getTailBufferPosition";

/* setTailBufferPosition */
[@bs.send.pipe: t]
external setTailBufferPosition: Point.t => unit = "setTailBufferPosition";

/* getTailScreenPosition */
[@bs.send.pipe: t]
external getTailScreenPosition: Point.t = "getTailScreenPosition";

[@bs.send.pipe: t]
external getTailScreenPosition_: {. "clipDirection": string} => Point.t =
  "getTailScreenPosition";

/* setTailScreenPosition */
[@bs.send.pipe: t]
external setTailScreenPosition: Point.t => unit = "setTailScreenPosition";

[@bs.send.pipe: t]
external setTailScreenPosition_:
  (Point.t, {. "clipDirection": string}) => unit =
  "setTailScreenPosition";

/* getStartBufferPosition */
[@bs.send.pipe: t]
external getStartBufferPosition: Point.t = "getStartBufferPosition";

/* getEndBufferPosition */
[@bs.send.pipe: t]
external getEndBufferPosition: Point.t = "getEndBufferPosition";

/* hasTail */
[@bs.send.pipe: t] external hasTail: bool = "hasTail";

/* plantTail */
[@bs.send.pipe: t] external plantTail: unit = "plantTail";

/* clearTail */
[@bs.send.pipe: t] external clearTail: unit = "clearTail";
