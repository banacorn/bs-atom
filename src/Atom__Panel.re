open Atom__Type;

type t = panel;

[@bs.send.pipe: t] external isVisible : bool = "isVisible";

[@bs.send.pipe: t] external hide : unit = "hide";

[@bs.send.pipe: t] external show : unit = "show";

[@bs.send.pipe: t] external destroy : unit = "destroy";
