open Atom__Type;

include TextEditor;

/* Hack */
[@bs.get] external id: t => int = "id";

external asWorkspaceItem: TextEditor.t => Workspace.item = "%identity";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChangeTitle */
[@bs.send.pipe: t]
external onDidChangeTitle: (unit => unit) => Disposable.t = "onDidChangeTitle";

/* onDidChangePath */
[@bs.send.pipe: t]
external onDidChangePath: (unit => unit) => Disposable.t = "onDidChangePath";

/* onDidChange */
[@bs.send.pipe: t]
external onDidChange: (unit => unit) => Disposable.t = "onDidChange";

/* onDidStopChanging */
[@bs.send.pipe: t]
external onDidStopChanging: (unit => unit) => Disposable.t =
  "onDidStopChanging";

/* onDidChangeCursorPosition */
[@bs.send.pipe: t]
external onDidChangeCursorPosition:
  (
    {
      .
      "oldBufferPosition": Point.t,
      "oldScreenPosition": Point.t,
      "newBufferPosition": Point.t,
      "newScreenPosition": Point.t,
      "textChanged": bool,
      "cursor": Cursor.t,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidChangeCursorPosition";

/* onDidChangeSelectionRange */
[@bs.send.pipe: t]
external onDidChangeSelectionRange:
  (
    {
      .
      "oldBufferRange": Point.t,
      "oldScreenRange": Point.t,
      "newBufferRange": Point.t,
      "newScreenRange": Point.t,
      "selection": Selection.t,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidChangeSelectionRange";

/* onDidSave */
[@bs.send.pipe: t]
external onDidSave: ({. "path": string} => unit) => Disposable.t =
  "onDidSave";

/* onDidDestroy */
[@bs.send.pipe: t]
external onDidDestroy: (unit => unit) => Disposable.t = "onDidDestroy";

/* observeGutters */
[@bs.send.pipe: t]
external observeGutters: (Gutter.t => unit) => Disposable.t = "observeGutters";

/* onDidAddGutter */
[@bs.send.pipe: t]
external onDidAddGutter: (Gutter.t => unit) => Disposable.t = "onDidAddGutter";

/* onDidRemoveGutter */
[@bs.send.pipe: t]
external onDidRemoveGutter: (string => unit) => Disposable.t =
  "onDidRemoveGutter";

/* onDidChangeSoftWrapped */
[@bs.send.pipe: t]
external onDidChangeSoftWrapped: (unit => unit) => Disposable.t =
  "onDidChangeSoftWrapped";

/* onDidChangeEncoding */
[@bs.send.pipe: t]
external onDidChangeEncoding: (unit => unit) => Disposable.t =
  "onDidChangeEncoding";

/* observeGrammar */
[@bs.send.pipe: t]
external observeGrammar: (Grammar.t => unit) => Disposable.t =
  "observeGrammar";

/* onDidChangeGrammar */
[@bs.send.pipe: t]
external onDidChangeGrammar: (Grammar.t => unit) => Disposable.t =
  "onDidChangeGrammar";

/* onDidChangeModified */
[@bs.send.pipe: t]
external onDidChangeModified: (unit => unit) => Disposable.t =
  "onDidChangeModified";

/* onDidConflict */
[@bs.send.pipe: t]
external onDidConflict: (unit => unit) => Disposable.t = "onDidConflict";

/* onWillInsertText */
[@bs.send.pipe: t]
external onWillInsertText:
  (
    {
      .
      "text": string,
      "cancel": unit => unit,
    } =>
    unit
  ) =>
  Disposable.t =
  "onWillInsertText";

/* onDidInsertText */
[@bs.send.pipe: t]
external onDidInsertText: ({. "text": string} => unit) => Disposable.t =
  "onDidInsertText";

/* observeCursors */
[@bs.send.pipe: t]
external observeCursors: (Cursor.t => unit) => Disposable.t = "observeCursors";

/* onDidAddCursor */
[@bs.send.pipe: t]
external onDidAddCursor: (Cursor.t => unit) => Disposable.t = "onDidAddCursor";

/* onDidRemoveCursor */
[@bs.send.pipe: t]
external onDidRemoveCursor: (Cursor.t => unit) => Disposable.t =
  "onDidRemoveCursor";

/* observeSelections */
[@bs.send.pipe: t]
external observeSelections: (Selection.t => unit) => Disposable.t =
  "observeSelections";

/* onDidAddSelection */
[@bs.send.pipe: t]
external onDidAddSelection: (Selection.t => unit) => Disposable.t =
  "onDidAddSelection";

/* onDidRemoveSelection */
[@bs.send.pipe: t]
external onDidRemoveSelection: (Selection.t => unit) => Disposable.t =
  "onDidRemoveSelection";

/* observeDecorations */
[@bs.send.pipe: t]
external observeDecorations: (Decoration.t => unit) => Disposable.t =
  "observeDecorations";

/* onDidAddDecoration */
[@bs.send.pipe: t]
external onDidAddDecoration: (Decoration.t => unit) => Disposable.t =
  "onDidAddDecoration";

/* onDidRemoveDecoration */
[@bs.send.pipe: t]
external onDidRemoveDecoration: (Decoration.t => unit) => Disposable.t =
  "onDidRemoveDecoration";

/* onDidChangePlaceholderText */
[@bs.send.pipe: t]
external onDidChangePlaceholderText: (string => unit) => Disposable.t =
  "onDidChangePlaceholderText";

/*************************************************************************************************************
  Buffer
 ************************************************************************************************************/

/* getBuffer */
[@bs.send.pipe: t] external getBuffer: TextBuffer.t = "getBuffer";

/*************************************************************************************************************
  File Details
 ************************************************************************************************************/

/* getTitle */
[@bs.send.pipe: t] external getTitle: string = "getTitle";

/* getLongTitle */
[@bs.send.pipe: t] external getLongTitle: string = "getLongTitle";

/* getPath */
[@bs.send.pipe: t] external getPath: option(string) = "getPath";

/* isModified */
[@bs.send.pipe: t] external isModified: bool = "isModified";

/* isEmpty */
[@bs.send.pipe: t] external isEmpty: bool = "isEmpty";

/* isMini */
[@bs.send.pipe: t] external isMini: bool = "isMini";

/* getEncoding */
[@bs.send.pipe: t] external getEncoding: string = "getEncoding";

/* setEncoding */
[@bs.send.pipe: t] external setEncoding: string => unit = "setEncoding";

/*************************************************************************************************************
  File Operations
 ************************************************************************************************************/

/* save */
[@bs.send.pipe: t] external save: Js.Promise.t(unit) = "save";

/* saveAs */
[@bs.send.pipe: t] external saveAs: string => Js.Promise.t(unit) = "saveAs";

/*************************************************************************************************************
  Reading Text
 ************************************************************************************************************/

/* getText */
[@bs.send.pipe: t] external getText: string = "getText";

/* getTextInBufferRange */
[@bs.send.pipe: t]
external getTextInBufferRange: Range.t => string = "getTextInBufferRange";

/* getLineCount */
[@bs.send.pipe: t] external getLineCount: int = "getLineCount";

/* getScreenLineCount */
[@bs.send.pipe: t] external getScreenLineCount: int = "getScreenLineCount";

/* getLastBufferRow */
[@bs.send.pipe: t] external getLastBufferRow: int = "getLastBufferRow";

/* getLastScreenRow */
[@bs.send.pipe: t] external getLastScreenRow: int = "getLastScreenRow";

/* lineTextForBufferRow */
[@bs.send.pipe: t]
external lineTextForBufferRow: int => string = "lineTextForBufferRow";

/* lineTextForScreenRow */
[@bs.send.pipe: t]
external lineTextForScreenRow: int => string = "lineTextForScreenRow";

/* getCurrentParagraphBufferRange */
[@bs.send.pipe: t]
external getCurrentParagraphBufferRange: Range.t =
  "getCurrentParagraphBufferRange";

/*************************************************************************************************************
  Mutating Text
 ************************************************************************************************************/

/* setText */
[@bs.send.pipe: t] external setText: string => unit = "setText";

[@bs.send.pipe: t]
external setText_: (string, {. "bypassReadOnly": bool}) => unit = "setText";

/* setTextInBufferRange */
[@bs.send.pipe: t]
external setTextInBufferRange: (Range.t, string) => Range.t =
  "setTextInBufferRange";

[@bs.send.pipe: t]
external setTextInBufferRange_:
  (
    Range.t,
    string,
    {
      .
      "normalizeLineEndings": bool,
      "bypassReadOnly": bool,
    }
  ) =>
  Range.t =
  "setTextInBufferRange";

/* insertText */
[@bs.send.pipe: t] external insertText: string => Range.t = "insertText";

[@bs.send.pipe: t]
external insertText_: (string, Atom__Selection.insertTextOptions) => Range.t =
  "insertText";

/* insertNewline */
[@bs.send.pipe: t] external insertNewline: unit = "insertNewline";

[@bs.send.pipe: t]
external insertNewline_: {. "bypassReadOnly": bool} => unit = "insertNewline";

/* delete */
[@bs.send.pipe: t] external delete: unit = "delete";

[@bs.send.pipe: t]
external delete_: {. "bypassReadOnly": bool} => unit = "delete";

/* backspace */
[@bs.send.pipe: t] external backspace: unit = "backspace";

[@bs.send.pipe: t]
external backspace_: {. "bypassReadOnly": bool} => unit = "backspace";

/* mutateSelectedText */
[@bs.send.pipe: t]
external mutateSelectedText: ((Selection.t, int) => unit) => unit =
  "mutateSelectedText";

/* transpose */
[@bs.send.pipe: t] external transpose: unit = "transpose";

[@bs.send.pipe: t]
external transpose_: {. "bypassReadOnly": bool} => unit = "transpose";

/* upperCase */
[@bs.send.pipe: t] external upperCase: unit = "upperCase";

[@bs.send.pipe: t]
external upperCase_: {. "bypassReadOnly": bool} => unit = "upperCase";

/* lowerCase */
[@bs.send.pipe: t] external lowerCase: unit = "lowerCase";

[@bs.send.pipe: t]
external lowerCase_: {. "bypassReadOnly": bool} => unit = "lowerCase";

/* toggleLineCommentsInSelection */
[@bs.send.pipe: t]
external toggleLineCommentsInSelection: unit = "toggleLineCommentsInSelection";

[@bs.send.pipe: t]
external toggleLineCommentsInSelection_: {. "bypassReadOnly": bool} => unit =
  "toggleLineCommentsInSelection";

/* insertNewlineBelow */
[@bs.send.pipe: t] external insertNewlineBelow: unit = "insertNewlineBelow";

[@bs.send.pipe: t]
external insertNewlineBelow_: {. "bypassReadOnly": bool} => unit =
  "insertNewlineBelow";

/* insertNewlineAbove */
[@bs.send.pipe: t] external insertNewlineAbove: unit = "insertNewlineAbove";

[@bs.send.pipe: t]
external insertNewlineAbove_: {. "bypassReadOnly": bool} => unit =
  "insertNewlineAbove";

/* deleteToBeginningOfWord */
[@bs.send.pipe: t]
external deleteToBeginningOfWord: unit = "deleteToBeginningOfWord";

[@bs.send.pipe: t]
external deleteToBeginningOfWord_: {. "bypassReadOnly": bool} => unit =
  "deleteToBeginningOfWord";

/* deleteToPreviousWordBoundary */
[@bs.send.pipe: t]
external deleteToPreviousWordBoundary: unit = "deleteToPreviousWordBoundary";

[@bs.send.pipe: t]
external deleteToPreviousWordBoundary_: {. "bypassReadOnly": bool} => unit =
  "deleteToPreviousWordBoundary";

/* deleteToNextWordBoundary */
[@bs.send.pipe: t]
external deleteToNextWordBoundary: unit = "deleteToNextWordBoundary";

[@bs.send.pipe: t]
external deleteToNextWordBoundary_: {. "bypassReadOnly": bool} => unit =
  "deleteToNextWordBoundary";

/* deleteToBeginningOfSubword */
[@bs.send.pipe: t]
external deleteToBeginningOfSubword: unit = "deleteToBeginningOfSubword";

[@bs.send.pipe: t]
external deleteToBeginningOfSubword_: {. "bypassReadOnly": bool} => unit =
  "deleteToBeginningOfSubword";

/* deleteToEndOfSubword */
[@bs.send.pipe: t]
external deleteToEndOfSubword: unit = "deleteToEndOfSubword";

[@bs.send.pipe: t]
external deleteToEndOfSubword_: {. "bypassReadOnly": bool} => unit =
  "deleteToEndOfSubword";

/* deleteToBeginningOfLine */
[@bs.send.pipe: t]
external deleteToBeginningOfLine: unit = "deleteToBeginningOfLine";

[@bs.send.pipe: t]
external deleteToBeginningOfLine_: {. "bypassReadOnly": bool} => unit =
  "deleteToBeginningOfLine";

/* deleteToEndOfLine */
[@bs.send.pipe: t] external deleteToEndOfLine: unit = "deleteToEndOfLine";

[@bs.send.pipe: t]
external deleteToEndOfLine_: {. "bypassReadOnly": bool} => unit =
  "deleteToEndOfLine";

/* deleteToEndOfWord */
[@bs.send.pipe: t] external deleteToEndOfWord: unit = "deleteToEndOfWord";

[@bs.send.pipe: t]
external deleteToEndOfWord_: {. "bypassReadOnly": bool} => unit =
  "deleteToEndOfWord";

/* deleteLine */
[@bs.send.pipe: t] external deleteLine: unit = "deleteLine";

[@bs.send.pipe: t]
external deleteLine_: {. "bypassReadOnly": bool} => unit = "deleteLine";

/*************************************************************************************************************
  History
 ************************************************************************************************************/

/* undo */
[@bs.send.pipe: t] external undo: unit = "undo";

[@bs.send.pipe: t] external undo_: {. bypassReadOnly: bool} => unit = "undo";

/* redo */
[@bs.send.pipe: t] external redo: unit = "redo";

[@bs.send.pipe: t] external redo_: {. bypassReadOnly: bool} => unit = "redo";

/* transact */
[@bs.send.pipe: t] external transact: (unit => 'a) => option('a) = "transact";

[@bs.send.pipe: t]
external transact_: (int, unit => 'a) => option('a) = "transact";

/* abortTransaction */
[@bs.send.pipe: t] external abortTransaction: unit = "abortTransaction";

/* createCheckpoint */
[@bs.send.pipe: t] external createCheckpoint: int = "createCheckpoint";

/* revertToCheckpoint */
[@bs.send.pipe: t]
external revertToCheckpoint: int => bool = "revertToCheckpoint";

/* groupChangesSinceCheckpoint */
[@bs.send.pipe: t]
external groupChangesSinceCheckpoint: int => bool =
  "groupChangesSinceCheckpoint";

/*************************************************************************************************************
  TextEditor Coordinates
 ************************************************************************************************************/

/* screenPositionForBufferPosition */
[@bs.send.pipe: t]
external screenPositionForBufferPosition: Point.t => Point.t =
  "screenPositionForBufferPosition";

[@bs.send.pipe: t]
external screenPositionForBufferPosition_:
  (Point.t, {. "clipDirection": string}) => Point.t =
  "screenPositionForBufferPosition";

/* bufferPositionForScreenPosition */
[@bs.send.pipe: t]
external bufferPositionForScreenPosition: Point.t => Point.t =
  "bufferPositionForScreenPosition";

[@bs.send.pipe: t]
external bufferPositionForScreenPosition_:
  (Point.t, {. "clipDirection": string}) => Point.t =
  "bufferPositionForScreenPosition";

/* screenRangeForBufferRange */
[@bs.send.pipe: t]
external screenRangeForBufferRange: Range.t => Range.t =
  "screenRangeForBufferRange";

/* bufferRangeForScreenRange */
[@bs.send.pipe: t]
external bufferRangeForScreenRange: Range.t => Range.t =
  "bufferRangeForScreenRange";

/* clipBufferPosition */
[@bs.send.pipe: t]
external clipBufferPosition: Point.t => Point.t = "clipBufferPosition";

/* clipBufferRange */
[@bs.send.pipe: t]
external clipBufferRange: Range.t => Range.t = "clipBufferRange";

/* clipScreenPosition */
[@bs.send.pipe: t]
external clipScreenPosition: Point.t => Point.t = "clipScreenPosition";

[@bs.send.pipe: t]
external clipScreenPosition_:
  (Point.t, {. "clipDirection": string}) => Point.t =
  "clipScreenPosition";

/* clipScreenRange */
[@bs.send.pipe: t]
external clipScreenRange: Range.t => Range.t = "clipScreenRange";

[@bs.send.pipe: t]
external clipScreenRange_: (Range.t, {. "clipDirection": string}) => Range.t =
  "clipScreenRange";

/*************************************************************************************************************
  Decoration
 ************************************************************************************************************/

type decorateMarkerOptions = {
  .
  "type": string,
  "class": string,
  "style": Js.t({.}),
};

type extendedDecorateMarkerOptions = {
  .
  "type": string,
  "class": string,
  "style": Js.t({.}),
  "item": Dom.htmlElement,
  "onlyHead": bool,
  "onlyEmpty": bool,
  "onlyNonEmpty": bool,
  "omitEmptyLastRow": bool,
  "position": string,
  "order": option(int),
  "avoidOverflow": bool,
};

/* decorateMarker */
[@bs.send.pipe: t]
external decorateMarker:
  (DisplayMarker.t, decorateMarkerOptions) => Decoration.t =
  "decorateMarker";

[@bs.send.pipe: t]
external decorateMarker_:
  (DisplayMarker.t, extendedDecorateMarkerOptions) => Decoration.t =
  "decorateMarker";

/* decorateMarkerLayer */
[@bs.send.pipe: t]
external decorateMarkerLayer:
  (MarkerLayer.t, decorateMarkerOptions) => LayerDecoration.t =
  "decorateMarkerLayer";

[@bs.send.pipe: t]
external decorateMarkerLayer_:
  (MarkerLayer.t, extendedDecorateMarkerOptions) => LayerDecoration.t =
  "decorateMarkerLayer";

[@bs.send.pipe: t]
external decorateDisplayMarkerLayer:
  (DisplayMarkerLayer.t, decorateMarkerOptions) => LayerDecoration.t =
  "decorateMarkerLayer";

[@bs.send.pipe: t]
external decorateDisplayMarkerLayer_:
  (DisplayMarkerLayer.t, extendedDecorateMarkerOptions) => LayerDecoration.t =
  "decorateMarkerLayer";

/* getDecorations */
[@bs.send.pipe: t]
external getDecorations: Js.t({.}) => array(Decoration.t) = "getDecorations";

/* getLineDecorations */
[@bs.send.pipe: t]
external getLineDecorations: Js.t({.}) => array(Decoration.t) =
  "getLineDecorations";

/* getLineNumberDecorations */
[@bs.send.pipe: t]
external getLineNumberDecorations: Js.t({.}) => array(Decoration.t) =
  "getLineNumberDecorations";

/* getHighlightDecorations */
[@bs.send.pipe: t]
external getHighlightDecorations: Js.t({.}) => array(Decoration.t) =
  "getHighlightDecorations";

/* getOverlayDecorations */
[@bs.send.pipe: t]
external getOverlayDecorations: Js.t({.}) => array(Decoration.t) =
  "getOverlayDecorations";

/*************************************************************************************************************
 Markers
 ************************************************************************************************************/

/* markBufferRange */
[@bs.send.pipe: t]
external markBufferRange: Range.t => DisplayMarker.t = "markBufferRange";

[@bs.send.pipe: t]
external markBufferRange_:
  (
    Range.t,
    {
      .
      "maintainHistory": bool,
      "reversed": bool,
      "invalidate": string,
    }
  ) =>
  DisplayMarker.t =
  "markBufferRange";

/* markScreenRange */
[@bs.send.pipe: t]
external markScreenRange: Range.t => DisplayMarker.t = "markScreenRange";

[@bs.send.pipe: t]
external markScreenRange_:
  (
    Range.t,
    {
      .
      "maintainHistory": bool,
      "reversed": bool,
      "invalidate": string,
    }
  ) =>
  DisplayMarker.t =
  "markScreenRange";

/* markBufferPosition */
[@bs.send.pipe: t]
external markBufferPosition: Point.t => DisplayMarker.t = "markBufferPosition";

[@bs.send.pipe: t]
external markBufferPosition_:
  (Point.t, {. "invalidate": string}) => DisplayMarker.t =
  "markBufferPosition";

/* markScreenPosition */
[@bs.send.pipe: t]
external markScreenPosition: Point.t => DisplayMarker.t = "markScreenPosition";

[@bs.send.pipe: t]
external markScreenPosition_:
  (
    Point.t,
    {
      .
      "invalidate": string,
      "clipDirection": string,
    }
  ) =>
  DisplayMarker.t =
  "markScreenPosition";

/* findMarkers */
[@bs.send.pipe: t]
external findMarkers:
  {
    .
    "startBufferRow": int,
    "endBufferRow": int,
    "containsBufferRange": Range.t,
    "containsBufferPosition": Range.t,
  } =>
  array(DisplayMarker.t) =
  "findMarkers";

/* addMarkerLayer */
[@bs.send.pipe: t]
external addMarkerLayer:
  {
    .
    "maintainHistory": bool,
    "persistent": bool,
  } =>
  DisplayMarkerLayer.t =
  "addMarkerLayer";

/* getMarkerLayer */
[@bs.send.pipe: t]
external getMarkerLayer: int => option(DisplayMarkerLayer.t) =
  "getMarkerLayer";

/* getDefaultMarkerLayer */
[@bs.send.pipe: t]
external getDefaultMarkerLayer: DisplayMarkerLayer.t = "getDefaultMarkerLayer";

/* getMarker */
[@bs.send.pipe: t]
external getMarker: int => option(DisplayMarker.t) = "getMarker";

/* getMarkers */
[@bs.send.pipe: t] external getMarkers: array(DisplayMarker.t) = "getMarkers";

/* getMarkerCount */
[@bs.send.pipe: t] external getMarkerCount: int = "getMarkerCount";

/*************************************************************************************************************
 Markers
 ************************************************************************************************************/

/* getCursorBufferPosition */
[@bs.send.pipe: t]
external getCursorBufferPosition: Point.t = "getCursorBufferPosition";

/* getCursorBufferPositions */
[@bs.send.pipe: t]
external getCursorBufferPositions: array(Point.t) =
  "getCursorBufferPositions";

/* setCursorBufferPosition */
[@bs.send.pipe: t]
external setCursorBufferPosition: Point.t => unit = "setCursorBufferPosition";

[@bs.send.pipe: t]
external setCursorBufferPosition_: (Point.t, {. "autoScroll": bool}) => unit =
  "setCursorBufferPosition";

/* getCursorAtScreenPosition */
[@bs.send.pipe: t]
external getCursorAtScreenPosition: Point.t => option(Cursor.t) =
  "getCursorAtScreenPosition";

/* getCursorScreenPosition */
[@bs.send.pipe: t]
external getCursorScreenPosition: Point.t = "getCursorScreenPosition";

/* getCursorScreenPositions */
[@bs.send.pipe: t]
external getCursorScreenPositions: array(Point.t) =
  "getCursorScreenPositions";

/* setCursorScreenPosition */
[@bs.send.pipe: t]
external setCursorScreenPosition: Point.t => unit = "setCursorScreenPosition";

[@bs.send.pipe: t]
external setCursorScreenPosition_: (Point.t, {. "autoScroll": bool}) => unit =
  "setCursorScreenPosition";

/* addCursorAtBufferPosition */
[@bs.send.pipe: t]
external addCursorAtBufferPosition: Point.t => Cursor.t =
  "addCursorAtBufferPosition";

/* addCursorAtScreenPosition */
[@bs.send.pipe: t]
external addCursorAtScreenPosition: Point.t => Cursor.t =
  "addCursorAtScreenPosition";

/* hasMultipleCursors */
[@bs.send.pipe: t] external hasMultipleCursors: bool = "hasMultipleCursors";

/* moveUp */
[@bs.send.pipe: t] external moveUp: unit = "moveUp";

[@bs.send.pipe: t] external moveUpBy: int => unit = "moveUp";

/* moveDown */
[@bs.send.pipe: t] external moveDown: unit = "moveDown";

[@bs.send.pipe: t] external moveDownBy: int => unit = "moveDown";

/* moveLeft */
[@bs.send.pipe: t] external moveLeft: unit = "moveLeft";

[@bs.send.pipe: t] external moveLeftBy: int => unit = "moveLeft";

/* moveRight */
[@bs.send.pipe: t] external moveRight: unit = "moveRight";

[@bs.send.pipe: t] external moveRightBy: int => unit = "moveRight";

/* moveToBeginningOfLine */
[@bs.send.pipe: t]
external moveToBeginningOfLine: unit = "moveToBeginningOfLine";

/* moveToBeginningOfScreenLine */
[@bs.send.pipe: t]
external moveToBeginningOfScreenLine: unit = "moveToBeginningOfScreenLine";

/* moveToFirstCharacterOfLine */
[@bs.send.pipe: t]
external moveToFirstCharacterOfLine: unit = "moveToFirstCharacterOfLine";

/* moveToEndOfLine */
[@bs.send.pipe: t] external moveToEndOfLine: unit = "moveToEndOfLine";

/* moveToEndOfScreenLine */
[@bs.send.pipe: t]
external moveToEndOfScreenLine: unit = "moveToEndOfScreenLine";

/* moveToBeginningOfWord */
[@bs.send.pipe: t]
external moveToBeginningOfWord: unit = "moveToBeginningOfWord";

/* moveToEndOfWord */
[@bs.send.pipe: t] external moveToEndOfWord: unit = "moveToEndOfWord";

/* moveToTop */
[@bs.send.pipe: t] external moveToTop: unit = "moveToTop";

/* moveToBottom */
[@bs.send.pipe: t] external moveToBottom: unit = "moveToBottom";

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

/* moveToBeginningOfNextParagraph */
[@bs.send.pipe: t]
external moveToBeginningOfNextParagraph: unit =
  "moveToBeginningOfNextParagraph";

/* moveToBeginningOfPreviousParagraph */
[@bs.send.pipe: t]
external moveToBeginningOfPreviousParagraph: unit =
  "moveToBeginningOfPreviousParagraph";

/* getLastCursor */
[@bs.send.pipe: t] external getLastCursor: option(Cursor.t) = "getLastCursor";

/* getWordUnderCursor */
[@bs.send.pipe: t] external getWordUnderCursor: string = "getWordUnderCursor";

[@bs.send.pipe: t]
external getWordUnderCursor_:
  {
    .
    "wordRegex": Js.Re.t,
    "includeNonWordCharacters": bool,
    "allowPrevious": bool,
  } =>
  string =
  "getWordUnderCursor";

/* getCursors */
[@bs.send.pipe: t] external getCursors: array(Cursor.t) = "getCursors";

/* getCursorsOrderedByBufferPosition */
[@bs.send.pipe: t]
external getCursorsOrderedByBufferPosition: array(Selection.t) =
  "getCursorsOrderedByBufferPosition";

/*************************************************************************************************************
 Selections
 ************************************************************************************************************/

/* getSelectedText */
[@bs.send.pipe: t] external getSelectedText: string = "getSelectedText";

/* getSelectedBufferRange */
[@bs.send.pipe: t]
external getSelectedBufferRange: Range.t = "getSelectedBufferRange";

/* getSelectedBufferRanges */
[@bs.send.pipe: t]
external getSelectedBufferRanges: array(Range.t) = "getSelectedBufferRanges";

/* setSelectedBufferRange */
[@bs.send.pipe: t]
external setSelectedBufferRange: Range.t => unit = "setSelectedBufferRange";

[@bs.send.pipe: t]
external setSelectedBufferRange_:
  (
    Range.t,
    {
      .
      "reversed": bool,
      "preserveFolds": bool,
    }
  ) =>
  unit =
  "setSelectedBufferRange";

/* setSelectedBufferRanges */
[@bs.send.pipe: t]
external setSelectedBufferRanges: array(Range.t) => unit =
  "setSelectedBufferRanges";

[@bs.send.pipe: t]
external setSelectedBufferRanges_:
  (
    array(Range.t),
    {
      .
      "reversed": bool,
      "preserveFolds": bool,
    }
  ) =>
  unit =
  "setSelectedBufferRanges";

/* getSelectedScreenRange */
[@bs.send.pipe: t]
external getSelectedScreenRange: Range.t = "getSelectedScreenRange";

/* getSelectedScreenRanges */
[@bs.send.pipe: t]
external getSelectedScreenRanges: array(Range.t) = "getSelectedScreenRanges";

/* setSelectedScreenRange */
[@bs.send.pipe: t]
external setSelectedScreenRange: Range.t => unit = "setSelectedScreenRange";

[@bs.send.pipe: t]
external setSelectedScreenRange_: (Range.t, {. "reversed": bool}) => unit =
  "setSelectedScreenRange";

/* setSelectedScreenRanges */
[@bs.send.pipe: t]
external setSelectedScreenRanges: array(Range.t) => unit =
  "setSelectedScreenRanges";

[@bs.send.pipe: t]
external setSelectedScreenRanges_:
  (array(Range.t), {. "reversed": bool}) => unit =
  "setSelectedScreenRanges";

/* addSelectionForBufferRange */
[@bs.send.pipe: t]
external addSelectionForBufferRange: Range.t => Selection.t =
  "addSelectionForBufferRange";

[@bs.send.pipe: t]
external addSelectionForBufferRange_:
  (
    Range.t,
    {
      .
      "reversed": bool,
      "preserveFolds": bool,
    }
  ) =>
  Selection.t =
  "addSelectionForBufferRange";

/* addSelectionForScreenRange */
[@bs.send.pipe: t]
external addSelectionForScreenRange: Range.t => Selection.t =
  "addSelectionForScreenRange";

[@bs.send.pipe: t]
external addSelectionForScreenRange_:
  (
    Range.t,
    {
      .
      "reversed": bool,
      "preserveFolds": bool,
    }
  ) =>
  Selection.t =
  "addSelectionForScreenRange";

/* selectToBufferPosition */
[@bs.send.pipe: t]
external selectToBufferPosition: Point.t => Selection.t =
  "selectToBufferPosition";

/* selectToScreenPosition */
[@bs.send.pipe: t]
external selectToScreenPosition: Point.t => Selection.t =
  "selectToScreenPosition";

/* selectUp */
[@bs.send.pipe: t] external selectUp: int => Selection.t = "selectUp";

/* selectDown */
[@bs.send.pipe: t] external selectDown: int => Selection.t = "selectDown";

/* selectLeft */
[@bs.send.pipe: t] external selectLeft: int => Selection.t = "selectLeft";

/* selectRight */
[@bs.send.pipe: t] external selectRight: int => Selection.t = "selectRight";

/* selectToTop */
[@bs.send.pipe: t] external selectToTop: Selection.t = "selectToTop";

/* selectToBottom */
[@bs.send.pipe: t] external selectToBottom: Selection.t = "selectToBottom";

/* selectAll */
[@bs.send.pipe: t] external selectAll: Selection.t = "selectAll";

/* selectToBeginningOfLine */
[@bs.send.pipe: t]
external selectToBeginningOfLine: Selection.t = "selectToBeginningOfLine";

/* selectToFirstCharacterOfLine */
[@bs.send.pipe: t]
external selectToFirstCharacterOfLine: Selection.t =
  "selectToFirstCharacterOfLine";

/* selectToEndOfLine */
[@bs.send.pipe: t]
external selectToEndOfLine: Selection.t = "selectToEndOfLine";

/* selectToBeginningOfWord */
[@bs.send.pipe: t]
external selectToBeginningOfWord: Selection.t = "selectToBeginningOfWord";

/* selectToEndOfWord */
[@bs.send.pipe: t]
external selectToEndOfWord: Selection.t = "selectToEndOfWord";

/* selectLinesContainingCursors */
[@bs.send.pipe: t]
external selectLinesContainingCursors: Selection.t =
  "selectLinesContainingCursors";

/* selectWordsContainingCursors */
[@bs.send.pipe: t]
external selectWordsContainingCursors: Selection.t =
  "selectWordsContainingCursors";

/* selectToPreviousSubwordBoundary */
[@bs.send.pipe: t]
external selectToPreviousSubwordBoundary: Selection.t =
  "selectToPreviousSubwordBoundary";

/* selectToNextSubwordBoundary */
[@bs.send.pipe: t]
external selectToNextSubwordBoundary: Selection.t =
  "selectToNextSubwordBoundary";

/* selectToPreviousWordBoundary */
[@bs.send.pipe: t]
external selectToPreviousWordBoundary: Selection.t =
  "selectToPreviousWordBoundary";

/* selectToNextWordBoundary */
[@bs.send.pipe: t]
external selectToNextWordBoundary: Selection.t = "selectToNextWordBoundary";

/* selectToBeginningOfNextWord */
[@bs.send.pipe: t]
external selectToBeginningOfNextWord: Selection.t =
  "selectToBeginningOfNextWord";

/* selectToBeginningOfNextParagraph */
[@bs.send.pipe: t]
external selectToBeginningOfNextParagraph: Selection.t =
  "selectToBeginningOfNextParagraph";

/* selectToBeginningOfPreviousParagraph */
[@bs.send.pipe: t]
external selectToBeginningOfPreviousParagraph: Selection.t =
  "selectToBeginningOfPreviousParagraph";

/* selectLargerSyntaxNode */
[@bs.send.pipe: t]
external selectLargerSyntaxNode: Selection.t = "selectLargerSyntaxNode";

/* selectSmallerSyntaxNode */
[@bs.send.pipe: t]
external selectSmallerSyntaxNode: Selection.t = "selectSmallerSyntaxNode";

/* selectMarker */
[@bs.send.pipe: t]
external selectMarker: DisplayMarker.t => option(Range.t) = "selectMarker";

/* getLastSelection */
[@bs.send.pipe: t] external getLastSelection: Selection.t = "getLastSelection";

/* getSelections */
[@bs.send.pipe: t]
external getSelections: array(Selection.t) = "getSelections";

/* getSelectionsOrderedByBufferPosition */
[@bs.send.pipe: t]
external getSelectionsOrderedByBufferPosition: array(Selection.t) =
  "getSelectionsOrderedByBufferPosition";

/* selectionIntersectsBufferRange */
[@bs.send.pipe: t]
external selectionIntersectsBufferRange: Range.t => bool =
  "selectionIntersectsBufferRange";

/*************************************************************************************************************
 Searching and Replacing
 ************************************************************************************************************/

type iterator =
  {
    .
    "match": Js.t({.}),
    "matchText": string,
    "range": Range.t,
    [@bs.meth] "stop": unit => unit,
    [@bs.meth] "replace": string => unit,
  } =>
  unit;

/* scan */
[@bs.send.pipe: t] external scan: (Js.Re.t, iterator) => unit = "scan";

[@bs.send.pipe: t]
external scan_:
  (
    Js.Re.t,
    {
      .
      "leadingContextLineCount": int,
      "trailingContextLineCount": int,
    },
    iterator
  ) =>
  unit =
  "scan";

/* scanInBufferRange */
[@bs.send.pipe: t]
external scanInBufferRange: (Js.Re.t, Range.t, iterator) => unit =
  "scanInBufferRange";

/* backwardsScanInBufferRange */
[@bs.send.pipe: t]
external backwardsScanInBufferRange: (Js.Re.t, Range.t, iterator) => unit =
  "backwardsScanInBufferRange";

/*************************************************************************************************************
 Tab Behavior
 ************************************************************************************************************/

/* getSoftTabs */
[@bs.send.pipe: t] external getSoftTabs: bool = "getSoftTabs";

/* setSoftTabs */
[@bs.send.pipe: t] external setSoftTabs: bool => unit = "setSoftTabs";

/* toggleSoftTabs */
[@bs.send.pipe: t] external toggleSoftTabs: unit = "toggleSoftTabs";

/* getTabLength */
[@bs.send.pipe: t] external getTabLength: int = "getTabLength";

/* setTabLength */
[@bs.send.pipe: t] external setTabLength: int => unit = "setTabLength";

/* usesSoftTabs */
[@bs.send.pipe: t] external usesSoftTabs: option(bool) = "usesSoftTabs";

/* getTabText */
[@bs.send.pipe: t] external getTabText: string = "getTabText";

/*************************************************************************************************************
 Soft Wrap Behavior
 ************************************************************************************************************/

/* isSoftWrapped */
[@bs.send.pipe: t] external isSoftWrapped: bool = "isSoftWrapped";

/* setSoftWrapped */
[@bs.send.pipe: t] external setSoftWrapped: bool => bool = "setSoftWrapped";

/* toggleSoftWrapped */
[@bs.send.pipe: t]
external toggleSoftWrapped: unit => unit = "toggleSoftWrapped";

/* getSoftWrapColumn */
[@bs.send.pipe: t] external getSoftWrapColumn: int = "getSoftWrapColumn";

/*************************************************************************************************************
 Indentation
 ************************************************************************************************************/

/* indentationForBufferRow */
[@bs.send.pipe: t]
external indentationForBufferRow: int => int = "indentationForBufferRow";

/* setIndentationForBufferRow */
[@bs.send.pipe: t]
external setIndentationForBufferRow: (int, int) => unit =
  "setIndentationForBufferRow";

[@bs.send.pipe: t]
external setIndentationForBufferRow_:
  (int, int, {. "preserveLeadingWhitespace": bool}) => unit =
  "setIndentationForBufferRow";

/* indentSelectedRows */
[@bs.send.pipe: t] external indentSelectedRows: unit = "indentSelectedRows";

[@bs.send.pipe: t]
external indentSelectedRows_: {. "bypassReadOnly": bool} => unit =
  "indentSelectedRows";

/* outdentSelectedRows */
[@bs.send.pipe: t] external outdentSelectedRows: unit = "outdentSelectedRows";

[@bs.send.pipe: t]
external outdentSelectedRows_: {. "bypassReadOnly": bool} => unit =
  "outdentSelectedRows";

/* indentLevelForLine */
[@bs.send.pipe: t]
external indentLevelForLine: string => int = "indentLevelForLine";

/* autoIndentSelectedRows */
[@bs.send.pipe: t]
external autoIndentSelectedRows: unit = "autoIndentSelectedRows";

[@bs.send.pipe: t]
external autoIndentSelectedRows_: {. "bypassReadOnly": bool} => unit =
  "autoIndentSelectedRows";

/*************************************************************************************************************
 Grammars
 ************************************************************************************************************/

/* getGrammar */
[@bs.send.pipe: t] external getGrammar: Grammar.t = "getGrammar";

// deprecated
/* setGrammar */
[@bs.send.pipe: t] external setGrammar: Grammar.t => unit = "setGrammar";

/*************************************************************************************************************
 Managing Syntax Scopes
 ************************************************************************************************************/

/* getRootScopeDescriptor */
[@bs.send.pipe: t]
external getRootScopeDescriptor: ScopeDescriptor.t = "getRootScopeDescriptor";

/* scopeDescriptorForBufferPosition */
[@bs.send.pipe: t]
external scopeDescriptorForBufferPosition: Point.t => ScopeDescriptor.t =
  "scopeDescriptorForBufferPosition";

/* syntaxTreeScopeDescriptorForBufferPosition */
[@bs.send.pipe: t]
external syntaxTreeScopeDescriptorForBufferPosition:
  Point.t => ScopeDescriptor.t =
  "syntaxTreeScopeDescriptorForBufferPosition";

/* bufferRangeForScopeAtCursor */
[@bs.send.pipe: t]
external bufferRangeForScopeAtCursor: string => Range.t =
  "bufferRangeForScopeAtCursor";

/* isBufferRowCommented */
[@bs.send.pipe: t]
external isBufferRowCommented: bool = "isBufferRowCommented";

/*************************************************************************************************************
 Clipboard Operations
 ************************************************************************************************************/

/* copySelectedText */
[@bs.send.pipe: t] external copySelectedText: unit = "copySelectedText";

/* cutSelectedText */
[@bs.send.pipe: t] external cutSelectedText: unit = "cutSelectedText";

[@bs.send.pipe: t]
external cutSelectedText_: {. "bypassReadOnly": bool} => unit =
  "cutSelectedText";

/* pasteText */
[@bs.send.pipe: t] external pasteText: unit = "pasteText";

[@bs.send.pipe: t]
external pasteText_: Atom__Selection.insertTextOptions => unit = "pasteText";

/* cutToEndOfLine */
[@bs.send.pipe: t] external cutToEndOfLine: unit = "cutToEndOfLine";

[@bs.send.pipe: t]
external cutToEndOfLine_: {. "bypassReadOnly": bool} => unit =
  "cutToEndOfLine";

/* cutToEndOfBufferLine */
[@bs.send.pipe: t]
external cutToEndOfBufferLine: unit = "cutToEndOfBufferLine";

[@bs.send.pipe: t]
external cutToEndOfBufferLine_: {. "bypassReadOnly": bool} => unit =
  "cutToEndOfBufferLine";

/*************************************************************************************************************
 Folds
 ************************************************************************************************************/

/* foldCurrentRow */
[@bs.send.pipe: t] external foldCurrentRow: unit = "foldCurrentRow";

/* unfoldCurrentRow */
[@bs.send.pipe: t] external unfoldCurrentRow: unit = "unfoldCurrentRow";

/* foldBufferRow */
[@bs.send.pipe: t] external foldBufferRow: int => unit = "foldBufferRow";

/* unfoldBufferRow */
[@bs.send.pipe: t] external unfoldBufferRow: int => unit = "unfoldBufferRow";

/* foldSelectedLines */
[@bs.send.pipe: t] external foldSelectedLines: unit = "foldSelectedLines";

/* foldAll */
[@bs.send.pipe: t] external foldAll: unit = "foldAll";

/* unfoldAll */
[@bs.send.pipe: t] external unfoldAll: unit = "unfoldAll";

/* foldAllAtIndentLevel */
[@bs.send.pipe: t]
external foldAllAtIndentLevel: int => unit = "foldAllAtIndentLevel";

/* isFoldableAtBufferRow */
[@bs.send.pipe: t]
external isFoldableAtBufferRow: int => bool = "isFoldableAtBufferRow";

/* isFoldableAtScreenRow */
[@bs.send.pipe: t]
external isFoldableAtScreenRow: int => bool = "isFoldableAtScreenRow";

/* toggleFoldAtBufferRow */
[@bs.send.pipe: t]
external toggleFoldAtBufferRow: bool = "toggleFoldAtBufferRow";

/* isFoldedAtCursorRow */
[@bs.send.pipe: t] external isFoldedAtCursorRow: bool = "isFoldedAtCursorRow";

/* isFoldedAtBufferRow */
[@bs.send.pipe: t]
external isFoldedAtBufferRow: int => bool = "isFoldedAtBufferRow";

/* isFoldedAtScreenRow */
[@bs.send.pipe: t]
external isFoldedAtScreenRow: int => bool = "isFoldedAtScreenRow";

/*************************************************************************************************************
 Gutters
 ************************************************************************************************************/

/* addGutter */
[@bs.send.pipe: t]
external addGutter:
  {
    .
    "name": string,
    "priority": int,
    "visible": bool,
    "type": string,
    "class": string,
    "labelFn":
      {
        .
        "bufferRow": int,
        "screenRow": int,
        "foldable": bool,
        "softWrapped": bool,
        "maxDigits": int,
      } =>
      string,
    "onMouseDown":
      {
        .
        "bufferRow": int,
        "screenRow": int,
      } =>
      unit,
    "onMouseMove":
      {
        .
        "bufferRow": int,
        "screenRow": int,
      } =>
      unit,
  } =>
  Gutter.t =
  "addGutter";

/* getGutters */
[@bs.send.pipe: t] external getGutters: array(Gutter.t) = "getGutters";

/* gutterWithName */
[@bs.send.pipe: t]
external gutterWithName: string => Js.Nullable.t(Gutter.t) = "gutterWithName";

/*************************************************************************************************************
 Scrolling the TextEditor
 ************************************************************************************************************/

/* scrollToCursorPosition */
[@bs.send.pipe: t]
external scrollToCursorPosition: unit = "scrollToCursorPosition";

[@bs.send.pipe: t]
external scrollToCursorPosition_: {. "center": bool} => unit =
  "scrollToCursorPosition";

/* scrollToBufferPosition */
[@bs.send.pipe: t]
external scrollToBufferPosition: Point.t => unit = "scrollToBufferPosition";

[@bs.send.pipe: t]
external scrollToBufferPosition_: (Point.t, {. "center": bool}) => unit =
  "scrollToBufferPosition";

/* scrollToScreenPosition */
[@bs.send.pipe: t]
external scrollToScreenPosition: Point.t => unit = "scrollToScreenPosition";

[@bs.send.pipe: t]
external scrollToScreenPosition_: (Point.t, {. "center": bool}) => unit =
  "scrollToScreenPosition";

/*************************************************************************************************************
 TextEditor Rendering
 ************************************************************************************************************/

/* getPlaceholderText */
[@bs.send.pipe: t] external getPlaceholderText: string = "getPlaceholderText";

/* setPlaceholderText */
[@bs.send.pipe: t]
external setPlaceholderText: string => unit = "setPlaceholderText";
