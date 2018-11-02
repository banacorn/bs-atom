open Atom__Type;

type t = cursor;

[@bs.send.pipe: t] external getScreenRow : unit => int = "getScreenRow";

[@bs.send.pipe: t] external moveUp : unit => unit = "moveUp";

[@bs.send.pipe: t] external moveUpBy : int => unit = "moveUpBy";

[@bs.send.pipe: t] external moveDown : unit => unit = "moveDown";

[@bs.send.pipe: t] external moveDownBy : int => unit = "moveDownBy";

[@bs.send.pipe: t] external moveLeft : unit => unit = "moveLeft";

[@bs.send.pipe: t] external moveLeftBy : int => unit = "moveLeftBy";

[@bs.send.pipe: t] external moveRight : unit => unit = "moveRight";

[@bs.send.pipe: t] external moveRightBy : int => unit = "moveRightBy";
