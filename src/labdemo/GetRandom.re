open Utils;

open Control;

let getRandom =
  Utils.selectRandomFromList(
    Control.components,
    Control.renderComponentToString(Control.Image),
  );
/*
  /* demostrate what Js.log looks like for array and belt.list */
  let myArray = [|1, 2, 3, 4|];

  let myList = Belt.List.ofArray(myArray);

  Js.log(myList);

  Js.log(myArray);

  output:

  [ 1, [ 2, [ 3, [Array] ] ] ] //myList with belt
 [ 1, 2, 3, 4 ] standard array/ myArray
  */