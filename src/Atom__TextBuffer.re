open Atom__Type;

include TextBuffer;

/*************************************************************************************************************
  Construction
 ************************************************************************************************************/

/* .load */
[@bs.val] [@bs.scope ("atom", "TextBuffer")]
external load: string => Js.Promise.t(TextBuffer.t) = "load";

[@bs.val] [@bs.scope ("atom", "TextBuffer")]
external load_:
  (
    string,
    {
      .
      "encoding": string,
      [@bs.meth] "shouldDestroyOnFileDelete": unit => bool,
    }
  ) =>
  Js.Promise.t(TextBuffer.t) =
  "load";

type setFileOptions = {
  .
  [@bs.meth] "getPath": unit => string,
  [@bs.meth] "createReadStream": unit => Js.t({.}),
  [@bs.meth] "createWriteStream": unit => Js.t({.}),
  [@bs.meth] "existsSync": unit => bool,
  [@bs.meth] "onDidChange": unit => Disposable.t,
  [@bs.meth] "onDidDelete": unit => Disposable.t,
  [@bs.meth] "onDidRename": unit => Disposable.t,
};

[@bs.val] [@bs.scope ("atom", "TextBuffer")]
external loadFromObject: setFileOptions => Js.Promise.t(TextBuffer.t) =
  "load";

[@bs.val] [@bs.scope ("atom", "TextBuffer")]
external loadFromObject_:
  (
    setFileOptions,
    {
      .
      "encoding": string,
      [@bs.meth] "shouldDestroyOnFileDelete": unit => bool,
    }
  ) =>
  Js.Promise.t(TextBuffer.t) =
  "load";

/* loadSync */
[@bs.val] [@bs.scope ("atom", "TextBuffer")]
external loadSync: string => TextBuffer.t = "loadSync";

[@bs.val] [@bs.scope ("atom", "TextBuffer")]
external loadSync_:
  (
    string,
    {
      .
      "encoding": string,
      [@bs.meth] "shouldDestroyOnFileDelete": unit => bool,
    }
  ) =>
  TextBuffer.t =
  "loadSync";

/* deserialize */
[@bs.val] [@bs.scope ("atom", "TextBuffer")]
external deserialize: Js.t({.}) => Js.Promise.t(TextBuffer.t) =
  "deserialize";

/* constructor */
[@bs.module "atom"] [@bs.new] external make: string => t = "TextBuffer";

[@bs.module "atom"] [@bs.new]
external make_:
  {
    .
    "text": string,
    "shouldDestroyOnFileDelete": bool,
  } =>
  t =
  "TextBuffer";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onWillChange */
[@bs.send.pipe: t]
external onWillChange: (unit => unit) => Disposable.t = "onWillChange";

/* onDidChange */
[@bs.send.pipe: t]
external onDidChange: (unit => unit) => Disposable.t = "onDidChange";

/* onDidChangeText */
[@bs.send.pipe: t]
external onDidChangeText: (unit => unit) => Disposable.t = "onDidChangeText";

