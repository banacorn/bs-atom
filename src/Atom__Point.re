open Atom__Type;

include Point;

[@bs.new] external make : (int, int) => t = "Point";

/* Properties */
[@bs.get] external row : t => int = "";

[@bs.get] external column : t => int = "";

/* Construction */
[@bs.send.pipe: t]
external fromObject :
  {
    .
    "row": int,
    "column": int,
  } =>
  t =
  "";

[@bs.send.pipe: t] external fromArray : array(int) => t = "fromObject";

[@bs.send.pipe: t] external constructor : (int, int) => t = "";

[@bs.send.pipe: t] external copy : t = "";

[@bs.send.pipe: t] external negate : t = "";

/* Comparison */
[@bs.send.pipe: t] external min : (t, t) => t = "";

[@bs.send.pipe: t] external compare : t => int = "";

[@bs.send.pipe: t] external isEqual : t => bool = "";

[@bs.send.pipe: t] external isLessThan : t => bool = "";

[@bs.send.pipe: t] external isLessThanOrEqual : t => bool = "";

[@bs.send.pipe: t] external isGreaterThan : t => bool = "";

[@bs.send.pipe: t] external isGreaterThanOrEqual : t => bool = "";

/* Operations */
[@bs.send.pipe: t] external freeze : t = "";

[@bs.send.pipe: t] external translate : t => t = "";

[@bs.send.pipe: t] external traverse : t => t = "";

/* Conversion */
[@bs.send.pipe: t] external toArray : array(int) = "";

[@bs.send.pipe: t] external serialize : array(int) = "";

[@bs.send.pipe: t] external toString : string = "";
