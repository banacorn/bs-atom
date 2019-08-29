open Atom__Type;

include GitRepository;

/*************************************************************************************************************
  Construction and Destruction
 ************************************************************************************************************/

/* constructor */
[@bs.module "atom"] [@bs.new] external make: t = "GitRepository";

[@bs.module "atom"] [@bs.new]
external make_: {. "refreshOnWindowFocus": bool} => t = "GitRepository";

/* destroy */
[@bs.send.pipe: t] external destroy: unit = "destroy";

/* isDestroyed */
[@bs.send.pipe: t] external isDestroyed: bool = "isDestroyed";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidDestroy */
[@bs.send.pipe: t]
external onDidDestroy: (unit => unit) => Disposable.t = "onDidDestroy";

/* onDidChangeStatus */
[@bs.send.pipe: t]
external onDidChangeStatus:
  (
    {
      .
      "path": string,
      "pathStatus": int,
    } =>
    unit
  ) =>
  Disposable.t =
  "onDidChangeStatus";

/* onDidChangeStatuses */
[@bs.send.pipe: t]
external onDidChangeStatuses: (unit => unit) => Disposable.t =
  "onDidChangeStatuses";

/*************************************************************************************************************
  Repository Details
 ************************************************************************************************************/

/* getType */
[@bs.send.pipe: t] external getType: string = "getType";

/* getPath */
[@bs.send.pipe: t] external getPath: string = "getPath";

/* getWorkingDirectory */
[@bs.send.pipe: t]
external getWorkingDirectory: string = "getWorkingDirectory";

/* isProjectAtRoot */
[@bs.send.pipe: t] external isProjectAtRoot: bool = "isProjectAtRoot";

/* relativize */
[@bs.send.pipe: t] external relativize: unit = "relativize";

/* hasBranch */
[@bs.send.pipe: t] external hasBranch: bool = "hasBranch";

/* getShortHead */
[@bs.send.pipe: t] external getShortHead: string = "getShortHead";

[@bs.send.pipe: t] external getShortHead_: string => string = "getShortHead";

/* isSubmodule */
[@bs.send.pipe: t] external isSubmodule: string => bool = "isSubmodule";

/* getAheadBehindCount */
[@bs.send.pipe: t]
external getAheadBehindCount: (string, string) => int = "getAheadBehindCount";

/* getCachedUpstreamAheadBehindCount */
[@bs.send.pipe: t]
external getCachedUpstreamAheadBehindCount: {
  .
  "ahead": int,
  "behind": int,
} =
  "getCachedUpstreamAheadBehindCount";

[@bs.send.pipe: t]
external getCachedUpstreamAheadBehindCount_:
  string =>
  {
    .
    "ahead": int,
    "behind": int,
  } =
  "getCachedUpstreamAheadBehindCount";

/* getConfigValue */
[@bs.send.pipe: t] external getConfigValue: string => 'a = "getConfigValue";

[@bs.send.pipe: t]
external getConfigValue_: (string, string) => 'a = "getConfigValue";

/* getOriginURL */
[@bs.send.pipe: t] external getOriginURL: string = "getOriginURL";

[@bs.send.pipe: t] external getOriginURL_: string => string = "getOriginURL";

/* getUpstreamBranch */
[@bs.send.pipe: t]
external getUpstreamBranch: Js.Nullable.t(string) = "getUpstreamBranch";

[@bs.send.pipe: t]
external getUpstreamBranch_: string => Js.Nullable.t(string) =
  "getUpstreamBranch";

/* getReferences */
[@bs.send.pipe: t]
external getReferences: {
  .
  "heads": array(string),
  "remotes": array(string),
  "tags": array(string),
} =
  "getReferences";

[@bs.send.pipe: t]
external getReferences_:
  string =>
  {
    .
    "heads": array(string),
    "remotes": array(string),
    "tags": array(string),
  } =
  "getReferences";

/* getReferenceTarget */
[@bs.send.pipe: t]
external getReferenceTarget: string => string = "getReferenceTarget";

external getReferenceTarget_: (string, string) => string =
  "getReferenceTarget";

/*************************************************************************************************************
  Reading Status
 ************************************************************************************************************/

/* isPathModified */
[@bs.send.pipe: t] external isPathModified: string => bool = "isPathModified";

/* isPathNew */
[@bs.send.pipe: t] external isPathNew: string => bool = "isPathNew";

/* isPathIgnored */
[@bs.send.pipe: t] external isPathIgnored: string => bool = "isPathIgnored";

/* getDirectoryStatus */
[@bs.send.pipe: t]
external getDirectoryStatus: string => int = "getDirectoryStatus";

/* getPathStatus */
[@bs.send.pipe: t] external getPathStatus: string => int = "getPathStatus";

/* getCachedPathStatus */
[@bs.send.pipe: t]
external getCachedPathStatus: string => int = "getCachedPathStatus";

/*  isStatusModified*/
[@bs.send.pipe: t] external isStatusModified: int => bool = "isStatusModified";

/* isStatusNew */
[@bs.send.pipe: t] external isStatusNew: int => bool = "isStatusNew";

/*************************************************************************************************************
  Retrieving Diffs
 ************************************************************************************************************/

/* getDiffStats */
[@bs.send.pipe: t]
external getDiffStats:
  string =>
  {
    .
    "added": int,
    "deleted": int,
  } =
  "getDiffStats";

/* getLineDiffs */
[@bs.send.pipe: t]
external getLineDiffs:
  (string, string) =>
  {
    .
    "oldStart": int,
    "newStart": int,
    "oldLines": int,
    "newLines": int,
  } =
  "getLineDiffs";

/*************************************************************************************************************
  Checking Out
 ************************************************************************************************************/

/* checkoutHead */
[@bs.send.pipe: t] external checkoutHead: string => bool = "checkoutHead";

/* checkoutReference */
[@bs.send.pipe: t]
external checkoutReference: (string, bool) => bool = "checkoutReference";
