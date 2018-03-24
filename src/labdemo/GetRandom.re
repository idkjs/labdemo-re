open Utils;

open Control;

let getRandom =
  Utils.selectRandomFromList(
    Control.components,
    Control.renderComponentToString(Control.Image),
  );