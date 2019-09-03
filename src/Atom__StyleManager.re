open Atom__Type;

include Styles;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

type htmlStyleElement;

/* observeStyleElements */
[@bs.val] [@bs.scope ("atom", "styles")]
external observeStyleElements:
  ((htmlStyleElement, string, string) => unit) => Disposable.t =
  "observeStyleElements";

/* onDidAddStyleElement */
[@bs.val] [@bs.scope ("atom", "styles")]
external onDidAddStyleElement:
  ((htmlStyleElement, string, string) => unit) => Disposable.t =
  "onDidAddStyleElement";

/* onDidRemoveStyleElement */
[@bs.val] [@bs.scope ("atom", "styles")]
external onDidRemoveStyleElement: (htmlStyleElement => unit) => Disposable.t =
  "onDidRemoveStyleElement";

/* onDidUpdateStyleElement */
[@bs.val] [@bs.scope ("atom", "styles")]
external onDidUpdateStyleElement:
  ((htmlStyleElement, string, string) => unit) => Disposable.t =
  "onDidUpdateStyleElement";

/*************************************************************************************************************
  Reading Style Elements
 ************************************************************************************************************/

/* getStyleElements */
[@bs.val] [@bs.scope ("atom", "styles")]
external getStyleElements: unit => array(htmlStyleElement) =
  "getStyleElements";

/*************************************************************************************************************
  Paths
 ************************************************************************************************************/

/* getUserStyleSheetPath */
[@bs.val] [@bs.scope ("atom", "styles")]
external getUserStyleSheetPath: unit => string = "getUserStyleSheetPath";
