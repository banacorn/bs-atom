open Atom__Type;

include CompositeDisposable;

/*************************************************************************************************************
  Construction and Destruction
 ************************************************************************************************************/

/* constructor */
[@bs.module "atom"] [@bs.new] external make: unit => t = "CompositeDisposable";

[@bs.module "atom"] [@bs.new]
external makeMany: array(Disposable.t) => t = "CompositeDisposable";

/* dispose */
[@bs.send.pipe: t] external dispose: unit = "dispose";

/*************************************************************************************************************
  Managing Disposables
 ************************************************************************************************************/

/* add */
[@bs.send] external add: (t, Disposable.t) => unit = "add";

/* addMany */
[@bs.send.pipe: t] external addMany: array(Disposable.t) => unit = "add";

/* remove */
[@bs.send.pipe: t] external remove: Disposable.t => unit = "";

/* delete */
[@bs.send.pipe: t] external delete: unit = "";

/* clean */
[@bs.send.pipe: t] external clear: unit = "";
