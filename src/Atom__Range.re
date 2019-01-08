open Atom__Type;

include Range;

[@bs.module "atom"] [@bs.new] external make: (Point.t, Point.t) => t = "Range";

/* Properties */
[@bs.get] external start: t => Point.t = "";

[@bs.get] external end_: t => Point.t = "end";

/* Construction */
[@bs.send.pipe: t]
external fromObject:
  {
    .
    "start": Point.t,
    "end": Point.t,
  } =>
  t =
  "";

[@bs.send.pipe: t] external constructor: (Point.t, Point.t) => t = "";

[@bs.send.pipe: t] external copy: t = "";

[@bs.send.pipe: t] external negate: t = "";

/* Serialization and Deserialization */
[@bs.send.pipe: t] external serialize: Js.t({.}) = "";

[@bs.send.pipe: t] external deserialize: array(Point.t) => t = "";

/* Range Details */
[@bs.send.pipe: t] external isEmpty: bool = "";

[@bs.send.pipe: t] external isSingleLine: bool = "";

[@bs.send.pipe: t] external getRowCount: int = "";

[@bs.send.pipe: t] external getRows: array(int) = "";

/* Operations */
[@bs.send.pipe: t] external freeze: t = "";

[@bs.send.pipe: t] external union: t => t = "";

[@bs.send.pipe: t] external translate: (Point.t, Point.t) => t = "";

[@bs.send.pipe: t] external traverse: Point.t => t = "";

/* Comparison */
[@bs.send.pipe: t] external compare: t => int = "";

[@bs.send.pipe: t] external isEqual: t => bool = "";

[@bs.send.pipe: t] external coversSameRows: t => bool = "";

[@bs.send.pipe: t] external intersectsWith: t => bool = "";

[@bs.send.pipe: t] external containesRange: t => bool = "";

[@bs.send.pipe: t] external containesPoint: Point.t => bool = "";

[@bs.send.pipe: t] external intersectsRow: int => bool = "";

[@bs.send.pipe: t] external intersectsRowRange: (int, int) => bool = "";

/* Conversion */
[@bs.send.pipe: t] external toString: string = "";
