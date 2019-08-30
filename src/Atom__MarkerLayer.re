open Atom__Type;

include MarkerLayer;

/*************************************************************************************************************
  Lifecycle
 ************************************************************************************************************/

/* copy */
[@bs.send.pipe: t] external copy: MarkerLayer.t = "copy";

/* destroy */
[@bs.send.pipe: t] external destroy: unit = "destroy";

/* clear */
[@bs.send.pipe: t] external clear: unit = "clear";

/* isDestroyed */
[@bs.send.pipe: t] external isDestroyed: bool = "isDestroyed";

/*************************************************************************************************************
  Querying
 ************************************************************************************************************/

/* getMarker */
[@bs.send.pipe: t] external getMarker: marker = "getMarker";

/* getMarkers */
[@bs.send.pipe: t] external getMarkers: array(marker) = "getMarkers";

/* getMarkerCount */
[@bs.send.pipe: t] external getMarkerCount: int = "getMarkerCount";

/* findMarkers */
[@bs.send.pipe: t]
external findMarkers: Js.t({.}) => array(marker) = "findMarkers";

/* getRole */
[@bs.send.pipe: t] external getRole: string = "getRole";

/*************************************************************************************************************
  Marker creation
 ************************************************************************************************************/

/* markRange */
[@bs.send.pipe: t] external markRange: Range.t => marker = "markRange";

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
  marker =
  "markRange";

/* markPosition */
[@bs.send.pipe: t] external markPosition: Point.t => marker = "markPosition";

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
  marker =
  "markPosition";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChange */
[@bs.send.pipe: t]
external onDidChange: (unit => unit) => Disposable.t = "onDidChange";

/* onDidCreateMarker */
[@bs.send.pipe: t]
external onDidCreateMarker: (marker => unit) => Disposable.t =
  "onDidCreateMarker";

/* onDidDestroy */
[@bs.send.pipe: t]
external onDidDestroy: (unit => unit) => Disposable.t = "onDidDestroy";
