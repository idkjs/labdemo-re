[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

open Belt;

open GetComponents;

[@bs.module] external lab : Js.t({..}) = "./labdemo/lab.json";

type keyword = string;

type example = string;

type props = {
  src: option(string),
  w: option(int),
  mt: option(int),
  mb: option(int),
  my: option(int),
  fontSize: option(array(int)),
  fontWeight: option(string),
  color: option(string),
  borderColor: option(string),
  hover: option(hover),
  active: option(active),
}
and hover = {
  opacity: int,
  transition: string,
}
and active = {
  opacity: int,
  transition: string,
};

type style = {
  display: option(string),
  maxWidth: option(string),
  textTransform: option(string),
  letterSpacing: option(string),
  lineHeight: option(string),
  textDecoration: option(string),
  whiteSpace: option(string),
  transition: option(string),
  opacity: option(int),
  height: option(string),
  width: option(string),
  overflow: option(string),
  textAlign: option(string),
};

type componentItem = {
  name: string,
  type_: option(string),
  props: option(props),
  style: option(style),
  examples: array(example),
  system: option(array(string)),
  imports: option(array(string)),
  jsx: option(string),
  keyword: option(array(keyword)),
  description: option(string),
};

module Decode = {
  let decodeProps = json : props => {
    let hover = json : hover =>
      Json.Decode.{
        opacity: json |> field("opacity", int),
        transition: json |> field("transition", string),
      };
    let active = json : active =>
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
  let decodeStyle = json : style =>
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
  let decodeComponent = json : componentItem =>
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
  let components = json : array(componentItem) =>
    json
    |> Json.Decode.array(decodeComponent)
    |> Array.map(_, component => component);
};

let x = lab##components;

let components = x |> Decode.components;

let component = ReasonReact.statelessComponent("LabExample");

let make = _children => {
  ...component,
  render: _self => {
    let components = components;
    let getSvg = StringMap.find("Svg", componentMap);
    Js.log(components);
    <div>
      <h1> (ReasonReact.stringToElement("Components")) </h1>
      <ul>
        (
          Array.map(components, component =>
            <li key=component.name>
              (ReasonReact.stringToElement(component.name))
            </li>
          )
          |> ReasonReact.arrayToElement
        )
      </ul>
      <h1> (ReasonReact.stringToElement("GetComponents")) </h1>
      <div> (ReasonReact.stringToElement(getSvg.name)) </div>
    </div>;
  },
};