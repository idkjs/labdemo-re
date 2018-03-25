[%bs.raw {|require('./app.css')|}];

[@bs.module] external logo : string = "./logo.svg";

open Belt;

let component = ReasonReact.statelessComponent("App");

let gr = GetRandom.getRandom;

gr |> Js.log;

let make = _children => {
  ...component,
  render: _self => {
    let components = Lab.components;
    /* comment above `components` and uncomment below to test components
    which have been decoded AND typed. Above is just decoded... */
    /* let components = LabTyped.components; */
    let whatever = Lab.StringMap.find(gr, Lab.componentMap);
    let x = DemoVariants.renderer(`Image);
    /* Js.log(components); */
    <div className="App">
    <h1> (ReasonReact.stringToElement("One Random Component")) </h1>
    <div> (ReasonReact.stringToElement(whatever.name)) </div>
    <h1> (ReasonReact.stringToElement("Using Variants?")) </h1>
    <div> (ReasonReact.stringToElement(x.name)) </div>
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
    </div>;
  },
};