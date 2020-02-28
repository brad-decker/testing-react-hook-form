module Styles = {
  open Css;
  let logo = style([width(px(177))]);
};

[@react.component]
let make = () => {
  <img src="/logo.svg" className=Styles.logo />;
};