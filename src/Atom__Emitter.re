open Atom__Type;

include Dock;

/*************************************************************************************************************
  Construction and Destruction
 ************************************************************************************************************/

/* constructor */
[@bs.module "atom"] [@bs.new] external make: t = "Emitter";

/* clear */
[@bs.send.pipe: t] external clear: unit = "clear";

/* dispose */
[@bs.send.pipe: t] external dispose: unit = "dispose";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* on */
[@bs.send.pipe: t] external on: (string, 'a => unit) => Disposable.t = "on";

/* once */
[@bs.send.pipe: t]
external once: (string, 'a => unit) => Disposable.t = "once";

/* preempt */
[@bs.send.pipe: t]
external preempt: (string, 'a => unit) => Disposable.t = "preempt";

/*************************************************************************************************************
  Event Emission
 ************************************************************************************************************/

/* emit */
[@bs.send.pipe: t] external emit: (string, 'a) => unit = "emit";
