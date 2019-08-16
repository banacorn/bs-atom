open Atom__Type;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChangePaths */
[@bs.val] [@bs.scope ("atom", "project")]
external onDidChangePaths: (array(string) => unit) => Disposable.t =
  "onDidChangePaths";

/* onDidAddBuffer */
[@bs.val] [@bs.scope ("atom", "project")]
external onDidAddBuffer: (TextBuffer.t => unit) => Disposable.t =
  "onDidAddBuffer";

/* observeBuffers */
[@bs.val] [@bs.scope ("atom", "project")]
external observeBuffers: (TextBuffer.t => unit) => Disposable.t =
  "observeBuffers";

/* observeRepositories */
[@bs.val] [@bs.scope ("atom", "project")]
external observeRepositories: (GitRepository.t => unit) => Disposable.t =
  "observeRepositories";

/* onDidAddRepository */
[@bs.val] [@bs.scope ("atom", "project")]
external onDidAddRepository: (GitRepository.t => unit) => Disposable.t =
  "onDidAddRepository";

/* onDidChangeFiles */
[@bs.val] [@bs.scope ("atom", "project")]
external onDidChangeFiles:
  (
    array({
      .
      "action": string,
      "path": string,
      "oldPath": string,
    }) =>
    unit
  ) =>
  Disposable.t =
  "onDidChangeFiles";

/*************************************************************************************************************
  Accessing the git repository
 ************************************************************************************************************/

/* getRepositories */
[@bs.val] [@bs.scope ("atom", "project")]
external getRepositories: unit => array(GitRepository.t) = "getRepositories";

/* repositoryForDirectory */
[@bs.val] [@bs.scope ("atom", "project")]
external repositoryForDirectory:
  Directory.t => Js.Promise.t(Js.Nullable.t(GitRepository.t)) =
  "repositoryForDirectory";

/*************************************************************************************************************
  Managing Paths
 ************************************************************************************************************/

/* getPaths */
[@bs.val] [@bs.scope ("atom", "project")]
external getPaths: unit => array(string) = "getPaths";

/* setPaths */
[@bs.val] [@bs.scope ("atom", "project")]
external setPaths: array(string) => unit = "setPaths";

[@bs.val] [@bs.scope ("atom", "project")]
external setPaths_:
  (
    array(string),
    {
      .
      "mustExist": bool,
      "exact": bool,
    }
  ) =>
  unit =
  "setPaths";

/* addPath */
[@bs.val] [@bs.scope ("atom", "project")]
external addPath: string => unit = "addPath";

[@bs.val] [@bs.scope ("atom", "project")]
external addPath_:
  (
    string,
    {
      .
      "mustExist": bool,
      "exact": bool,
    }
  ) =>
  unit =
  "addPath";

/* removePath */
[@bs.val] [@bs.scope ("atom", "project")]
external removePath: string => unit = "removePath";

/* getDirectories */
[@bs.val] [@bs.scope ("atom", "project")]
external getDirectories: unit => array(string) = "getDirectories";

/* relativizePath */
[@bs.val] [@bs.scope ("atom", "project")]
external relativizePath_: unit => array(string) = "relativizePath";

let relativizePath: unit => (string, string) =
  () => {
    switch (relativizePath_()) {
    | [|projectPath, relativePath|] => (projectPath, relativePath)
    | _ => ("", "")
    };
  };

/* contains */
[@bs.val] [@bs.scope ("atom", "project")]
external contains: string => bool = "contains";

/* getWatcherPromise */
[@bs.val] [@bs.scope ("atom", "project")]
external getWatcherPromise: string => Js.Promise.t(PathWatcher.t) =
  "getWatcherPromise";
