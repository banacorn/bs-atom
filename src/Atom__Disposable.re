open Atom__Type;

include Disposable;

/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

/* isDisposable */
[@bs.send.pipe: t] external isDisposable: 'a => bool = "isDisposable";

/*************************************************************************************************************
  Construction and Destruction
 ************************************************************************************************************/

/* constructor */
[@bs.module "atom"] [@bs.new]
external make: (unit => unit) => t = "Disposable";

/* dispose */
[@bs.send.pipe: t] external dispose: unit = "dispose";
