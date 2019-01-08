open Atom__Type;

include TextEditor;

/* Event Subscription */
[@bs.send.pipe: t] external getBuffer: TextBuffer.t = "";

[@bs.send.pipe: t] external getCursors: array(Cursor.t) = "";

[@bs.send.pipe: t] external isMini: bool = "";

/* File Details */
[@bs.send.pipe: t] external getTitle: string = "";

[@bs.send.pipe: t] external getLongTitle: string = "";

[@bs.send.pipe: t] external getPath: string = "";

[@bs.send.pipe: t] external isModified: bool = "";

[@bs.send.pipe: t] external isEmpty: bool = "";

/* Reading Text */
[@bs.send.pipe: t] external getText: string = "";

[@bs.send.pipe: t] external getTextInBufferRange: Range.t => string = "";

/* Mutating Text */
[@bs.send.pipe: t] external setText: string => unit = "";

[@bs.send.pipe: t]
external setTextInBufferRange: (Range.t, string) => Range.t = "";

[@bs.send.pipe: t]
external setTextWithOption: (string, {. bypassReadOnly: bool}) => unit =
  "setText";

/* Grammars */
[@bs.send.pipe: t] external setGrammar: grammar => unit = "";

/* TextEditor Rendering */
[@bs.send.pipe: t] external getPlaceholderText: string = "";

[@bs.send.pipe: t] external setPlaceholderText: string => unit = "";

/* Selections */
[@bs.send.pipe: t] external getSelections: array(Selection.t) = "";

[@bs.send.pipe: t] external getSelectedBufferRange: Range.t = "";

[@bs.send.pipe: t] external getSelectedBufferRanges: array(Range.t) = "";

[@bs.send] external setSelectedBufferRange: (t, Range.t) => unit = "";
[@bs.send]
external setSelectedBufferRange_:
  (
    t,
    Range.t,
    {
      .
      reversed: bool,
      preserveFolds: bool,
    }
  ) =>
  unit =
  "setSelectedBufferRange";

[@bs.send] external setSelectedBufferRanges: (t, array(Range.t)) => unit = "";
[@bs.send]
external setSelectedBufferRanges_:
  (
    t,
    array(Range.t),
    {
      .
      reversed: bool,
      preserveFolds: bool,
    }
  ) =>
  unit =
  "setSelectedBufferRanges";

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
/* let scan = (regex, iterator) => */
/* [@bs.send.pipe: t]
   external scan':
     (
       Js.Re.t,
       {
         .
         leadingContextLineCount: int,
         trailingContextLineCount: int,
       },
       scanMatch => unit
     ) =>
     unit =
     ""; */

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
      maintainHistory: bool,
      reversed: bool,
      invalidate: DisplayMarker.validity,
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
