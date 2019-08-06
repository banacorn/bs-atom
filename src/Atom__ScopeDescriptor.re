open Atom__Type;

include ScopeDescriptor;

/*
    Construction and Destruction
 */

/* constructor() */
[@bs.module "atom"] [@bs.new]
external make: {. "scopes": array(string)} => t = "ScopeDescriptor";

/* getScopesArray() */
[@bs.send.pipe: t] external getScopesArray: array(string) = "getScopesArray";
