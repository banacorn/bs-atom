open Atom__Type;

include Task;

/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

/* .once */
[@bs.val] [@bs.scope ("atom", "Task")]
external once__: (string, 'a) => Task.t = "once";

/* constructor */
[@bs.module "atom"] [@bs.new] external make: string => t = "Task";

/* start */
[@bs.send.pipe: t] external start: 'a => unit = "start";

[@bs.send.pipe: t] external start_: ('a, unit => unit) => unit = "start";

/* send */
[@bs.send.pipe: t] external send: 'a => unit = "send";

/* on */
[@bs.send.pipe: t] external on: (string, unit => unit) => Disposable.t = "on";

/* once */
[@bs.send.pipe: t] external once: (string, unit => unit) => Task.t = "once";

/* terminate */
[@bs.send.pipe: t] external terminate: unit = "terminate";

/* cancel */
[@bs.send.pipe: t] external cancel: bool = "cancel";
