[@bs.val] external alert: string => unit = "alert";

let firstNameInput =
  ReactHookState.formInput(~required={value: true, message: "REQUIRED"}, ());

let lastNameInput =
  ReactHookState.formInput(~required={value: true, message: "REQUIRED"}, ());
let address1Input =
  ReactHookState.formInput(~required={value: true, message: "REQUIRED"}, ());
let address2Input = ReactHookState.formInput();

module Styles = {
  open Css;

  let form = style([width(`percent(100.))]);
};

[@react.component]
let make = () => {
  let form = ReactHookState.useForm();
  let onSubmit =
    form.handleSubmit(data => {
      alert("Submitted Form Data: " ++ data->Js.Json.stringify);
      ();
    });
  <form onSubmit className=Styles.form>
    <Input
      name="firstName"
      label="First Name"
      inputRef={form.register(firstNameInput)}
      errors={form.errors}
    />
    <Input
      name="lastName"
      label="Last Name"
      inputRef={form.register(lastNameInput)}
      errors={form.errors}
    />
    <Input
      name="address"
      label="Address"
      inputRef={form.register(address1Input)}
      errors={form.errors}
    />
    <Input
      name="address2"
      label="Address 2"
      inputRef={form.register(address2Input)}
      errors={form.errors}
    />
    <SubmitButton />
  </form>;
};