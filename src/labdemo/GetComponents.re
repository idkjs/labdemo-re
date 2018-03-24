open Components;

module StringMap = Map.Make(String);

let myList = Belt.List.ofArray(components);

/* List.length(myList) |> Js.log; */
let getComponentMap = myList =>
  List.fold_left(
    (map, user) => StringMap.add(user.name, user, map),
    StringMap.empty,
    myList,
  );

let componentMap = getComponentMap(myList);

Js.log("iterate through & print the components:");

Js.log("--------------------------------------");

componentMap
|> StringMap.iter((id, componentName) =>
     Js.log({j|key:$id, val:$componentName|j})
   );

Js.log("                       ");

Js.log("Find a particular item:");

Js.log("-----------------------");

let getSvg = StringMap.find("Svg", componentMap);

Js.log(Some(getSvg.name));

Js.log(Some(getSvg.type_));

Js.log(StringMap.find("Svg", componentMap));