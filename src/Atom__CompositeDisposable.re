open Atom__Type;

include CompositeDisposable;

/* Construction and Destruction */
[@bs.module "atom"] [@bs.new]
external make : unit => t = "CompositeDisposable";

[@bs.send.pipe: t] external dispose : unit = "";

/* Managing Disposables */
[@bs.send] external add : (t, Disposable.t) => unit = "";

[@bs.send.pipe: t] external addMany : array(Disposable.t) => unit = "";

[@bs.send.pipe: t] external remove : Disposable.t => unit = "";

[@bs.send.pipe: t] external clear : unit = "";
