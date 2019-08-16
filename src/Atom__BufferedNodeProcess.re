open Atom__Type;

include BufferedNodeProcess;

/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

/* constructor */
[@bs.module "atom"] [@bs.new]
external make:
  {
    .
    "command": string,
    "args": array(string),
    "options": Js.t({.}),
    "stdout": string => unit,
    "stderr": string => unit,
    "exit": int => unit,
  } =>
  t =
  "BufferedNodeProcess";
