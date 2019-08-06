open Atom__Type;

include Package;

/*************************************************************************************************************
  Properties
 ************************************************************************************************************/

[@bs.get] external name: t => string = "name";

/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

/* activate */
[@bs.send.pipe: t] external activate: unit => Js.Promise.t(unit) = "activate";

/* deactivate */
[@bs.send.pipe: t]
external deactivate: unit => Js.Promise.t(unit) = "deactivate";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* observeStyleElements */
[@bs.send.pipe: t]
external onDidDeactivate: (unit => unit) => Disposable.t = "onDidDeactivate";

/*************************************************************************************************************
  Native Module Compatibility
 ************************************************************************************************************/

/* isCompatible */
[@bs.send.pipe: t] external isCompatible: bool = "isCompatible";

/* rebuild */
[@bs.send.pipe: t]
external rebuild:
  Js.Promise.t({
    .
    "code": string,
    "stdout": string,
    "stderr": string,
  }) =
  "rebuild";

/* getBuildFailureOutput */
[@bs.send.pipe: t]
external getBuildFailureOutput: string = "getBuildFailureOutput";
