open Atom__Type;

/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

/* addViewProvider */
type createView = Js.t({.}) => option(Dom.htmlElement);

/* addViewProvider */
[@bs.val] [@bs.scope ("atom", "views")]
external addViewProvider: createView => Disposable.t = "addViewProvider";

[@bs.val] [@bs.scope ("atom", "views")]
external addViewProvider_: ('a, createView) => Disposable.t =
  "addViewProvider";

/* getView */
[@bs.val] [@bs.scope ("atom", "views")]
external getView: 'a => Dom.htmlElement = "getView";
