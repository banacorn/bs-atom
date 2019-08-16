open Atom__Type;

// Atom Details
[@bs.val] [@bs.scope "atom"] external inDevMode: unit => bool = "";
[@bs.val] [@bs.scope "atom"] external inSafeMode: unit => bool = "";
[@bs.val] [@bs.scope "atom"] external inSpecMode: unit => bool = "";
[@bs.val] [@bs.scope "atom"] external getVersion: unit => string = "";
[@bs.val] [@bs.scope "atom"] external getReleaseChannel: unit => string = "";
[@bs.val] [@bs.scope "atom"] external isReleasedVersion: unit => bool = "";
[@bs.val] [@bs.scope "atom"] external getWindowLoadTime: unit => int = "";
[@bs.val] [@bs.scope "atom"]
external getLoadSettings: unit => Js.t({..}) = "";
/* module type HooksSpec = {
     type state;
     type serializedState;

     let activate : option(serializedState) => state;
     let serialize : state => serializedState;
     let deactivate : state => unit;
   };

   module Hooks (Spec: HooksSpec) = {
     type self = {
       mutable state: Spec.state
     };

     let activate = ( (self, serializedState) => {
       self.state = Spec.activate (Js.Undefined.to_opt(serializedState));
     }) [@bs.this];

     let serialize = ((self) => Spec.serialize(self.state)) [@bs.this];

     let deactivate = ((self) => Spec.deactivate(self.state)) [@bs.this];
   }; */
