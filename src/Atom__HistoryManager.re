open Atom__Type;

/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

/* getProjects */
[@bs.val] [@bs.scope ("atom", "history")]
external getProjects: unit => array(HistoryProject.t) = "getProjects";

/* clearProjects */
[@bs.val] [@bs.scope ("atom", "history")]
external clearProjects: unit => Js.Promise.t(unit) = "clearProjects";

/* onDidChangeProjects */
[@bs.val] [@bs.scope ("atom", "history")]
external onDidChangeProjects: (unit => unit) => Disposable.t =
  "onDidChangeProjects";
