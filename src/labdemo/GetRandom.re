open Utils;

open Lab;

/* open Control; */
let myList = Belt.List.ofArray(components);

let default = StringMap.find("Svg", componentMap);

Js.log(Utils.selectRandomFromList(myList, default));