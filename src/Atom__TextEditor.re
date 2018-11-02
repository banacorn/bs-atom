open Atom__Type;

include TextEditor;

[@bs.send.pipe: t] external getCursors : array(cursor) = "getCursors";

[@bs.send.pipe: t] external isMini : bool = "isMini";

/* File Details */
[@bs.send.pipe: t] external getTitle : string = "getTitle";

[@bs.send.pipe: t] external getLongTitle : string = "getLongTitle";

[@bs.send.pipe: t] external getPath : string = "getPath";

[@bs.send.pipe: t] external isModified : bool = "isModified";

[@bs.send.pipe: t] external isEmpty : bool = "isModified";

/* Reading Text */
[@bs.send.pipe: t] external getText : string = "getText";

/* Mutating Text */
[@bs.send.pipe: t] external setText : string => unit = "setText";

[@bs.send.pipe: t]
external setTextWithOption : (string, {. bypassReadOnly: bool}) => unit =
  "setText";

/* Grammars */
[@bs.send.pipe: t] external setGrammar : grammar => unit = "setGrammar";

/* TextEditor Rendering */
[@bs.send.pipe: t] external getPlaceholderText : string = "getPlaceholderText";

[@bs.send.pipe: t]
external setPlaceholderText : string => unit = "setPlaceholderText";
/*
 [@bs.deriving abstract]
 type textEditor = {languageMode}; */
