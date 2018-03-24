open Belt;

let selectRandomFromList = (list, default) =>
  switch (List.length(list)) {
  | 0 => default
  | length =>
    let randomMaybe = length |> Random.int |> List.get(list, _);
    switch (randomMaybe) {
    | None => default.name
    | Some(element) => Js.log(element)
    };
  };
/* let selectRandomFromList = (list, default) =>
   switch (List.length(list)) {
   | 0 => default
   | length =>
     let randomMaybe = length |> Random.int |> List.get(list, _);
     switch (randomMaybe) {
     | None => default
     | Some(element) => Control.renderComponentToString(element)
     };
   }; */