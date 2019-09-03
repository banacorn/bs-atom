open Atom__Type;

include ThemeManager;

/*************************************************************************************************************
  Event Subscription
 ************************************************************************************************************/

/* onDidChangeActiveThemes */
[@bs.val] [@bs.scope ("atom", "themes")]
external onDidChangeActiveThemes: (unit => unit) => Disposable.t =
  "onDidChangeActiveThemes";

/*************************************************************************************************************
  Accessing Loaded Themes
 ************************************************************************************************************/

/* getLoadedThemeNames */
[@bs.val] [@bs.scope ("atom", "themes")]
external getLoadedThemeNames: unit => array(string) = "getLoadedThemeNames";

/* getLoadedThemes */
[@bs.val] [@bs.scope ("atom", "themes")]
external getLoadedThemes: unit => array(theme) = "getLoadedThemes";

/*************************************************************************************************************
  Accessing Active Themes
 ************************************************************************************************************/

/* getActiveThemeNames */
[@bs.val] [@bs.scope ("atom", "themes")]
external getActiveThemeNames: unit => array(string) = "getActiveThemeNames";

/* getActiveThemes */
[@bs.val] [@bs.scope ("atom", "themes")]
external getActiveThemes: unit => array(theme) = "getActiveThemes";

/*************************************************************************************************************
  Managing Enabled Themes
 ************************************************************************************************************/

/* getEnabledThemeNames */
[@bs.val] [@bs.scope ("atom", "themes")]
external getEnabledThemeNames: unit => array(string) = "getEnabledThemeNames";
