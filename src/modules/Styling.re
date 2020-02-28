open Css;

module Colors = {
  let error = hex("E70000");
  let focus = hex("00ADEE");
  let idleOutline = hex("EAEAEA");
  let idleBackground = hex("F7F7F7");
  // Sorry, couldn't resist the combo of 666 + hex
  let theDevilsColor = hex("666");
  let darkGray = hex("585858");
  let action = hex("FFAB44");
};

module Fonts = {
  let merriweather = fontFamily("Merriweather");
  let roboto = fontFamily("Roboto");
};

let mobileQuery = media("(max-width: 912px)");
let desktopQuery = media("(min-width: 913px)");

let createInsideOutlne = color =>
  boxShadow(
    Shadow.box(
      ~x=px(0),
      ~y=px(0),
      ~blur=px(0),
      ~spread=px(1),
      ~inset=true,
      color,
    ),
  );