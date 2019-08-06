open Atom__Type;

type value = Js.t({.});

/*************************************************************************************************************
  Config Subscription
 ************************************************************************************************************/

/* observe */
[@bs.val] [@bs.scope ("atom", "config")]
external observe: (string, value => unit, value) => Disposable.t = "observe";

[@bs.val] [@bs.scope ("atom", "config")]
external observe_:
  (string, {. "scope": ScopeDescriptor.t}, value => unit, value) =>
  Disposable.t =
  "observe";

/* onDidChange */
[@bs.val] [@bs.scope ("atom", "config")]
external onDidChange:
  (
    string,
    {
      .
      "newValue": value,
      "oldValue": value,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidChange";

[@bs.val] [@bs.scope ("atom", "config")]
external onDidChange_:
  (
    string,
    {. "scope": ScopeDescriptor.t},
    {
      .
      "newValue": value,
      "oldValue": value,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidChange";

/*************************************************************************************************************
  Managing Settings
 ************************************************************************************************************/

/* get */
type getOption = {
  .
  "sources": option(array(string)),
  "excludeSources": option(array(string)),
  "scope": option(ScopeDescriptor.t),
};

[@bs.val] [@bs.scope ("atom", "config")]
external get: string => value = "get";

[@bs.val] [@bs.scope ("atom", "config")]
external get_: (string, getOption) => value = "get";

/* set */
type setOption = {
  .
  "scopeSelector": option(string),
  "source": option(string),
};

[@bs.val] [@bs.scope ("atom", "config")]
external set: (string, value) => bool = "set";

[@bs.val] [@bs.scope ("atom", "config")]
external set_: (string, value, setOption) => bool = "set";

/* unset */
[@bs.val] [@bs.scope ("atom", "config")]
external unset: string => unit = "unset";

[@bs.val] [@bs.scope ("atom", "config")]
external unset_: (string, setOption) => unit = "unset";

/*************************************************************************************************************
  Managing Settings
 ************************************************************************************************************/

/* getAll */
[@bs.val] [@bs.scope ("atom", "config")]
external getAll:
  string =>
  array({
    .
    "scopeSelector": ScopeDescriptor.t,
    "value": value,
  }) =
  "getAll";

[@bs.val] [@bs.scope ("atom", "config")]
external getAll_:
  (string, getOption) =>
  array({
    .
    "scopeSelector": ScopeDescriptor.t,
    "value": value,
  }) =
  "getAll";

/* getSources */
[@bs.val] [@bs.scope ("atom", "config")]
external getSources: unit => array(string) = "getSources";

/* getSchema */
[@bs.val] [@bs.scope ("atom", "config")]
external getSchema: string => option(value) = "getSchema";

/* transact */
[@bs.val] [@bs.scope ("atom", "config")]
external transact: (unit => unit) => unit = "transact";
