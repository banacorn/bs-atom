/* write */
[@bs.val] [@bs.scope ("atom", "clipboard")]
external write: string => unit = "write";
[@bs.val] [@bs.scope ("atom", "clipboard")]
external write_: (string, Js.t({.})) => unit = "write";

/* read */
[@bs.val] [@bs.scope ("atom", "clipboard")]
external read: unit => string = "read";

/* readWithMetadata */
[@bs.val] [@bs.scope ("atom", "clipboard")]
external readWithMetadata:
  unit =>
  {
    .
    "text": string,
    "metadata": option(Js.t({.})),
  } =
  "readWithMetadata";
