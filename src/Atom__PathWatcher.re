open Atom__Type;

include PathWatcher;

/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

/* getStartPromise */
[@bs.send.pipe: t]
external getStartPromise: Js.Promise.t(unit) = "getStartPromise";

/* onDidError */
[@bs.send.pipe: t]
external onDidError: (Js.Exn.t => unit) => Disposable.t = "onDidError";

/* dispose */
[@bs.send.pipe: t] external dispose: unit = "dispose";
