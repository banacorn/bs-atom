open Type;

type t = panel;

[@bs.send.pipe: t] external isVisible : unit => bool = "isVisible";

[@bs.send.pipe: t] external hide : unit => unit = "hide";

[@bs.send.pipe: t] external show : unit => unit = "show";

[@bs.send.pipe: t] external destroy : unit => unit = "destroy";
