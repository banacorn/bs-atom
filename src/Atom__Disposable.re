open Atom__Type;

include Disposable;

/* Construction and Destruction */
[@bs.module "atom"] [@bs.new] external make : unit => t = "Disposable";

[@bs.send.pipe: t] external dispose : unit = "";

/* Methods */
[@bs.send.pipe: t] external isDisposable : bool = "";
