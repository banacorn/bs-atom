open Type;

type t = compositeDisposable;

[@bs.module "atom"] [@bs.new]
external make : unit => t = "CompositeDisposable";

[@bs.send] external add : (t, disposable) => unit = "";

[@bs.send.pipe: t] external destroy : unit = "";
