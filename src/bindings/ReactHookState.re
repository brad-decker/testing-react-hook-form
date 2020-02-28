type formInputOptions('a) = {
  value: 'a,
  message: string,
};

[@bs.deriving jsConverter]
type validationType = [
  | [@bs.as "required"] `required
  | [@bs.as "min"] `min
  | [@bs.as "max"] `max
  | [@bs.as "noop"] `noop
];

type validationError = {
  validationType,
  message: string,
};

[@bs.deriving abstract]
type formInput = {
  [@bs.optional]
  required: formInputOptions(bool),
  [@bs.optional]
  min: formInputOptions(int),
  [@bs.optional]
  max: formInputOptions(int),
  [@bs.optional]
  minLength: formInputOptions(int),
  [@bs.optional]
  maxLength: formInputOptions(int),
  [@bs.optional]
  pattern: formInputOptions(Js.Re.t),
};

[@bs.deriving jsConverter]
type validationErrorExt = {
  [@bs.as "type"]
  type_: string,
  message: string,
};

type hookReturnExt = {
  register: (Js.Nullable.t(Dom.element), formInput) => unit,
  handleSubmit: (Js.Json.t => unit, ReactEvent.Form.t) => unit,
  errors: Js.Dict.t(validationErrorExt),
  getValues: unit => Js.Dict.t(string),
  formState: Js.Dict.t(string),
};

type form = {
  register: formInput => ReactDOMRe.domRef,
  handleSubmit: (Js.Json.t => unit, ReactEvent.Form.t) => unit,
  errors: Js.Dict.t(validationError),
  getValues: unit => Js.Dict.t(string),
  formState: Js.Dict.t(string),
};

[@bs.deriving abstract]
type useFormOptions = {
  [@bs.optional]
  mode: string,
  [@bs.optional]
  reValidateMode: string,
};

[@bs.module "react-hook-form"]
external useFormExt: useFormOptions => hookReturnExt = "useForm";

let defaultOpts =
  useFormOptions(~mode="onBlur", ~reValidateMode="onBlur", ());

let useForm = (~options=defaultOpts, ()) => {
  let formExt = useFormExt(options);
  let register = (input: formInput) => {
    ReactDOMRe.Ref.callbackDomRef(ref => {formExt.register(ref, input)});
  };
  let errors =
    formExt.errors
    ->Js.Dict.entries
    ->Belt.Array.map(((key, err)) => {
        let validationType =
          switch (err.type_) {
          | "required" => `required
          | "min" => `min
          | "max" => `max
          | _ => `noop
          };
        (key, {validationType, message: err.message});
      })
    ->Js.Dict.fromArray;
  {
    errors,
    register,
    handleSubmit: formExt.handleSubmit,
    getValues: formExt.getValues,
    formState: formExt.formState,
  };
};