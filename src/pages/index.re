module Styles = {
  open Css;
  open Styling;

  global("body", [margin(px(0))]);
  global("*", [boxSizing(borderBox)]);
  global(
    "h2",
    [
      fontSize(px(32)),
      marginTop(px(0)),
      marginBottom(px(16)),
      Fonts.roboto,
      fontWeight(bold),
      mobileQuery([fontSize(px(24))]),
    ],
  );
  global(
    "p",
    [
      Fonts.merriweather,
      marginBottom(px(0)),
      fontSize(px(14)),
      color(hex("EAEAEA")),
    ],
  );

  let container =
    style([
      display(`flex),
      height(vmin(100.)),
      mobileQuery([height(auto), flexWrap(wrap)]),
    ]);

  let left =
    style([
      display(`flex),
      flexBasis(`percent(60.)),
      alignItems(stretch),
      justifyContent(flexEnd),
      color(white),
      backgroundColor(Colors.darkGray),
      selector(
        "." ++ Logo.Styles.logo,
        [marginBottom(px(45)), mobileQuery([marginBottom(px(32))])],
      ),
      mobileQuery([
        flexGrow(1.),
        justifyContent(center),
        flexBasis(`percent(100.)),
      ]),
    ]);

  let leftContent =
    style([
      width(px(535)),
      paddingTop(px(32)),
      paddingRight(px(80)),
      mobileQuery([
        width(`percent(100.)),
        paddingLeft(px(16)),
        paddingRight(px(16)),
        marginBottom(px(32)),
      ]),
    ]);
  let right =
    style([
      flexBasis(`percent(40.)),
      display(`flex),
      justifyContent(flexStart),
      alignItems(stretch),
      mobileQuery([
        justifyContent(center),
        flexBasis(`percent(100.)),
        flexGrow(1.),
        selector(
          "." ++ SubmitButton.Styles.button,
          [width(`percent(100.))],
        ),
      ]),
    ]);
  let rightContent =
    style([
      width(px(376)),
      paddingLeft(px(24)),
      marginTop(px(115)),
      mobileQuery([
        width(`percent(100.)),
        paddingLeft(px(16)),
        paddingRight(px(16)),
        marginTop(px(32)),
      ]),
    ]);
};

[@react.component]
let make = () => {
  <div className=Styles.container>
    <section className=Styles.left>
      <div className=Styles.leftContent>
        <Logo />
        <h2> "Welcome"->React.string </h2>
        <p>
          "Please tell us a bit about yourself to get started"->React.string
        </p>
      </div>
    </section>
    <section className=Styles.right>
      <div className=Styles.rightContent> <Form /> </div>
    </section>
  </div>;
};

let default = make;