open Atom__Type;

include TextEditor;

/* Hack */
[@bs.get] external id: t => int = "id";

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

/* Grammars */
[@bs.send.pipe: t] external setGrammar: Atom__Grammar.t => unit = "";

/* TextEditor Rendering */
[@bs.send.pipe: t] external getPlaceholderText: string = "";

[@bs.send.pipe: t] external setPlaceholderText: string => unit = "";

/* Selections */
[@bs.send.pipe: t] external getSelections: array(Selection.t) = "";

[@bs.send.pipe: t] external getSelectedBufferRange: Range.t = "";

[@bs.send.pipe: t] external getSelectedBufferRanges: array(Range.t) = "";

[@bs.send.pipe: t] external setSelectedBufferRange: Range.t => unit = "";
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

[@bs.send.pipe: t]
external setSelectedBufferRanges: array(Range.t) => unit = "";
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

[@bs.send.pipe: t] external selectAll: unit = "";

/* Searching and Replacing */
/* [@bs.deriving abstract] */
module Scan = {
  type match = {
    .
    "matchText": string,
    "range": Range.t,
    [@bs.meth] "stop": unit => unit,
    [@bs.meth] "replace": string => unit,
  };
};
[@bs.send.pipe: t] external scan: (Js.Re.t, Scan.match => unit) => unit = "";
[@bs.send.pipe: t]
external scanInBufferRange: (Js.Re.t, Range.t, Scan.match => unit) => unit =
  "";

[@bs.send.pipe: t]
external backwardsScanInBufferRange:
  (Js.Re.t, Range.t, Scan.match => unit) => unit =
  "";

/* Decorations */
/* Cursors */
[@bs.send.pipe: t]
external addCursorAtBufferPosition: Point.t => Cursor.t = "";

[@bs.send.pipe: t] external setCursorBufferPosition: Point.t => unit = "";

[@bs.send.pipe: t]
external setCursorBufferPosition_: (Point.t, {. "autoScroll": bool}) => unit =
  "setCursorBufferPosition";

[@bs.send.pipe: t] external getCursorBufferPosition: Point.t = "";

/* Selections */

[@bs.send.pipe: t] external getSelectedText: string = "";
[@bs.send.pipe: t] external getSelectedBufferRange: Range.t = "";
[@bs.send.pipe: t] external getSelectedBufferRanges: array(Range.t) = "";
[@bs.send.pipe: t] external setSelectedBufferRange: Range.t => unit = "";
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
[@bs.send.pipe: t]
external setSelectedBufferRanges: array(Range.t) => unit = "";
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
[@bs.send.pipe: t] external getSelectedScreenRange: Range.t = "";
[@bs.send.pipe: t] external getSelectedScreenRanges: array(Range.t) = "";

[@bs.send.pipe: t] external setSelectedScreenRange: Range.t => unit = "";
[@bs.send.pipe: t]
external setSelectedScreenRange_: (Range.t, {. "reversed": bool}) => unit =
  "setSelectedScreenRange";

[@bs.send.pipe: t]
external setSelectedScreenRanges: array(Range.t) => unit = "";
[@bs.send.pipe: t]
external setSelectedScreenRanges_:
  (array(Range.t), {. "reversed": bool}) => unit =
  "setSelectedScreenRanges";

[@bs.send.pipe: t] external selectLinesContainingCursors: unit = "";
[@bs.send.pipe: t] external selectWordsContainingCursors: unit = "";
[@bs.send.pipe: t] external selectLargerSyntaxNode: unit = "";
[@bs.send.pipe: t] external selectSmallerSyntaxNode: unit = "";
