module Styles = {
  open Css;
  open Styling;

  let button =
    style([
      color(white),
      Fonts.roboto,
      fontWeight(bold),
      fontSize(px(16)),
      unsafe("border", "none"),
      paddingLeft(px(24)),
      paddingRight(px(24)),
      height(px(48)),
      borderRadius(px(6)),
      backgroundColor(Colors.action),
      cursor(`pointer),
    ]);

  let text = style([marginRight(px(8))]);
  let arrow = style([height(px(10)), width(px(10))]);
};
[@react.component]
let make = () => {
  <button className=Styles.button type_="submit">
    <span className=Styles.text> "Next"->React.string </span>
    <img className=Styles.arrow src="/white-arrow.svg" />
  </button>;
};