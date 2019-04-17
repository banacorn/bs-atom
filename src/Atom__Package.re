open Atom__Type;

include Package;

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
