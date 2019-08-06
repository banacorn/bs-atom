open Atom__Type;

/*************************************************************************************************************
 Methods
 ************************************************************************************************************/

/* add */
[@bs.val] [@bs.scope ("atom", "tooltips")]
external add: (Dom.htmlElement, Js.t({..})) => Disposable.t = "add";

/* findTooltips */
[@bs.val] [@bs.scope ("atom", "tooltips")]
external findTooltips: Dom.htmlElement => array(tooltip) = "findTooltips";
