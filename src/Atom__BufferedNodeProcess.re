open Atom__Type;

include BufferedNodeProcess;

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
  "BufferedNodeProcess";