/* onDidStopChanging */
[@bs.send.pipe: t]
external onDidStopChanging:
  (
    {
      .
      "changes": array(Js.t({.})),
      "oldRange": Range.t,
      "newRange": Range.t,
      "oldText": string,
      "newText": string,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidStopChanging";

/* onDidConflict */
[@bs.send.pipe: t]
external onDidConflict: (unit => unit) => Disposable.t = "onDidConflict";

/* onDidChangeModified */
[@bs.send.pipe: t]
external onDidChangeModified: (bool => unit) => Disposable.t =
  "onDidChangeModified";

/* onDidUpdateMarkers */
[@bs.send.pipe: t]
external onDidUpdateMarkers: (bool => unit) => Disposable.t =
  "onDidUpdateMarkers";

/* onDidCreateMarker */
[@bs.send.pipe: t]
external onDidCreateMarker: (MarkerLayer.marker => unit) => Disposable.t =
  "onDidCreateMarker";

/* onDidChangePath */
[@bs.send.pipe: t]
external onDidChangePath: (string => unit) => Disposable.t = "onDidChangePath";

/* onDidChangeEncoding */
[@bs.send.pipe: t]
external onDidChangeEncoding: (string => unit) => Disposable.t =
  "onDidChangeEncoding";

/* onWillSave */
[@bs.send.pipe: t]
external onWillSave: (unit => unit) => Disposable.t = "onWillSave";

[@bs.send.pipe: t]
external onWillSave_: (unit => Js.Promise.t('a)) => Disposable.t =
  "onWillSave";

/* onDidSave */
[@bs.send.pipe: t]
external onDidSave: ({. "path": string} => unit) => Disposable.t =
  "onDidSave";

/* onDidDelete */
[@bs.send.pipe: t]
external onDidDelete: (unit => unit) => Disposable.t = "onDidDelete";

/* onWillReload */
[@bs.send.pipe: t]
external onWillReload: (unit => unit) => Disposable.t = "onWillReload";

/* onDidReload */
[@bs.send.pipe: t]
external onDidReload: (unit => unit) => Disposable.t = "onDidReload";

/* onDidDestroy */
[@bs.send.pipe: t]
external onDidDestroy: (unit => unit) => Disposable.t = "onDidDestroy";

/* onWillThrowWatchError */
[@bs.send.pipe: t]
external onWillThrowWatchError:
  (
    {
      .
      "error": Js.Exn.t,
      [@bs.meth] "handle": unit => unit,
    } =>
    unit
  ) =>
  Disposable.t =
  "onWillThrowWatchError";

/* getStoppedChangingDelay */
[@bs.send.pipe: t]
external getStoppedChangingDelay: int = "getStoppedChangingDelay";

/*************************************************************************************************************
  File Details
 ************************************************************************************************************/

/* isModified */
[@bs.send.pipe: t] external isModified: bool = "isModified";

/* isInConflict */
[@bs.send.pipe: t] external isInConflict: bool = "isInConflict";

/* getPath */
[@bs.send.pipe: t] external getPath: string = "getPath";

/* setPath */
[@bs.send.pipe: t] external setPath: string => unit = "setPath";

/* setEncoding */
[@bs.send.pipe: t] external setEncoding: string => unit = "setEncoding";

/* getEncoding */
[@bs.send.pipe: t] external getEncoding: string = "getEncoding";

/* getUri */
[@bs.send.pipe: t] external getUri: string = "getUri";

/*************************************************************************************************************
  Reading Text
 ************************************************************************************************************/

/* isEmpty */
[@bs.send.pipe: t] external isEmpty: bool = "isEmpty";

/* getText */
[@bs.send.pipe: t] external getText: string = "getText";

/* getTextInRange */
[@bs.send.pipe: t]
external getTextInRange: Range.t => string = "getTextInRange";

/* getLines */
[@bs.send.pipe: t] external getLines: array(string) = "getLines";

/* getLastText */
[@bs.send.pipe: t] external getLastText: string = "getLastText";

/* lineForRow */
[@bs.send.pipe: t] external lineForRow: int => string = "lineForRow";

/* lineEndingForRow */
[@bs.send.pipe: t]
external lineEndingForRow: int => string = "lineEndingForRow";

/* lineLengthForRow */
[@bs.send.pipe: t] external lineLengthForRow: int => int = "lineLengthForRow";

/* isRowBlank */
[@bs.send.pipe: t] external isRowBlank: int => bool = "isRowBlank";

/* previousNonBlankRow */
[@bs.send.pipe: t]
external previousNonBlankRow: int => option(int) = "previousNonBlankRow";

/* nextNonBlankRow */
[@bs.send.pipe: t]
external nextNonBlankRow: int => option(int) = "nextNonBlankRow";

/* hasAstral */
[@bs.send.pipe: t] external hasAstral: bool = "hasAstral";

/*************************************************************************************************************
  Mutating Text
 ************************************************************************************************************/

/* setText */
[@bs.send.pipe: t] external setText: string => Range.t = "setText";

/* setTextViaDiff */
[@bs.send.pipe: t]
external setTextViaDiff: string => Range.t = "setTextViaDiff";

/* setTextInRange */
[@bs.send.pipe: t]
external setTextInRange: (Range.t, string) => Range.t = "setTextInRange";

[@bs.send.pipe: t]
external setTextInRange_:
  (Range.t, string, {. "normalizeLineEndings": bool}) => Range.t =
  "setTextInRange";

/* insert */
[@bs.send.pipe: t] external insert: (Point.t, string) => Range.t = "insert";

[@bs.send.pipe: t]
external insert_:
  (Point.t, string, {. "normalizeLineEndings": bool}) => Range.t =
  "insert";

/* append */
[@bs.send.pipe: t] external append: string => Range.t = "append";

[@bs.send.pipe: t]
external append_: (string, {. "normalizeLineEndings": bool}) => Range.t =
  "append";

/* delete */
[@bs.send.pipe: t] external delete: Range.t => Range.t = "delete";

/* deleteRow */
[@bs.send.pipe: t] external deleteRow: int => Range.t = "deleteRow";

/* deleteRows */
[@bs.send.pipe: t] external deleteRows: (int, int) => Range.t = "deleteRows";

/*************************************************************************************************************
  Markers
 ************************************************************************************************************/

/* addMarkerLayer */
[@bs.send.pipe: t]
external addMarkerLayer:
  {
    .
    "maintainHistory": bool,
    "persistent": bool,
    "role": string,
  } =>
  MarkerLayer.t =
  "addMarkerLayer";

/* getMarkerLayer */
[@bs.send.pipe: t]
external getMarkerLayer: int => option(MarkerLayer.t) = "getMarkerLayer";

/* getDefaultMarkerLayer */
[@bs.send.pipe: t]
external getDefaultMarkerLayer: MarkerLayer.t = "getDefaultMarkerLayer";

/* markRange */
[@bs.send.pipe: t]
external markRange: Range.t => MarkerLayer.marker = "markRange";

[@bs.send.pipe: t]
external markRange_:
  (
    Range.t,
    {
      .
      "reversed": bool,
      "invalidate": string,
      "exclusive": bool,
    }
  ) =>
  MarkerLayer.marker =
  "markRange";

/* markPosition */
[@bs.send.pipe: t]
external markPosition: Point.t => MarkerLayer.marker = "markPosition";

[@bs.send.pipe: t]
external markPosition_:
  (
    Point.t,
    {
      .
      "invalidate": string,
      "exclusive": bool,
    }
  ) =>
  MarkerLayer.marker =
  "markPosition";

/* getMarkers */
[@bs.send.pipe: t]
external getMarkers: array(MarkerLayer.marker) = "getMarkers";

/* getMarker */
[@bs.send.pipe: t]
external getMarker: int => option(MarkerLayer.marker) = "getMarker";

/* findMarkers */
[@bs.send.pipe: t]
external findMarkers: Js.t({.}) => array(MarkerLayer.marker) = "findMarkers";

/* getMarkerCount */
[@bs.send.pipe: t] external getMarkerCount: int = "getMarkerCount";

/*************************************************************************************************************
  History
 ************************************************************************************************************/

/* undo */
[@bs.send.pipe: t] external undo: unit = "undo";

[@bs.send.pipe: t]
external undo_: {. "selectionsMarkerLayer": MarkerLayer.t} => bool = "undo";

/* redo */
[@bs.send.pipe: t] external redo: unit = "redo";

[@bs.send.pipe: t]
external redo_: {. "selectionsMarkerLayer": MarkerLayer.t} => bool = "redo";

/* transact */
[@bs.send.pipe: t] external transact: (unit => 'a) => option('a) = "transact";

[@bs.send.pipe: t]
external transact_:
  (
    {
      .
      "groupingInterval": int,
      "selectionsMarkerLayer": MarkerLayer.t,
    },
    int,
    unit => 'a
  ) =>
  option('a) =
  "transact";

/* abortTransaction */
[@bs.send.pipe: t] external abortTransaction: unit = "abortTransaction";

/* clearUndoStack */
[@bs.send.pipe: t] external clearUndoStack: unit = "clearUndoStack";

/* createCheckpoint */
[@bs.send.pipe: t] external createCheckpoint: int = "createCheckpoint";

[@bs.send.pipe: t]
external createCheckpoint_: {. "selectionsMarkerLayer": MarkerLayer.t} => int =
  "createCheckpoint";

/* revertToCheckpoint */
[@bs.send.pipe: t]
external revertToCheckpoint: int => bool = "revertToCheckpoint";

[@bs.send.pipe: t]
external revertToCheckpoint_:
  ({. "selectionsMarkerLayer": MarkerLayer.t}, int) => bool =
  "revertToCheckpoint";

/* groupChangesSinceCheckpoint */
[@bs.send.pipe: t]
external groupChangesSinceCheckpoint: int => bool =
  "groupChangesSinceCheckpoint";

[@bs.send.pipe: t]
external groupChangesSinceCheckpoint_:
  ({. "selectionsMarkerLayer": MarkerLayer.t}, int) => bool =
  "groupChangesSinceCheckpoint";

/* groupLastChanges */
[@bs.send.pipe: t] external groupLastChanges: bool = "groupLastChanges";

/* getChangesSinceCheckpoint */
[@bs.send.pipe: t]
external getChangesSinceCheckpoint:
  int =>
  array({
    .
    "oldRange": Range.t,
    "newRange": Range.t,
    "oldText": string,
    "newText": string,
  }) =
  "getChangesSinceCheckpoint";

/*************************************************************************************************************
  Search And Replace
 ************************************************************************************************************/

type iterator =
  {
    .
    "match": Js.t({.}),
    "matchText": string,
    "range": Range.t,
    [@bs.meth] "stop": unit => unit,
    [@bs.meth] "replace": string => unit,
    "leadingContextLines": array(string),
    "trailingContextLines": array(string),
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

/* backwardsScan */
[@bs.send.pipe: t]
external backwardsScan: (Js.Re.t, iterator) => unit = "backwardsScan";

[@bs.send.pipe: t]
external backwardsScan_:
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
  "backwardsScan";

/* scanInRange */
[@bs.send.pipe: t]
external scanInRange: (Js.Re.t, Range.t, iterator) => unit = "scanInRange";

[@bs.send.pipe: t]
external scanInRange_:
  (
    Js.Re.t,
    Range.t,
    {
      .
      "leadingContextLineCount": int,
      "trailingContextLineCount": int,
    },
    iterator
  ) =>
  unit =
  "scanInRange";

/* backwardsScanInRange */
[@bs.send.pipe: t]
external backwardsScanInRange: (Js.Re.t, Range.t, iterator) => unit =
  "backwardsScanInRange";

[@bs.send.pipe: t]
external backwardsScanInRange_:
  (
    Js.Re.t,
    Range.t,
    {
      .
      "leadingContextLineCount": int,
      "trailingContextLineCount": int,
    },
    iterator
  ) =>
  unit =
  "backwardsScanInRange";

/* replace */
[@bs.send.pipe: t] external replace: (Js.Re.t, string) => int = "replace";

/*************************************************************************************************************
  Buffer Range Details
 ************************************************************************************************************/

/* getRange */
[@bs.send.pipe: t] external getRange: Range.t = "getRange";

/* getLineCount */
[@bs.send.pipe: t] external getLineCount: int = "getLineCount";

/* getLastRow */
[@bs.send.pipe: t] external getLastRow: int = "getLastRow";

/* getFirstPosition */
[@bs.send.pipe: t] external getFirstPosition: Point.t = "getFirstPosition";

/* getEndPosition */
[@bs.send.pipe: t] external getEndPosition: Point.t = "getEndPosition";

/* getLength */
[@bs.send.pipe: t] external getLength: int = "getLength";

/* getMaxCharacterIndex */
[@bs.send.pipe: t] external getMaxCharacterIndex: int = "getMaxCharacterIndex";

/* rangeForRow */
[@bs.send.pipe: t]
external rangeForRow: (int, bool) => Range.t = "rangeForRow";

/* characterIndexForPosition */
[@bs.send.pipe: t]
external characterIndexForPosition: Point.t => int =
  "characterIndexForPosition";

/* positionForCharacterIndex */
[@bs.send.pipe: t]
external positionForCharacterIndex: int => Point.t =
  "positionForCharacterIndex";

/* clipRange */
[@bs.send.pipe: t] external clipRange: Range.t => Range.t = "clipRange";

/* clipPosition */
[@bs.send.pipe: t] external clipPosition: Point.t => Point.t = "clipPosition";

/*************************************************************************************************************
  Buffer Operations
 ************************************************************************************************************/

/* save */
[@bs.send.pipe: t] external save: Js.Promise.t(unit) = "save";

/* saveAs */
[@bs.send.pipe: t] external saveAs: string => Js.Promise.t(unit) = "saveAs";

/* reload */
[@bs.send.pipe: t] external reload: Js.Promise.t(unit) = "reload";
