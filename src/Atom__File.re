open Atom__Type;

include File;

/*************************************************************************************************************
  Construction
 ************************************************************************************************************/

/* constructor */
[@bs.module "atom"] [@bs.new] external make: string => t = "File";

[@bs.module "atom"] [@bs.new] external make_: (string, bool) => t = "File";

/* create */
[@bs.send.pipe: t] external create: Js.Promise.t(bool) = "create";

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChange */
[@bs.send.pipe: t]
external onDidChange: (unit => unit) => Disposable.t = "onDidChange";

/* onDidRename */
[@bs.send.pipe: t]
external onDidRename: (unit => unit) => Disposable.t = "onDidRename";

/* onDidDelete */
[@bs.send.pipe: t]
external onDidDelete: (unit => unit) => Disposable.t = "onDidDelete";

/* onWillThrowWatchError */
[@bs.send.pipe: t]
external onWillThrowWatchError:
  (
    {
      .
      "error": Js.Exn.t,
      "handle": unit => unit,
    } =>
    unit
  ) =>
  Disposable.t =
  "onWillThrowWatchError";

/*************************************************************************************************************
  File Metadata
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

/* getDigest */
[@bs.send.pipe: t] external getDigest: Js.Promise.t(string) = "getDigest";

/* getDigestSync */
[@bs.send.pipe: t] external getDigestSync: string = "getDigestSync";

/* setEncoding */
[@bs.send.pipe: t] external setEncoding: string => unit = "setEncoding";

/* getEncoding */
[@bs.send.pipe: t] external getEncoding: string = "getEncoding";

/*************************************************************************************************************
  Managing Paths
 ************************************************************************************************************/

/* getPath */
[@bs.send.pipe: t] external getPath: string = "getPath";

/* getRealPathSync */
[@bs.send.pipe: t] external getRealPathSync: string = "getRealPathSync";

/* getRealPath */
[@bs.send.pipe: t] external getRealPath: Js.Promise.t(string) = "getRealPath";

/* getBaseName */
[@bs.send.pipe: t] external getBaseName: string = "getBaseName";

/*************************************************************************************************************
  Traversing
 ************************************************************************************************************/

/* getParent */
[@bs.send.pipe: t] external getParent: Directory.t = "getParent";

/*************************************************************************************************************
  Reading and Writing
 ************************************************************************************************************/

/* read */
[@bs.send.pipe: t] external read: bool => Js.Promise.t(string) = "read";

/* createReadStream */
[@bs.send.pipe: t] external createReadStream: 'a = "createReadStream";

/* write */
[@bs.send.pipe: t] external write: string => Js.Promise.t(unit) = "write";

/* createWriteStream */
[@bs.send.pipe: t] external createWriteStream: 'a = "createWriteStream";

/* writeSync */
[@bs.send.pipe: t] external writeSync: string => unit = "writeSync";
