open Atom__Type;

type t = compositeDisposable;

[@bs.module "atom"] [@bs.new]
external make : unit => t = "CompositeDisposable";

[@bs.send.pipe: t] external dispose : unit = "dispose";

[@bs.send] external add : (t, disposable) => unit = "add";

[@bs.send.pipe: t] external addMany : array(disposable) => unit = "add";

[@bs.send.pipe: t] external remove : disposable => unit = "remove";

[@bs.send.pipe: t] external clear : unit = "clear";
