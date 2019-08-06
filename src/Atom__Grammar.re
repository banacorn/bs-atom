open Atom__Type;

type grammar;
type t = grammar;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidUpdate */
[@bs.send.pipe: t]
external onDidUpdate: (unit => unit) => Disposable.t = "onDidUpdate";

/*************************************************************************************************************
  Tokenizing
 ************************************************************************************************************/

/* tokenizeLines */
[@bs.send.pipe: t]
external tokenizeLines: string => array(array(string)) = "tokenizeLines";

/* tokenizeLine */
[@bs.send.pipe: t]
external tokenizeLine: string => Disposable.t = "tokenizeLine";
[@bs.send.pipe: t]
external tokenizeLine_:
  (string, array(string), bool) =>
  {
    .
    "line": string,
    "tags": array(int),
    "ruleStack": array(string),
  } =
  "tokenizeLine";
