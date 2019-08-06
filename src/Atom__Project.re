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

// ::getPaths()
// ::setPaths(projectPaths, options)
// ::addPath(projectPath, options)
// ::removePath(projectPath)
// ::getDirectories()
// ::relativizePath(fullPath)
// ::contains(pathToCheck)
// ::getWatcherPromise(projectPath)
