open Atom__Type;

include Cursor;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChangePosition */
[@bs.send.pipe: t]
external onDidChangePosition:
  (
    {
      .
      "oldBufferPosition": Point.t,
      "oldScreenPosition": Point.t,
      "newBufferPosition": Point.t,
      "newScreenPosition": Point.t,
      "textChanged": bool,
      "cursor": t,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidChangePosition";

/* onDidDestroy */
[@bs.send.pipe: t]
external onDidDestroy: (unit => unit) => Disposable.t = "onDidDestroy";

/*************************************************************************************************************
  Managing Cursor Position
 ************************************************************************************************************/

/* setScreenPosition */
[@bs.send.pipe: t]
external setScreenPositionPrim: array(int) => unit = "setScreenPosition";

let setScreenPosition: ((int, int), t) => unit =
  ((row, col), self) => self |> setScreenPositionPrim([|row, col|]);

[@bs.send.pipe: t]
external setScreenPositionPrim_: (array(int), {. "autoscroll": bool}) => unit =
  "setScreenPosition";

let setScreenPosition_: ((int, int), {. "autoscroll": bool}, t) => unit =
  ((row, col), options, self) =>
    self |> setScreenPositionPrim_([|row, col|], options);

/* getScreenPosition */
[@bs.send.pipe: t] external getScreenPosition: Point.t = "getScreenPosition";

/* setBufferPosition */
[@bs.send.pipe: t]
external setBufferPositionPrim: array(int) => unit = "setBufferPosition";

let setBufferPosition: ((int, int), t) => unit =
  ((row, col), self) => self |> setBufferPositionPrim([|row, col|]);

[@bs.send.pipe: t]
external setBufferPositionPrim_: (array(int), {. "autoscroll": bool}) => unit =
  "setBufferPosition";

let setBufferPosition_: ((int, int), {. "autoscroll": bool}, t) => unit =
  ((row, col), options, self) =>
    self |> setBufferPositionPrim_([|row, col|], options);

/* getBufferPosition */
[@bs.send.pipe: t] external getBufferPosition: Point.t = "getBufferPosition";

/* getScreenRow */
[@bs.send.pipe: t] external getScreenRow: int = "getScreenRow";

/* getScreenColumn */
[@bs.send.pipe: t] external getScreenColumn: int = "getScreenColumn";

/* getBufferRow */
[@bs.send.pipe: t] external getBufferRow: int = "getBufferRow";

/* getBufferColumn */
[@bs.send.pipe: t] external getBufferColumn: int = "getBufferColumn";

/* getCurrentBufferLine */
[@bs.send.pipe: t] external getCurrentBufferLine: int = "getCurrentBufferLine";

/* isAtBeginningOfLine */
[@bs.send.pipe: t] external isAtBeginningOfLine: bool = "isAtBeginningOfLine";

/* isAtEndOfLine */
[@bs.send.pipe: t] external isAtEndOfLine: bool = "isAtEndOfLine";

/*************************************************************************************************************
  Cursor Position Details
 ************************************************************************************************************/

/* getMarker */
[@bs.send.pipe: t] external getMarker: DisplayMarker.t = "getMarker";

/* isSurroundedByWhitespace */
[@bs.send.pipe: t]
external isSurroundedByWhitespace: bool = "isSurroundedByWhitespace";

/* isBetweenWordAndNonWord */
[@bs.send.pipe: t]
external isBetweenWordAndNonWord: bool = "isBetweenWordAndNonWord";

/* isInsideWord */
[@bs.send.pipe: t] external isInsideWord: bool = "isInsideWord";

[@bs.send.pipe: t]
external isInsideWord_: {. "wordRegex": Js.Re.t} => bool = "isInsideWord";

/* getIndentLevel */
[@bs.send.pipe: t] external getIndentLevel: int = "getIndentLevel";

/* getScopeDescriptor */
[@bs.send.pipe: t]
external getScopeDescriptor: ScopeDescriptor.t = "getScopeDescriptor";

/* getSyntaxTreeScopeDescriptor */
[@bs.send.pipe: t]
external getSyntaxTreeScopeDescriptor: ScopeDescriptor.t =
  "getSyntaxTreeScopeDescriptor";

/* hasPrecedingCharactersOnLine */
[@bs.send.pipe: t]
external hasPrecedingCharactersOnLine: bool = "hasPrecedingCharactersOnLine";

/* isLastCursor */
[@bs.send.pipe: t] external isLastCursor: bool = "isLastCursor";

/*************************************************************************************************************
  Moving the Cursor
 ************************************************************************************************************/

/* moveUp */
[@bs.send.pipe: t] external moveUp: unit = "moveUp";

[@bs.send.pipe: t] external moveUpBy: int => unit = "moveUp";

[@bs.send.pipe: t]
external moveUpBy_: (int, {. "moveToEndOfSelection": bool}) => unit =
  "moveUp";

/* moveDown */
[@bs.send.pipe: t] external moveDown: unit = "moveDown";

[@bs.send.pipe: t] external moveDownBy: int => unit = "moveDown";

[@bs.send.pipe: t]
external moveDownBy_: (int, {. "moveToEndOfSelection": bool}) => unit =
  "moveDown";

/* moveLeft */
[@bs.send.pipe: t] external moveLeft: unit = "moveLeft";

[@bs.send.pipe: t] external moveLeftBy: int => unit = "moveLeft";

[@bs.send.pipe: t]
external moveLeftBy_: (int, {. "moveToEndOfSelection": bool}) => unit =
  "moveLeft";

/* moveRight */
[@bs.send.pipe: t] external moveRight: unit = "moveRight";

[@bs.send.pipe: t] external moveRightBy: int => unit = "moveRight";

[@bs.send.pipe: t]
external moveRightBy_: (int, {. "moveToEndOfSelection": bool}) => unit =
  "moveRight";

/* moveToTop */
[@bs.send.pipe: t] external moveToTop: unit = "moveToTop";

/* moveToBottom */
[@bs.send.pipe: t] external moveToBottom: unit = "moveToBottom";

/* moveToBeginningOfScreenLine */
[@bs.send.pipe: t]
external moveToBeginningOfScreenLine: unit = "moveToBeginningOfScreenLine";

/* moveToBeginningOfLine */
[@bs.send.pipe: t]
external moveToBeginningOfLine: unit = "moveToBeginningOfLine";

/* moveToFirstCharacterOfLine */
[@bs.send.pipe: t]
external moveToFirstCharacterOfLine: unit = "moveToFirstCharacterOfLine";

/* moveToEndOfScreenLine */
[@bs.send.pipe: t]
external moveToEndOfScreenLine: unit = "moveToEndOfScreenLine";

/* moveToEndOfLine */
[@bs.send.pipe: t] external moveToEndOfLine: unit = "moveToEndOfLine";

/* moveToBeginningOfWord */
[@bs.send.pipe: t]
external moveToBeginningOfWord: unit = "moveToBeginningOfWord";

/* moveToEndOfWord */
[@bs.send.pipe: t] external moveToEndOfWord: unit = "moveToEndOfWord";

/* moveToBeginningOfNextWord */
[@bs.send.pipe: t]
external moveToBeginningOfNextWord: unit = "moveToBeginningOfNextWord";

/* moveToPreviousWordBoundary */
[@bs.send.pipe: t]
external moveToPreviousWordBoundary: unit = "moveToPreviousWordBoundary";

/* moveToNextWordBoundary */
[@bs.send.pipe: t]
external moveToNextWordBoundary: unit = "moveToNextWordBoundary";

/* moveToPreviousSubwordBoundary */
[@bs.send.pipe: t]
external moveToPreviousSubwordBoundary: unit = "moveToPreviousSubwordBoundary";

/* moveToNextSubwordBoundary */
[@bs.send.pipe: t]
external moveToNextSubwordBoundary: unit = "moveToNextSubwordBoundary";

/* skipLeadingWhitespace */
[@bs.send.pipe: t]
external skipLeadingWhitespace: unit = "skipLeadingWhitespace";

/* moveToBeginningOfNextParagraph */
[@bs.send.pipe: t]
external moveToBeginningOfNextParagraph: unit =
  "moveToBeginningOfNextParagraph";

/* moveToBeginningOfPreviousParagraph */
[@bs.send.pipe: t]
external moveToBeginningOfPreviousParagraph: unit =
  "moveToBeginningOfPreviousParagraph";
