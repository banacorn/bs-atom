/*************************************************************************************************************
  Methods
 ************************************************************************************************************/

type state = Js.t({.});
type deserializer = {
  .
  "name": string,
  "deserialize": (state, Js.t({.})),
};

/* add */
[@bs.val] [@bs.scope ("atom", "deserializers")]
external add: array(deserializer) => unit = "add";

/* deserialize */
[@bs.val] [@bs.scope ("atom", "deserializers")]
external deserialize: state => unit = "deserialize";
