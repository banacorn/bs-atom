open Atom__Type;

include BufferedProcess;

/*************************************************************************************************************
  Construction
 ************************************************************************************************************/

/* constructor */
[@bs.module "atom"] [@bs.new]
external make:
  {
    .
    "command": string,
    "args": array(string),
    "options": Js.t({.}),
    [@bs.meth] "stdout": string => unit,
    [@bs.meth] "stderr": string => unit,
    [@bs.meth] "exit": int => unit,
  } =>
  t =
  "BufferedProcess";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onWillThrowError */
[@bs.send.pipe: t]
external onWillThrowError:
  {
    .
    "error": Js.Exn.t,
    [@bs.meth] "handle": unit => unit,
  } =>
  Disposable.t =
  "onWillThrowError";

/*************************************************************************************************************
  Helper Methods
 ************************************************************************************************************/

/* kill */
[@bs.send.pipe: t] external kill: unit = "kill";
