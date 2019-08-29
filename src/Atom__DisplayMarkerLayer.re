open Atom__Type;

include DisplayMarkerLayer;

/*************************************************************************************************************
  Lifecycle
 ************************************************************************************************************/

/* destroy */
[@bs.send.pipe: t] external destroy: unit = "destroy";

/* clear */
[@bs.send.pipe: t] external clear: unit = "clear";

/* isDestroyed */
[@bs.send.pipe: t] external isDestroyed: bool = "isDestroyed";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidDestroy */
[@bs.send.pipe: t]
external onDidDestroy: (unit => unit) => Disposable.t = "onDidDestroy";

/* onDidUpdate */
[@bs.send.pipe: t]
external onDidUpdate: (unit => unit) => Disposable.t = "onDidUpdate";

/* onDidCreateMarker */
[@bs.send.pipe: t]
external onDidCreateMarker: (TextEditorMarker.t => unit) => Disposable.t =
  "onDidCreateMarker";

/*************************************************************************************************************
  Marker creation
 ************************************************************************************************************/

/* markScreenRange */
[@bs.send.pipe: t]
external markScreenRange: Range.t => DisplayMarker.t = "markScreenRange";

[@bs.send.pipe: t]
external markScreenRange_:
  (
    Range.t,
    {
      .
      "reversed": bool,
      "invalidate": string,
      "exclusive": bool,
      "clipDirection": string,
    }
  ) =>
  DisplayMarker.t =
  "markScreenRange";

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
      "exclusive": bool,
      "clipDirection": string,
    }
  ) =>
  DisplayMarker.t =
  "markScreenPosition";

/* markBufferRange */
[@bs.send.pipe: t]
external markBufferRange: Range.t => DisplayMarker.t = "markBufferRange";

[@bs.send.pipe: t]
external markBufferRange_:
  (
    Range.t,
    {
      .
      "reversed": bool,
      "invalidate": string,
      "exclusive": bool,
    }
  ) =>
  DisplayMarker.t =
  "markBufferRange";

/* markBufferPosition */
[@bs.send.pipe: t]
external markBufferPosition: Point.t => DisplayMarker.t = "markBufferPosition";

[@bs.send.pipe: t]
external markBufferPosition_:
  (
    Point.t,
    {
      .
      "invalidate": string,
      "exclusive": bool,
    }
  ) =>
  DisplayMarker.t =
  "markBufferPosition";

/*************************************************************************************************************
  Querying
 ************************************************************************************************************/

/* getMarker */
[@bs.send.pipe: t] external getMarker: DisplayMarker.t = "getMarker";

/* getMarkers */
[@bs.send.pipe: t] external getMarkers: array(DisplayMarker.t) = "getMarkers";

/* getMarkerCount */
[@bs.send.pipe: t] external getMarkerCount: int = "getMarkerCount";

/* findMarkers */
[@bs.send.pipe: t]
external findMarkers:
  Atom__DisplayMarker.matchingProperties => array(DisplayMarker.t) =
  "findMarkers";
