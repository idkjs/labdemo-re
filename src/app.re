[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

open Belt;

open GetComponents;

let component = ReasonReact.statelessComponent("LabExample");

let make = _children => {
  ...component,
  render: _self => {
    let components = Lab.components;
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