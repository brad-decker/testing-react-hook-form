module Styles = {
  open Css;
  open Styling;

  // boxshadow outlines!
  let grayInsideOutline = createInsideOutlne(Colors.idleOutline);
  let errorInsideOutline = createInsideOutlne(Colors.error);
  let focusedInsideOutline = createInsideOutlne(Colors.focus);

  let container = style([marginBottom(px(24))]);

  let label =
    style([
      color(Colors.theDevilsColor),
      fontSize(px(12)),
      marginBottom(px(10)),
      marginRight(px(10)),
      Fonts.merriweather,
      textTransform(uppercase),
      display(inlineBlock),
    ]);

  let errorMessage = merge([label, style([color(Colors.error)])]);

  let error = style([errorInsideOutline]);
  let idle =
    style([backgroundColor(Colors.idleBackground), grayInsideOutline]);
  let focus = style([focusedInsideOutline]);

  let colorError = style([color(Colors.error)]);

  let input =
    style([
      width(`percent(100.)),
      unsafe("border", "none"),
      backgroundImage(none),
      borderRadius(px(6)),
      padding(px(16)),
      selector("&:focus", [unsafe("outline", "none")]),
    ]);
};

type state =
  | Focused
  | Error(string)
  | Idle;

let update =
    (
      ~error: option(ReactHookState.validationError)=?,
      ~blur=false,
      previousState,
    ) => {
  switch (error, previousState) {
  | (Some(err), Focused)
  | (Some(err), Idle) => Error(err.message)
  | (None, Error(_)) => Idle
  | (None, Focused) when blur => Idle
  | (_, _) => previousState
  };
};

[@react.component]
let make =
    (
      ~name,
      ~label,
      ~inputRef,
      ~errors: Js.Dict.t(ReactHookState.validationError),
    ) => {
  let error = errors->Js.Dict.get(name);

  let (state, setState) =
    React.useState(() => {
      switch (error) {
      | Some(err) => Error(err.message)
      | None => Idle
      }
    });
  React.useEffect1(
    () => {
      setState(update(~error?, ~blur=false));
      None;
    },
    [|error|],
  );
  let inputClass =
    Cn.make([
      Styles.input,
      switch (state) {
      | Focused => Styles.focus
      | Error(_) => Styles.error
      | Idle => Styles.idle
      },
    ]);
  let onFocus = _ => {
    setState(_ => Focused);
  };
  let onBlur = _ => {
    setState(update(~error?, ~blur=true));
  };
  <div className=Styles.container>
    <label className=Styles.label htmlFor=name>
      {(label ++ " ")->React.string}
    </label>
    {switch (error) {
     | Some(err) =>
       <span className=Styles.errorMessage> err.message->React.string </span>
     | None => React.null
     }}
    <br />
    <input className=inputClass name ref=inputRef onFocus onBlur />
  </div>;
};