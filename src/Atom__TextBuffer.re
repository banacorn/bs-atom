open Atom__Type;

include TextBuffer;

/* Reading Text */
[@bs.send.pipe: t] external isEmpty: bool = "";

[@bs.send.pipe: t] external getText: string = "";

[@bs.send.pipe: t] external getTextInRange: Range.t => string = "";

[@bs.send.pipe: t] external getLines: array(string) = "";

[@bs.send.pipe: t] external getLastText: string = "";

[@bs.send.pipe: t] external lineForRow: int => string = "";

[@bs.send.pipe: t] external lineEndingForRow: int => string = "";

[@bs.send.pipe: t] external lineLengthForRow: int => int = "";

[@bs.send.pipe: t] external isRowBlank: int => bool = "";

[@bs.send.pipe: t] external previousNonBlankRow: int => option(int) = "";

[@bs.send.pipe: t] external nextNonBlankRow: int => option(int) = "";

[@bs.send.pipe: t] external hasAstral: bool = "";

/* Mutating Text */
[@bs.send.pipe: t] external setText: string => Range.t = "";

[@bs.send.pipe: t] external setTextViaDiff: string => Range.t = "";

[@bs.send.pipe: t] external setTextInRange: (Range.t, string) => Range.t = "";

[@bs.send.pipe: t]
external setTextInRange': (Range.t, string, Js.t({.})) => Range.t =
  "setTextInRange";

[@bs.send.pipe: t] external insert: (Point.t, string) => Range.t = "";

[@bs.send.pipe: t]
external insert': (Point.t, string, Js.t({.})) => Range.t = "insert";

[@bs.send.pipe: t] external append: string => Range.t = "";

[@bs.send.pipe: t]
external append': (string, Js.t({.})) => Range.t = "append";

[@bs.send.pipe: t] external delete: Range.t => Range.t = "";

[@bs.send.pipe: t] external deleteRow: int => Range.t = "";

[@bs.send.pipe: t] external deleteRows: (int, int) => Range.t = "";

/* Buffer Range Details */
[@bs.send.pipe: t] external getRange: Range.t = "";

[@bs.send.pipe: t] external getLineCount: int = "";

[@bs.send.pipe: t] external getLastRow: int = "";

[@bs.send.pipe: t] external getFirstPosition: Point.t = "";

[@bs.send.pipe: t] external getEndPosition: Point.t = "";

[@bs.send.pipe: t] external getLength: int = "";

[@bs.send.pipe: t] external getMaxCharacterIndex: int = "";

[@bs.send.pipe: t] external rangeForRow: (int, bool) => Range.t = "";

[@bs.send.pipe: t] external characterIndexForPosition: Point.t => int = "";

[@bs.send.pipe: t] external positionForCharacterIndex: int => Point.t = "";

[@bs.send.pipe: t] external clipRange: Range.t => Range.t = "";

[@bs.send.pipe: t] external clipPosition: Point.t => Point.t = "";
