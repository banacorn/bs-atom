open Atom__Type;

include Point;

/*************************************************************************************************************
  Properties
 ************************************************************************************************************/

/* row */
[@bs.get] external row: t => int = "row";

/* column */
[@bs.get] external column: t => int = "column";

/*************************************************************************************************************
  Construction
 ************************************************************************************************************/

/* fromObject */
[@bs.send.pipe: t]
external fromObject:
  {
    .
    "row": int,
    "column": int,
  } =>
  t =
  "fromObject";

[@bs.send.pipe: t] external fromArray: array(int) => t = "fromObject";

/* constructor */
[@bs.module "atom"] [@bs.new] external make: (int, int) => t = "Point";

/* copy */
[@bs.send.pipe: t] external copy: t = "copy";

/* negate */
[@bs.send.pipe: t] external negate: t = "negate";

/* destroy */
[@bs.send.pipe: t] external destroy: unit = "destroy";

/*************************************************************************************************************
  Comparison
 ************************************************************************************************************/

/* min */
[@bs.send.pipe: t] external min: (t, t) => t = "min";

/* compare */
[@bs.send.pipe: t] external compare: t => int = "compare";

/* isEqual */
[@bs.send.pipe: t] external isEqual: t => bool = "isEqual";

/* isLessThan */
[@bs.send.pipe: t] external isLessThan: t => bool = "isLessThan";

/* isLessThanOrEqual */
[@bs.send.pipe: t] external isLessThanOrEqual: t => bool = "isLessThanOrEqual";

/* isGreaterThan */
[@bs.send.pipe: t] external isGreaterThan: t => bool = "isGreaterThan";

/* isGreaterThanOrEqual */
[@bs.send.pipe: t]
external isGreaterThanOrEqual: t => bool = "isGreaterThanOrEqual";

/*************************************************************************************************************
  Operations
 ************************************************************************************************************/

/* freeze */
[@bs.send.pipe: t] external freeze: t = "freeze";

/* translate */
[@bs.send.pipe: t] external translate: t => t = "translate";

/* traverse */
[@bs.send.pipe: t] external traverse: t => t = "traverse";

/*************************************************************************************************************
  Conversion
 ************************************************************************************************************/

/* toArray */
[@bs.send.pipe: t] external toArray: array(int) = "toArray";

/* serialize */
[@bs.send.pipe: t] external serialize: array(int) = "serialize";

/* toString */
[@bs.send.pipe: t] external toString: string = "toString";
