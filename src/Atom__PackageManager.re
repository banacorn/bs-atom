open Atom__Type;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

type htmlStyleElement;

/* onDidLoadInitialPackages */
[@bs.val] [@bs.scope ("atom", "packages")]
external onDidLoadInitialPackages: (unit => unit) => Disposable.t =
  "onDidLoadInitialPackages";

/* onDidActivateInitialPackages */
[@bs.val] [@bs.scope ("atom", "packages")]
external onDidActivateInitialPackages: (unit => unit) => Disposable.t =
  "onDidActivateInitialPackages";

/* onDidActivatePackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external onDidActivatePackage: (Package.t => unit) => Disposable.t =
  "onDidActivatePackage";

/* onDidDeactivatePackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external onDidDeactivatePackage: (Package.t => unit) => Disposable.t =
  "onDidDeactivatePackage";

/* onDidLoadPackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external onDidLoadPackage: (Package.t => unit) => Disposable.t =
  "onDidLoadPackage";

/* onDidUnloadPackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external onDidUnloadPackage: (Package.t => unit) => Disposable.t =
  "onDidUnloadPackage";

/*************************************************************************************************************
  Package system data
 ************************************************************************************************************/

/* getApmPath */
[@bs.val] [@bs.scope ("atom", "packages")]
external getApmPath: unit => string = "getApmPath";

/* getPackageDirPaths */
[@bs.val] [@bs.scope ("atom", "packages")]
external getPackageDirPaths: unit => array(string) = "getPackageDirPaths";

/*************************************************************************************************************
  General package data
 ************************************************************************************************************/

/* resolvePackagePath */
[@bs.val] [@bs.scope ("atom", "packages")]
external resolvePackagePath: string => option(string) = "resolvePackagePath";

/* isBundledPackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external isBundledPackage: string => bool = "isBundledPackage";

/*************************************************************************************************************
  Enabling and disabling packages
 ************************************************************************************************************/

/* enablePackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external enablePackage: string => Js.Nullable.t(Package.t) = "enablePackage";

/* disablePackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external disablePackage: string => Js.Nullable.t(Package.t) =
  "disablePackage";

/* isPackageDisabled */
[@bs.val] [@bs.scope ("atom", "packages")]
external isPackageDisabled: unit => bool = "isPackageDisabled";

/*************************************************************************************************************
  Accessing active packages
 ************************************************************************************************************/

/* getActivePackages */
[@bs.val] [@bs.scope ("atom", "packages")]
external getActivePackages: unit => array(Package.t) = "getActivePackages";

/* getActivePackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external getActivePackage: string => option(Package.t) = "getActivePackage";

/* isPackageActive */
[@bs.val] [@bs.scope ("atom", "packages")]
external isPackageActive: string => bool = "isPackageActive";

/* hasActivatedInitialPackages */
[@bs.val] [@bs.scope ("atom", "packages")]
external hasActivatedInitialPackages: unit => bool =
  "hasActivatedInitialPackages";

/*************************************************************************************************************
  Accessing loaded packages
 ************************************************************************************************************/

/* getLoadedPackages */
[@bs.val] [@bs.scope ("atom", "packages")]
external getLoadedPackages: unit => array(Package.t) = "getLoadedPackages";

/* getLoadedPackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external getLoadedPackage: string => option(Package.t) = "getLoadedPackage";

/* isPackageLoaded */
[@bs.val] [@bs.scope ("atom", "packages")]
external isPackageLoaded: string => bool = "isPackageLoaded";

/* hasLoadedInitialPackages */
[@bs.val] [@bs.scope ("atom", "packages")]
external hasLoadedInitialPackages: unit => bool = "hasLoadedInitialPackages";

/*************************************************************************************************************
  Accessing available packages
 ************************************************************************************************************/

/* getAvailablePackagePaths */
[@bs.val] [@bs.scope ("atom", "packages")]
external getAvailablePackagePaths: unit => array(string) =
  "getAvailablePackagePaths";

/* getAvailablePackageNames */
[@bs.val] [@bs.scope ("atom", "packages")]
external getAvailablePackageNames: unit => array(string) =
  "getAvailablePackageNames";

/* getAvailablePackageMetadata */
[@bs.val] [@bs.scope ("atom", "packages")]
external getAvailablePackageMetadata: unit => array(string) =
  "getAvailablePackageMetadata";

/*************************************************************************************************************
  Activate/Deactivate packages
 ************************************************************************************************************/

/* loadPackages */
[@bs.val] [@bs.scope ("atom", "packages")]
external loadPackages: unit => unit = "loadPackages";

/* loadPackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external loadPackage: string => Package.t = "loadPackage";

/* activatePackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external activatePackage: string => Js.Promise.t(unit) = "activatePackage";

/* deactivatePackage */
[@bs.val] [@bs.scope ("atom", "packages")]
external deactivatePackage: (string, bool) => Js.Promise.t(unit) =
  "deactivatePackage";
