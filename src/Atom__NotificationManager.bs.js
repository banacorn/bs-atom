// Generated by BUCKLESCRIPT VERSION 5.0.2, PLEASE EDIT WITH CARE
'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");

function mkOptions(buttons, description, detail, dismissable, $staropt$star, param) {
  var icon = $staropt$star !== undefined ? $staropt$star : "check";
  var tmp = {
    icon: icon
  };
  if (buttons !== undefined) {
    tmp.buttons = Caml_option.valFromOption(buttons);
  }
  if (description !== undefined) {
    tmp.description = Caml_option.valFromOption(description);
  }
  if (detail !== undefined) {
    tmp.detail = Caml_option.valFromOption(detail);
  }
  if (dismissable !== undefined) {
    tmp.dismissable = Caml_option.valFromOption(dismissable);
  }
  return tmp;
}

exports.mkOptions = mkOptions;
/* No side effect */