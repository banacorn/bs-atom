open Atom__Type;

include Range;

/*************************************************************************************************************
  Properties
 ************************************************************************************************************/

/* start */
[@bs.get] external start: t => Point.t = "start";

/* end */
[@bs.get] external end_: t => Point.t = "end";

/*************************************************************************************************************
  Construction
 ************************************************************************************************************/

/* fromObject */
[@bs.send.pipe: t]
external fromObject:
  {
    .
    "start": Point.t,
    "end": Point.t,
  } =>
  t =
  "fromObject";

/* constructor */
[@bs.module "atom"] [@bs.new] external make: (Point.t, Point.t) => t = "Range";

/* copy */
[@bs.send.pipe: t] external copy: t = "copy";

/* negate */
[@bs.send.pipe: t] external negate: t = "negate";

/*************************************************************************************************************
  Serialization and Deserialization
 ************************************************************************************************************/

/* serialize */
[@bs.send.pipe: t] external serialize: Js.t({.}) = "serialize";

/* deserialize */
[@bs.send.pipe: t] external deserialize: array(Point.t) => t = "deserialize";

/*************************************************************************************************************
  Range Details
 ************************************************************************************************************/

/* isEmpty */
[@bs.send.pipe: t] external isEmpty: bool = "isEmpty";

/* isEmpty */
[@bs.send.pipe: t] external isSingleLine: bool = "isSingleLine";

/* getRowCount */
[@bs.send.pipe: t] external getRowCount: int = "getRowCount";

/* getRows */
[@bs.send.pipe: t] external getRows: array(int) = "getRows";

/*************************************************************************************************************
  Operations
 ************************************************************************************************************/

/* freeze */
[@bs.send.pipe: t] external freeze: t = "freeze";

/* union */
[@bs.send.pipe: t] external union: t => t = "union";

/* translate */
[@bs.send.pipe: t] external translate: (Point.t, Point.t) => t = "translate";

/* traverse */
[@bs.send.pipe: t] external traverse: Point.t => t = "traverse";

/*************************************************************************************************************
  Comparison
 ************************************************************************************************************/

/* compare */
[@bs.send.pipe: t] external compare: t => int = "compare";

/* isEqual */
[@bs.send.pipe: t] external isEqual: t => bool = "isEqual";

/* coversSameRows */
[@bs.send.pipe: t] external coversSameRows: t => bool = "coversSameRows";

/* intersectsWith */
[@bs.send.pipe: t] external intersectsWith: t => bool = "intersectsWith";
[@bs.send.pipe: t]
external intersectsWith_: (t, bool) => bool = "intersectsWith";

/* containsRange */
[@bs.send.pipe: t] external containsRange: t => bool = "containsRange";
[@bs.send.pipe: t]
external containsRange_: (t, bool) => bool = "containsRange";

/* containsPoint */
[@bs.send.pipe: t] external containsPoint: Point.t => bool = "containsPoint";
[@bs.send.pipe: t]
external containsPoint_: (Point.t, bool) => bool = "containsPoint";

/* intersectsRow */
[@bs.send.pipe: t] external intersectsRow: int => bool = "intersectsRow";

/* intersectsRowRange */
[@bs.send.pipe: t]
external intersectsRowRange: (int, int) => bool = "intersectsRowRange";

/*************************************************************************************************************
  Conversion
 ************************************************************************************************************/

/* toString */
[@bs.send.pipe: t] external toString: string = "toString";
