open Atom__Type;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidAddGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external onDidAddGrammar: (Atom__Grammar.t => unit) => Disposable.t =
  "onDidAddGrammar";

/* onDidUpdateGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external onDidUpdateGrammar: (Atom__Grammar.t => unit) => Disposable.t =
  "onDidUpdateGrammar";

/* onDidRemoveGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external onDidRemoveGrammar: (Atom__Grammar.t => unit) => Disposable.t =
  "onDidRemoveGrammar";

/*************************************************************************************************************
  Managing Grammars
 ************************************************************************************************************/

/* getGrammars */
[@bs.val] [@bs.scope ("atom", "grammars")]
external getGrammars: unit => array(Atom__Grammar.t) = "getGrammars";

/* grammarForScopeName */
[@bs.val] [@bs.scope ("atom", "grammars")]
external grammarForScopeName: string => option(Atom__Grammar.t) =
  "grammarForScopeName";

/* addGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external addGrammar: Atom__Grammar.t => Disposable.t = "addGrammar";

/* removeGrammarForScopeName */
[@bs.val] [@bs.scope ("atom", "grammars")]
external removeGrammarForScopeName: string => option(Atom__Grammar.t) =
  "removeGrammarForScopeName";

/* readGrammarSync */
[@bs.val] [@bs.scope ("atom", "grammars")]
external readGrammarSync: string => Atom__Grammar.t = "readGrammarSync";

/* readGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external readGrammar:
  (string, (option(Js.Exn.t), option(Atom__Grammar.t)) => unit) => unit =
  "readGrammar";

/* loadGrammarSync */
[@bs.val] [@bs.scope ("atom", "grammars")]
external loadGrammarSync: string => Atom__Grammar.t = "loadGrammarSync";

/* loadGrammar */
[@bs.val] [@bs.scope ("atom", "grammars")]
external loadGrammar:
  (string, (option(Js.Exn.t), option(Atom__Grammar.t)) => unit) => unit =
  "loadGrammar";
