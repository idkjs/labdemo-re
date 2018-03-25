module StringMap = Map.Make(String);

let myList = Belt.List.fromArray(Demo.x);

/* let myList = LabDecoder.components; */
/* let myList = DateDemo.c; */
/* List.length(myList) |> Js.log; */
/* using component##name instead of component.name per @keira in reason.chat
   see: https://reasonml.chat/t/using-json-in-reason-with-belt/360/7?u=idkjs
    
   This seems to work when operating straight of the raw json in Demo.x
   If you decode to a record it works with component.name syntax as seen 
   in Lab.components getComponentMap ().
   */
let getComponentMap = myList =>
  List.fold_left(
    (map, component) => StringMap.add(component##name, component, map),
    StringMap.empty,
    myList,
  );

let componentMap = getComponentMap(myList);

/* Js.log(componentMap); */
Js.log("iterate through & print the composers:");

Js.log("--------------------------------------");

componentMap
|> StringMap.iter((name, component) =>
     Js.log({j|key:$name, val:$component|j})
   );

Js.log("                       ");

Js.log("Find a particular item:");

Js.log("-----------------------");

let test = StringMap.find("Image", componentMap);

Js.log(test##name);

Js.log(test##examples);
/* Js.log(StringMap.find("Image", componentMap)); */