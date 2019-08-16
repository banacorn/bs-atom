open Atom__Type;

include Color;

/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

/* parse */
[@bs.val] [@bs.scope ("atom", "color")]
external parseString: string => Js.Nullable.t(t) = "parse";

[@bs.val] [@bs.scope ("atom", "color")]
external parseObject: Js.t({.}) => Js.Nullable.t(t) = "parse";

/* toHexString */
[@bs.send.pipe: t] external toHexString: string = "toHexString";

/* toRGBAString */
[@bs.send.pipe: t] external toRGBAString: string = "toRGBAString";
