/* [@bs.module] external labJson : Js.t({..}) = "./labdemo/lab.json";
/* [@bs.module] external labJson : Js.Json.t = "./labdemo/lab.json"; */

/*
 need to set this up to get values back from option
  */
/* open Js.Option;

module Option = {
  let optionMap = (fn, opt) =>
    switch (opt) {
    | Some(x) => fn(x) |> some
    | None => None
    };
  let optionWithDefault = (defaultValue, opt) =>
    switch (opt) {
    | Some(x) => x
    | None => defaultValue
    };
}; */

module Decoder = {
  let decodeLayout = json : Types.layout =>
    Json.Decode.{
      i: field("i", string, json),
      name: field("name", string, json),
      w: field("w", int, json),
      h: field("h", int, json),
      x: field("x", int, json),
      y: field("y", int, json),
      moved: json |> optional(field("moved", bool)),
      static: json |> optional(field("static", bool)),
    };
  let decodeProps = json : Types.props => {
    let hover = json : Types.hover =>
      Json.Decode.{
        opacity: json |> field("opacity", int),
        transition: json |> field("transition", string),
      };
    let active = json : Types.active =>
      Json.Decode.{
        opacity: json |> field("opacity", int),
        transition: json |> field("transition", string),
      };
    Json.Decode.{
      src: json |> optional(field("src", string)),
      w: json |> optional(field("w", int)),
      mt: json |> optional(field("mt", int)),
      mb: json |> optional(field("mb", int)),
      my: json |> optional(field("my", int)),
      fontSize: json |> optional(field("fontSize", Json.Decode.array(int))),
      fontWeight: json |> optional(field("fontWeight", string)),
      color: json |> optional(field("colors", string)),
      borderColor: json |> optional(field("borderColor", string)),
      hover: json |> optional(field("hover", hover)),
      active: json |> optional(field("active", active)),
    };
  };
  let decodeStyle = json : Types.style =>
    Json.Decode.{
      display: json |> optional(field("display", string)),
      maxWidth: json |> optional(field("maxWidth", string)),
      textTransform: json |> optional(field("textTransform", string)),
      letterSpacing: json |> optional(field("letterSpacing", string)),
      lineHeight: json |> optional(field("lineHeight", string)),
      textDecoration: json |> optional(field("textDecoration", string)),
      whiteSpace: json |> optional(field("whiteSpace", string)),
      transition: json |> optional(field("transition", string)),
      opacity: json |> optional(field("opacity", int)),
      height: json |> optional(field("height", string)),
      width: json |> optional(field("width", string)),
      overflow: json |> optional(field("overflow", string)),
      textAlign: json |> optional(field("textAlign", string)),
    };
  let decodeComponent = json : Types.component =>
    Json.Decode.{
      name: field("name", string, json),
      type_: json |> optional(field("type", string)),
      props: json |> optional(field("props", Json.Decode.(decodeProps))),
      style: json |> optional(field("style", Json.Decode.(decodeStyle))),
      examples: json |> field("examples", Json.Decode.array(string)),
      system: json |> optional(field("system", Json.Decode.array(string))),
      jsx: json |> optional(field("jsx", string)),
      keyword:
        json |> optional(field("keyword", Json.Decode.array(string))),
      imports:
        json |> optional(field("imports", Json.Decode.array(string))),
      description: json |> optional(field("description", string)),
    };
  let decodeLab = json : Types.lab =>
    Json.Decode.{
      name: json |>field("name", string),
      library: json |>field("library", string),
      layout: json |>field("layout", Json.Decode.array(decodeLayout)),
      components:
      json |>field("components", Json.Decode.list(decodeComponent)),
    };
  let defaultErrorMsg = "-- unknown value --";
};

let lab = labJson |> Decoder.decodeLab;

let components: list(Types.component) = lab.components;
/* let components = lab.components; */
/* components |> Js.log(_); */

module StringMap = Map.Make(String);

/* let myList = Belt.List.ofArray(components); */
let myList = components;

/* List.length(myList) |> Js.log; */
let getComponentMap = myList =>
  List.fold_left(
    (map, component) => StringMap.add(component##name, component, map),
    StringMap.empty,
    myList,
  );

let componentMap = getComponentMap(myList); */