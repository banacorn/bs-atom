open Atom__Type;

type item = {
  .
  "label": string,
  "submenu": array(item),
  "command": option(string),
};

/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

/* add */
[@bs.val] [@bs.scope ("atom", "menu")]
external add: array(item) => Disposable.t = "add";

/* update */
[@bs.val] [@bs.scope ("atom", "menu")]
external update: unit => unit = "update";
