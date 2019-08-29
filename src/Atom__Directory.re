open Atom__Type;

include Directory;

/*************************************************************************************************************
  Construction
 ************************************************************************************************************/

/* constructor */
[@bs.module "atom"] [@bs.new] external make: string => t = "Directory";

[@bs.module "atom"] [@bs.new]
external make_: (string, bool) => t = "Directory";

/* create */
[@bs.send.pipe: t] external create: Js.Promise.t(bool) = "create";

[@bs.send.pipe: t] external create_: int => Js.Promise.t(bool) = "create";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChange */
[@bs.send.pipe: t]
external onDidChange: (unit => unit) => Disposable.t = "onDidChange";

/*************************************************************************************************************
  Directory Metadata
 ************************************************************************************************************/

/* isFile */
[@bs.send.pipe: t] external isFile: bool = "isFile";

/* isDirectory */
[@bs.send.pipe: t] external isDirectory: bool = "isDirectory";

/* isSymbolicLink */
[@bs.send.pipe: t] external isSymbolicLink: bool = "isSymbolicLink";

/* exists */
[@bs.send.pipe: t] external exists: Js.Promise.t(bool) = "exists";

/* existsSync */
[@bs.send.pipe: t] external existsSync: bool = "existsSync";

/* isRoot */
[@bs.send.pipe: t] external isRoot: bool = "isRoot";

/*************************************************************************************************************
  Managing Paths
 ************************************************************************************************************/

/* getPath */
[@bs.send.pipe: t] external getPath: string = "getPath";

/* getRealPathSync */
[@bs.send.pipe: t] external getRealPathSync: string = "getRealPathSync";

/* getBaseName */
[@bs.send.pipe: t] external getBaseName: string = "getBaseName";

/* relativize */
[@bs.send.pipe: t] external relativize: string = "relativize";

/*************************************************************************************************************
  Traversing
 ************************************************************************************************************/

/* getParent */
[@bs.send.pipe: t] external getParent: Directory.t = "getParent";

/* getFile */
[@bs.send.pipe: t] external getFile: string => File.t = "getFile";

/* getSubdirectory */
[@bs.send.pipe: t]
external getSubdirectory: string => Directory.t = "getSubdirectory";

/* getEntriesSync */
// actually array(File.t) ++ array(Directory.t), fuck it.
[@bs.send.pipe: t] external getEntriesSync: array(File.t) = "getEntriesSync";

/* getEntries */
[@bs.send.pipe: t]
external getEntries:
  ((Js.Nullable.t(Js.Exn.t), array(File.t)) => unit) => unit =
  "getEntries";

/* contains */
[@bs.send.pipe: t] external contains: string => bool = "contains";
