open Type;

type t = textEditor;

[@bs.send.pipe: t] external getCursors : t => array(cursor) = "getCursors";

[@bs.send.pipe: t] external isMini : t => bool = "isMini";

/* Reading Text */
[@bs.send.pipe: t] external getText : string = "getText";

/* Mutating Text */
[@bs.send.pipe: t] external setText : string => unit = "setText";

[@bs.send.pipe: t]
external setTextWithOption : (t, string, {. bypassReadOnly: bool}) => unit =
  "setText";

/* TextEditor Rendering */
[@bs.send.pipe: t]
external getPlaceholderText : t => string = "getPlaceholderText";

[@bs.send.pipe: t]
external setPlaceholderText : string => unit = "setPlaceholderText";
