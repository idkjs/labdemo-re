/* open Components; */

type componentV = [
  | `Image
  | `NavLink
  | `TextLink
  | `BlockLink
  | `Avatar
  | `PageTitle
  | `PageSubtitle
  | `Card
  | `CardImage
  | `CardTitle
  | `CardSubtitle
  | `CardText
  | `CardKicker
  | `CardLink
  | `Container
  | `Svg
  | `DribbbleIcon
  | `TwitterIcon
  | `GitHubIcon
  | `FacebookIcon
  | `InstagramIcon
  | `PinterestIcon
  | `YoutubeIcon
  | `CodepenIcon
  | `VimeoIcon
  | `SnapchatIcon
  | `BehanceIcon
  | `EtsyIcon
  | `KickstarterIcon
  | `ProducthuntIcon
  | `StackoverflowIcon
  | `SlackIcon
  | `NpmIcon
  | `SoundcloudIcon
  | `LinkedinIcon
  | `IconLink
  | `Panel
  | `PanelAlt
  | `PanelTitle
  | `PanelSubtitle
  | `PanelKicker
  | `PanelText
  | `PanelImage
  | `PanelLink
  | `Flexbox
  | `Text
  | `SectionTitle
  | `Div
  | `Caps
  | `Capitalize
  | `PageBG
  | `Center
  | `SiteHeader
  | `HorizontalRule
  | `Tile
  | `TileLink
  | `TileTitle
  | `TileSubtitle
  | `TileKicker
  | `TileText
  | `TileImage
  | `Meta
  | `List
  | `ListItem
  | `ListItemLink
  | `LinkList
  | `Papercraft
  | `Icon
  | `Button
  | `BigButton
  | `CardComposite
];

/* let components = [
     Image,
     NavLink,
     TextLink,
     BlockLink,
     Avatar,
     PageTitle,
     PageSubtitle,
     Card,
     CardImage,
     CardTitle,
     CardSubtitle,
     CardText,
     CardKicker,
     CardLink,
     Container,
     Svg,
     DribbbleIcon,
     TwitterIcon,
     GitHubIcon,
     FacebookIcon,
     InstagramIcon,
     PinterestIcon,
     YoutubeIcon,
     CodepenIcon,
     VimeoIcon,
     SnapchatIcon,
     BehanceIcon,
     EtsyIcon,
     KickstarterIcon,
     ProducthuntIcon,
     StackoverflowIcon,
     SlackIcon,
     NpmIcon,
     SoundcloudIcon,
     LinkedinIcon,
     IconLink,
     Panel,
     PanelAlt,
     PanelTitle,
     PanelSubtitle,
     PanelKicker,
     PanelText,
     PanelImage,
     PanelLink,
     Flexbox,
     Text,
     SectionTitle,
     Div,
     Caps,
     Capitalize,
     PageBG,
     Center,
     SiteHeader,
     HorizontalRule,
     Tile,
     TileLink,
     TileTitle,
     TileSubtitle,
     TileKicker,
     TileText,
     TileImage,
     Meta,
     List,
     ListItem,
     ListItemLink,
     LinkList,
     Papercraft,
     Icon,
     Button,
     BigButton,
     CardComposite,
   ]; */
/* Js.log(Belt.List.length(components)); */
/* let renderIt =
   fun
   | Image => "Image"
   | NavLink => "NavLink"
   | TextLink => "TextLink"
   | BlockLink => "BlockLink"
   | Avatar => "Avatar"
   | PageTitle => "PageTitle"
   | PageSubtitle => "PageSubtitle"
   | Card => "Card"
   | CardImage => "CardImage"
   | CardTitle => "CardTitle"
   | CardSubtitle => "CardSubtitle"
   | CardText => "CardText"
   | CardKicker => "CardKicker"
   | CardLink => "CardLink"
   | Container => "Container"
   | Svg => "Svg"
   | DribbbleIcon => "DribbbleIcon"
   | TwitterIcon => "TwitterIcon"
   | GitHubIcon => "GitHubIcon"
   | FacebookIcon => "FacebookIcon"
   | InstagramIcon => "InstagramIcon"
   | PinterestIcon => "PinterestIcon"
   | YoutubeIcon => "YoutubeIcon"
   | CodepenIcon => "CodepenIcon"
   | VimeoIcon => "VimeoIcon"
   | SnapchatIcon => "SnapchatIcon"
   | BehanceIcon => "BehanceIcon"
   | EtsyIcon => "EtsyIcon"
   | KickstarterIcon => "KickstarterIcon"
   | ProducthuntIcon => "ProducthuntIcon"
   | StackoverflowIcon => "StackoverflowIcon"
   | SlackIcon => "SlackIcon"
   | NpmIcon => "NpmIcon"
   | SoundcloudIcon => "SoundcloudIcon"
   | LinkedinIcon => "LinkedinIcon"
   | IconLink => "IconLink"
   | Panel => "Panel"
   | PanelAlt => "PanelAlt"
   | PanelTitle => "PanelTitle"
   | PanelSubtitle => "PanelSubtitle"
   | PanelKicker => "PanelKicker"
   | PanelText => "PanelText"
   | PanelImage => "PanelImage"
   | PanelLink => "PanelLink"
   | Flexbox => "Flexbox"
   | Text => "Text"
   | SectionTitle => "SectionTitle"
   | Div => "Div"
   | Caps => "Caps"
   | Capitalize => "Capitalize"
   | PageBG => "PageBG"
   | Center => "Center"
   | SiteHeader => "SiteHeader"
   | HorizontalRule => "HorizontalRule"
   | Tile => "Tile"
   | TileLink => "TileLink"
   | TileTitle => "TileTitle"
   | TileSubtitle => "TileSubtitle"
   | TileKicker => "TileKicker"
   | TileText => "TileText"
   | TileImage => "TileImage"
   | Meta => "Meta"
   | List => "List"
   | ListItem => "ListItem"
   | ListItemLink => "ListItemLink"
   | LinkList => "LinkList"
   | Papercraft => "Papercraft"
   | Icon => "Icon"
   | Button => "Button"
   | BigButton => "BigButton"
   | CardComposite => "CardComposite"; */
module StringMap = Map.Make(String);

let cList = Belt.List.ofArray(Components.components);

/* List.length(myList) |> Js.log; */
let getComponentMap = list => {
  open Components;

  List.fold_left(
    (map, component) => StringMap.add(component.name, component, map),
    StringMap.empty,
    list,
  );};

let componentMap = getComponentMap(cList);

/* let renderer = component => 
component
|> renderComponentToString |> StringMap.find(Components.component.name, componentMap);

`Image |> renderer |> Js.log; */
/* let renderer = component => {
  switch ((component: componentV)) {
  | component => StringMap.find(Components.component.name, componentMap)
  | None => Js.log("Cant find that component")
  };
}; */



let renderComponentToString = component =>
  switch (component) {
  | `Image => "Image"
  | `NavLink => "NavLink"
  | `TextLink => "TextLink"
  | `BlockLink => "BlockLink"
  | `Avatar => "Avatar"
  | `PageTitle => "PageTitle"
  | `PageSubtitle => "PageSubtitle"
  | `Card => "Card"
  | `CardImage => "CardImage"
  | `CardTitle => "CardTitle"
  | `CardSubtitle => "CardSubtitle"
  | `CardText => "CardText"
  | `CardKicker => "CardKicker"
  | `CardLink => "CardLink"
  | `Container => "Container"
  | `Svg => "Svg"
  | `DribbbleIcon => "DribbbleIcon"
  | `TwitterIcon => "TwitterIcon"
  | `GitHubIcon => "GitHubIcon"
  | `FacebookIcon => "FacebookIcon"
  | `InstagramIcon => "InstagramIcon"
  | `PinterestIcon => "PinterestIcon"
  | `YoutubeIcon => "YoutubeIcon"
  | `CodepenIcon => "CodepenIcon"
  | `VimeoIcon => "VimeoIcon"
  | `SnapchatIcon => "SnapchatIcon"
  | `BehanceIcon => "BehanceIcon"
  | `EtsyIcon => "EtsyIcon"
  | `KickstarterIcon => "KickstarterIcon"
  | `ProducthuntIcon => "ProducthuntIcon"
  | `StackoverflowIcon => "StackoverflowIcon"
  | `SlackIcon => "SlackIcon"
  | `NpmIcon => "NpmIcon"
  | `SoundcloudIcon => "SoundcloudIcon"
  | `LinkedinIcon => "LinkedinIcon"
  | `IconLink => "IconLink"
  | `Panel => "Panel"
  | `PanelAlt => "PanelAlt"
  | `PanelTitle => "PanelTitle"
  | `PanelSubtitle => "PanelSubtitle"
  | `PanelKicker => "PanelKicker"
  | `PanelText => "PanelText"
  | `PanelImage => "PanelImage"
  | `PanelLink => "PanelLink"
  | `Flexbox => "Flexbox"
  | `Text => "Text"
  | `SectionTitle => "SectionTitle"
  | `Div => "Div"
  | `Caps => "Caps"
  | `Capitalize => "Capitalize"
  | `PageBG => "PageBG"
  | `Center => "Center"
  | `SiteHeader => "SiteHeader"
  | `HorizontalRule => "HorizontalRule"
  | `Tile => "Tile"
  | `TileLink => "TileLink"
  | `TileTitle => "TileTitle"
  | `TileSubtitle => "TileSubtitle"
  | `TileKicker => "TileKicker"
  | `TileText => "TileText"
  | `TileImage => "TileImage"
  | `Meta => "Meta"
  | `List => "List"
  | `ListItem => "ListItem"
  | `ListItemLink => "ListItemLink"
  | `LinkList => "LinkList"
  | `Papercraft => "Papercraft"
  | `Icon => "Icon"
  | `Button => "Button"
  | `BigButton => "BigButton"
  | `CardComposite => "CardComposite"
  };

/* Image |> renderComponentToString |> Js.log; */
/* Js.log2("FROM CONTROL MODULE", renderComponentToString(Image)); */
/* renderIt(`Icon) |> Js.log; */

let renderer = component => 
component
|> renderComponentToString |> StringMap.find(_, componentMap);

`Image |> renderer |> Js.log;

renderer(`Image) |> Js.log;
/* let renderer = component => {
  open Components;
  switch ((component: componentV)) {
  | Some(component) => StringMap.find(component.name, componentMap)
  | None => Js.log("Cant find that component")
  };
}; */
/* let selectRandom = (list, default) =>
  switch (Belt.List.length(list)) {
  | 0 => default
  | length =>
    let randomMaybe = length |> Random.int |> Belt.List.get(list, _);
    switch (randomMaybe) {
    | None => default
    | Some(element) => renderIt(element)
    };
  };

selectRandom(components, renderIt(Icon)) |> Js.log; */