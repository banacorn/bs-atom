open Atom__Type;

include Selection;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChangeRange */
[@bs.send.pipe: t]
external onDidChangeRange:
  (
    {
      .
      "oldBufferRange": Range.t,
      "oldScreenRange": Range.t,
      "newBufferRange": Range.t,
      "newScreenRange": Range.t,
      "selection": Selection.t,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidChangeRange";

/* onDidDestroy */
[@bs.send.pipe: t]
external onDidDestroy: (unit => unit) => Disposable.t = "onDidDestroy";

/*************************************************************************************************************
  Managing the selection range
 ************************************************************************************************************/

/* getScreenRange */
[@bs.send.pipe: t] external getScreenRange: Range.t = "getScreenRange";

/* setScreenRange */
[@bs.send.pipe: t] external setScreenRange: Range.t => unit = "setScreenRange";

[@bs.send.pipe: t]
external setBufferRange_:
  (
    Range.t,
    {
      .
      "reversed": bool,
      "preserveFolds": bool,
      "autoscroll": bool,
    }
  ) =>
  unit =
  "setBufferRange";

/* getBufferRange */
[@bs.send.pipe: t] external getBufferRange: Range.t = "getBufferRange";

/* setBufferRange */
[@bs.send.pipe: t] external setBufferRange: Range.t = "setBufferRange";

/* getBufferRowRange */
[@bs.send.pipe: t]
external getBufferRowRange: Range.t => unit = "getBufferRowRange";

[@bs.send.pipe: t]
external getBufferRowRange_:
  (
    Range.t,
    {
      .
      "reversed": bool,
      "preserveFolds": bool,
      "autoscroll": bool,
    }
  ) =>
  unit =
  "getBufferRowRange";

/*************************************************************************************************************
  Info about the selection
 ************************************************************************************************************/

/* isEmpty */
[@bs.send.pipe: t] external isEmpty: bool = "isEmpty";

/* isReversed */
[@bs.send.pipe: t] external isReversed: bool = "isReversed";

/* isSingleScreenLine */
[@bs.send.pipe: t] external isSingleScreenLine: bool = "isSingleScreenLine";

/* getText */
[@bs.send.pipe: t] external getText: string = "getText";

/* intersectsBufferRange */
[@bs.send.pipe: t]
external intersectsBufferRange: Range.t => bool = "intersectsBufferRange";

/* intersectsWith */
[@bs.send.pipe: t]
external intersectsWith: Selection.t => bool = "intersectsWith";

/*************************************************************************************************************
  Modifying the selected range
 ************************************************************************************************************/

/* clear */
[@bs.send.pipe: t] external clear: unit = "clear";

[@bs.send.pipe: t] external clear_: {. "autoscroll": bool} => unit = "clear";

/* selectToScreenPosition */
[@bs.send.pipe: t]
external selectToScreenPosition: Point.t => unit = "selectToScreenPosition";

/* selectToBufferPosition */
[@bs.send.pipe: t]
external selectToBufferPosition: Point.t => unit = "selectToBufferPosition";

/* selectRight */
[@bs.send.pipe: t] external selectRight: int => unit = "selectRight";

/* selectLeft */
[@bs.send.pipe: t] external selectLeft: int => unit = "selectLeft";

/* selectUp */
[@bs.send.pipe: t] external selectUp: int => unit = "selectUp";

/* selectDown */
[@bs.send.pipe: t] external selectDown: int => unit = "selectDown";

/* selectToTop */
[@bs.send.pipe: t] external selectToTop: unit = "selectToTop";

/* selectToBottom */
[@bs.send.pipe: t] external selectToBottom: unit = "selectToBottom";

/* selectAll */
[@bs.send.pipe: t] external selectAll: unit = "selectAll";

/* selectToBeginningOfLine */
[@bs.send.pipe: t]
external selectToBeginningOfLine: unit = "selectToBeginningOfLine";

/* selectToFirstCharacterOfLine */
[@bs.send.pipe: t]
external selectToFirstCharacterOfLine: unit = "selectToFirstCharacterOfLine";

/* selectToEndOfLine */
[@bs.send.pipe: t] external selectToEndOfLine: unit = "selectToEndOfLine";

/* selectToEndOfBufferLine */
[@bs.send.pipe: t]
external selectToEndOfBufferLine: unit = "selectToEndOfBufferLine";

/* selectToBeginningOfWord */
[@bs.send.pipe: t]
external selectToBeginningOfWord: unit = "selectToBeginningOfWord";

/* selectToEndOfWord */
[@bs.send.pipe: t] external selectToEndOfWord: unit = "selectToEndOfWord";

/* selectToBeginningOfNextWord */
[@bs.send.pipe: t]
external selectToBeginningOfNextWord: unit = "selectToBeginningOfNextWord";

/* selectToPreviousWordBoundary */
[@bs.send.pipe: t]
external selectToPreviousWordBoundary: unit = "selectToPreviousWordBoundary";

/* selectToNextWordBoundary */
[@bs.send.pipe: t]
external selectToNextWordBoundary: unit = "selectToNextWordBoundary";

/* selectToPreviousSubwordBoundary */
[@bs.send.pipe: t]
external selectToPreviousSubwordBoundary: unit =
  "selectToPreviousSubwordBoundary";

/* selectToNextSubwordBoundary */
[@bs.send.pipe: t]
external selectToNextSubwordBoundary: unit = "selectToNextSubwordBoundary";

/* selectToBeginningOfNextParagraph */
[@bs.send.pipe: t]
external selectToBeginningOfNextParagraph: unit =
  "selectToBeginningOfNextParagraph";

/* selectToBeginningOfPreviousParagraph */
[@bs.send.pipe: t]
external selectToBeginningOfPreviousParagraph: unit =
  "selectToBeginningOfPreviousParagraph";

/* selectWord */
[@bs.send.pipe: t] external selectWord: unit = "selectWord";

/* expandOverWord */
[@bs.send.pipe: t] external expandOverWord: unit = "expandOverWord";

/* selectLine */
[@bs.send.pipe: t] external selectLine: int => unit = "selectLine";

/* expandOverLine */
[@bs.send.pipe: t] external expandOverLine: unit = "expandOverLine";

/*************************************************************************************************************
  Modifying the selected text
 ************************************************************************************************************/

type insertTextOptions = {
  .
  "select": bool,
  "autoIndent": bool,
  "autoIndentNewline": bool,
  "autoDecreaseIndent": bool,
  "preserveTrailingLineIndentation": bool,
  "normalizeLineEndings": bool,
  "bypassReadOnly": bool,
};

type bypassReadOnly = {. "bypassReadOnly": bool};

/* insertText */
[@bs.send.pipe: t] external insertText: string => unit = "insertText";

[@bs.send.pipe: t]
external insertText_: (string, insertTextOptions) => unit = "insertText";

/* backspace */
[@bs.send.pipe: t] external backspace: unit = "backspace";

[@bs.send.pipe: t] external backspace_: bypassReadOnly => unit = "backspace";

/* deleteToPreviousWordBoundary */
[@bs.send.pipe: t]
external deleteToPreviousWordBoundary: unit = "deleteToPreviousWordBoundary";

[@bs.send.pipe: t]
external deleteToPreviousWordBoundary_: bypassReadOnly => unit =
  "deleteToPreviousWordBoundary";

/* deleteToNextWordBoundary */
[@bs.send.pipe: t]
external deleteToNextWordBoundary: unit = "deleteToNextWordBoundary";

[@bs.send.pipe: t]
external deleteToNextWordBoundary_: bypassReadOnly => unit =
  "deleteToNextWordBoundary";

/* deleteToBeginningOfWord */
[@bs.send.pipe: t]
external deleteToBeginningOfWord: unit = "deleteToBeginningOfWord";

[@bs.send.pipe: t]
external deleteToBeginningOfWord_: bypassReadOnly => unit =
  "deleteToBeginningOfWord";

/* deleteToBeginningOfLine */
[@bs.send.pipe: t]
external deleteToBeginningOfLine: unit = "deleteToBeginningOfLine";

[@bs.send.pipe: t]
external deleteToBeginningOfLine_: bypassReadOnly => unit =
  "deleteToBeginningOfLine";

/* delete */
[@bs.send.pipe: t] external delete: unit = "delete";

[@bs.send.pipe: t] external delete_: bypassReadOnly => unit = "delete";

/* deleteToEndOfLine */
[@bs.send.pipe: t] external deleteToEndOfLine: unit = "deleteToEndOfLine";

[@bs.send.pipe: t]
external deleteToEndOfLine_: bypassReadOnly => unit = "deleteToEndOfLine";

/* deleteToEndOfWord */
[@bs.send.pipe: t] external deleteToEndOfWord: unit = "deleteToEndOfWord";

[@bs.send.pipe: t]
external deleteToEndOfWord_: bypassReadOnly => unit = "deleteToEndOfWord";

/* deleteToBeginningOfSubword */
[@bs.send.pipe: t]
external deleteToBeginningOfSubword: unit = "deleteToBeginningOfSubword";

[@bs.send.pipe: t]
external deleteToBeginningOfSubword_: bypassReadOnly => unit =
  "deleteToBeginningOfSubword";

/* deleteToEndOfSubword */
[@bs.send.pipe: t]
external deleteToEndOfSubword: unit = "deleteToEndOfSubword";

[@bs.send.pipe: t]
external deleteToEndOfSubword_: bypassReadOnly => unit =
  "deleteToEndOfSubword";

/* deleteSelectedText */
[@bs.send.pipe: t] external deleteSelectedText: unit = "deleteSelectedText";

[@bs.send.pipe: t]
external deleteSelectedText_: bypassReadOnly => unit = "deleteSelectedText";

/* deleteLine */
[@bs.send.pipe: t] external deleteLine: unit = "deleteLine";

[@bs.send.pipe: t] external deleteLine_: bypassReadOnly => unit = "deleteLine";

/* joinLines */
[@bs.send.pipe: t] external joinLines: unit = "joinLines";

[@bs.send.pipe: t] external joinLines_: bypassReadOnly => unit = "joinLines";

/* outdentSelectedRows */
[@bs.send.pipe: t] external outdentSelectedRows: unit = "outdentSelectedRows";

[@bs.send.pipe: t]
external outdentSelectedRows_: bypassReadOnly => unit = "outdentSelectedRows";

/* autoIndentSelectedRows */
[@bs.send.pipe: t]
external autoIndentSelectedRows: unit = "autoIndentSelectedRows";

[@bs.send.pipe: t]
external autoIndentSelectedRows_: bypassReadOnly => unit =
  "autoIndentSelectedRows";

/* toggleLineComments */
[@bs.send.pipe: t] external toggleLineComments: unit = "toggleLineComments";

[@bs.send.pipe: t]
external toggleLineComments_: bypassReadOnly => unit = "toggleLineComments";

/* cutToEndOfLine */
[@bs.send.pipe: t] external cutToEndOfLine: unit = "cutToEndOfLine";

[@bs.send.pipe: t]
external cutToEndOfLine_: bypassReadOnly => unit = "cutToEndOfLine";

/* cutToEndOfBufferLine */
[@bs.send.pipe: t]
external cutToEndOfBufferLine: unit = "cutToEndOfBufferLine";

[@bs.send.pipe: t]
external cutToEndOfBufferLine_: bypassReadOnly => unit =
  "cutToEndOfBufferLine";

/* cut */
[@bs.send.pipe: t] external cut: unit = "cut";

[@bs.send.pipe: t] external cut_: (bool, bool, bool) => unit = "cut";

/* copy */
[@bs.send.pipe: t] external copy: unit = "copy";

[@bs.send.pipe: t] external copy_: (bool, bool) => unit = "copy";

/* fold */
[@bs.send.pipe: t] external fold: unit = "fold";

/* indentSelectedRows */
[@bs.send.pipe: t] external indentSelectedRows: unit = "indentSelectedRows";

[@bs.send.pipe: t]
external indentSelectedRows_: bypassReadOnly => unit = "indentSelectedRows";

/*************************************************************************************************************
  Managing multiple selections
 ************************************************************************************************************/

/* addSelectionBelow */
[@bs.send.pipe: t] external addSelectionBelow: unit = "addSelectionBelow";

/* addSelectionAbove */
[@bs.send.pipe: t] external addSelectionAbove: unit = "addSelectionAbove";

/* merge */
[@bs.send.pipe: t] external merge: Selection.t => unit = "merge";

[@bs.send.pipe: t]
external merge_:
  (
    Selection.t,
    {
      .
      "reversed": bool,
      "preserveFolds": bool,
      "autoscroll": bool,
    }
  ) =>
  unit =
  "merge";

/*************************************************************************************************************
  Comparing to other selections
 ************************************************************************************************************/

/* compare  */
[@bs.send.pipe: t] external compare: Selection.t => int = "compare";
