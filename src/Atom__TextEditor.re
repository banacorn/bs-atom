open Atom__Type;

include TextEditor;

/* Hack */
[@bs.get] external id: t => int = "";

/* Event Subscription */
[@bs.send.pipe: t]
external onDidChangeTitle: (unit => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external onDidChangePath: (unit => unit) => Disposable.t = "";

[@bs.send.pipe: t] external onDidChange: (unit => unit) => Disposable.t = "";

[@bs.send.pipe: t]
external onDidStopChanging: (unit => unit) => Disposable.t = "";

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
  "";

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
  "";

[@bs.send.pipe: t]
external onDidSave: ({. "path": string} => unit) => Disposable.t = "";

[@bs.send.pipe: t] external onDidDestroy: (unit => unit) => Disposable.t = "";

[@bs.send.pipe: t] external getBuffer: TextBuffer.t = "";

[@bs.send.pipe: t] external getCursors: array(Cursor.t) = "";

[@bs.send.pipe: t] external isMini: bool = "";

/* File Details */
[@bs.send.pipe: t] external getTitle: string = "";

[@bs.send.pipe: t] external getLongTitle: string = "";

[@bs.send.pipe: t] external getPath: string = "";

[@bs.send.pipe: t] external isModified: bool = "";

[@bs.send.pipe: t] external isEmpty: bool = "";

/* File Operations */
[@bs.send.pipe: t] external save: Js.Promise.t(unit) = "";
[@bs.send.pipe: t] external saveAs: string => Js.Promise.t(unit) = "";

/* Reading Text */
[@bs.send.pipe: t] external getText: string = "";

[@bs.send.pipe: t] external getTextInBufferRange: Range.t => string = "";

/* Mutating Text */
[@bs.send.pipe: t] external setText: string => unit = "";

[@bs.send.pipe: t]
external setText_: (string, {. "bypassReadOnly": bool}) => unit = "setText";

[@bs.send.pipe: t]
external setTextInBufferRange: (Range.t, string) => Range.t = "";

[@bs.send.pipe: t]
external setTextInBufferRange_:
  (
    t,
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

[@bs.send.pipe: t] external insertText: string => Range.t = "";

[@bs.send.pipe: t]
external insertText_: (string, Atom__Selection.insertTextOption) => Range.t =
  "insertText";

[@bs.send.pipe: t]
external insertNewline: {. "bypassReadOnly": bool} => unit = "";

[@bs.send.pipe: t] external delete: {. "bypassReadOnly": bool} => unit = "";

[@bs.send.pipe: t]
external backspace: {. "bypassReadOnly": bool} => unit = "";

/* Grammars */
[@bs.send.pipe: t] external setGrammar: grammar => unit = "";

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

[@bs.send.pipe: t] external markBufferRange: Range.t => DisplayMarker.t = "";

[@bs.send.pipe: t]
external markBufferRange':
  (
    Range.t,
    {
      .
      "maintainHistory": bool,
      "reversed": bool,
      "invalidate": DisplayMarker.validity,
    }
  ) =>
  DisplayMarker.t =
  "markBufferRange";

[@bs.deriving abstract]
type decorationParams = {
  [@bs.as "type"]
  type_: string,
  [@bs.optional] [@bs.as "class"]
  class_: string,
  [@bs.optional]
  style: Js.t({.}),
  [@bs.optional]
  item: Dom.htmlElement,
  [@bs.optional]
  onlyHead: bool,
  [@bs.optional]
  onlyEmpty: bool,
  [@bs.optional]
  onlyNonEmpty: bool,
  [@bs.optional]
  omitEmptyLastRow: bool,
  [@bs.optional]
  position: string,
  [@bs.optional]
  avoidOverflow: bool,
};

[@bs.send.pipe: t]
external decorateMarker: (DisplayMarker.t, decorationParams) => Decoration.t =
  "";

/* let decorateMarkerLine =
     (
       marker: DisplayMarker.t,
       class_: string,
       ~onlyHead=false,
       ~onlyEmpty=false,
       ~onlyNonEmpty=false,
       ~omitEmptyLastRow=true,
       (),
     ) =>
   decorateMarker(
     marker,
     {"type": `line, "class": class_, "style": Js.Obj.empty(), "item": item},
   ); */
/* [@bs.send.pipe: t]
   external decorateMarkerLine : (DisplayMarker.t, [@bs.as "line"] _,) => Decoration.t = */
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
