open Atom__Type;

include LayerDecoration;

/*************************************************************************************************************
  Visibility
 ************************************************************************************************************/

/* destroy */
[@bs.send.pipe: t] external destroy: unit = "destroy";

/* isDestroyed */
[@bs.send.pipe: t] external isDestroyed: bool = "isDestroyed";

/* getProperties */
[@bs.send.pipe: t] external getProperties: Js.t({.}) = "getProperties";

/* setProperties */
[@bs.send.pipe: t]
external setProperties: Js.t({.}) => unit = "setProperties";

/* setPropertiesForMarker */
[@bs.send.pipe: t]
external setPropertiesForMarker: (Marker.t, Js.t({.})) => unit =
  "setPropertiesForMarker";

[@bs.send.pipe: t]
external setPropertiesForDisplayMarker: (DisplayMarker.t, Js.t({.})) => unit =
  "setPropertiesForMarker";
