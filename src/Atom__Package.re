open Atom__Type;

include Package;

/* Properties */
[@bs.get] external name: t => string = "";

// [@bs.get] external column: t => int = "";

/* Event Subscription */
[@bs.send.pipe: t]
external onDidDeactivate: (unit => unit) => Disposable.t = "";

/* Native Module Compatibility */
[@bs.send.pipe: t] external isCompatible: bool = "";

[@bs.send.pipe: t]
external rebuild:
  Js.Promise.t
    /* ?? */
    ({
      .
      "code": string,
      "stdout": string,
      "stderr": string,
    }) =
  "";

[@bs.send.pipe: t] external getBuildFailureOutput: string = "";

// Instance Methods
[@bs.send.pipe: t] external activate: unit => Js.Promise.t(unit) = "";
[@bs.send.pipe: t] external deactivate: unit => Js.Promise.t(unit) = "";
