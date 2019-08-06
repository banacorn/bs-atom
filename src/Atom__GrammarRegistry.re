open Atom__Type;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidAddGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external onDidAddGrammar: (Grammar.t => unit) => Disposable.t =
  "onDidAddGrammar";

/* onDidUpdateGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external onDidUpdateGrammar: (Grammar.t => unit) => Disposable.t =
  "onDidUpdateGrammar";

/* onDidRemoveGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external onDidRemoveGrammar: (Grammar.t => unit) => Disposable.t =
  "onDidRemoveGrammar";

/*************************************************************************************************************
  Managing Grammars
 ************************************************************************************************************/

/* getGrammars */
[@bs.val] [@bs.scope ("atom", "grammars")]
external getGrammars: unit => array(Grammar.t) = "getGrammars";

/* grammarForScopeName */
[@bs.val] [@bs.scope ("atom", "grammars")]
external grammarForScopeName: string => option(Grammar.t) =
  "grammarForScopeName";

/* addGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external addGrammar: Grammar.t => Disposable.t = "addGrammar";

/* removeGrammarForScopeName */
[@bs.val] [@bs.scope ("atom", "grammars")]
external removeGrammarForScopeName: string => option(Grammar.t) =
  "removeGrammarForScopeName";

/* readGrammarSync */
[@bs.val] [@bs.scope ("atom", "grammars")]
external readGrammarSync: string => Grammar.t = "readGrammarSync";

/* readGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external readGrammar:
  (string, (option(Js.Exn.t), option(Grammar.t)) => unit) => unit =
  "readGrammar";

/* loadGrammarSync */
[@bs.val] [@bs.scope ("atom", "grammars")]
external loadGrammarSync: string => Grammar.t = "loadGrammarSync";

/* loadGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external loadGrammar:
  (string, (option(Js.Exn.t), option(Grammar.t)) => unit) => unit =
  "loadGrammar";
