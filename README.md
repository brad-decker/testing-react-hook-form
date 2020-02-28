### Form Challenge Submission

Greetings! I enjoyed this challenge a great deal and wanted to give a brief overview of the architectural/framework choices I made.

First, if you've never heard of ReasonML, you might be wondering what these .re files are. ReasonML is syntatic sugar over OCaml, designed to be slightly more friendly for JavaScript engineers to pick up. I believe very strongly that the foundation of any test coverage systems should be a solid static type system. Using types to enforce patterns and API usage is a great way to eliminate those "UGH" bugs like off by ones, null/undefined, etc. I love typescript for this, but ReasonML(and OCaml) is a paradigm changing language. You can actually use your types as code, reacting to what type something is, and the compiler will track that type and warn you when your code isn't behaving as you think it might.

Somethings that'll help as you walk through the code:

1. No import statements. You can "Open" a module so that the contents of that module are in your scope. You can also just reference modules by name and dot syntax.
2. All files are modules, and modules must begin with an uppercase.
3. I have three external reason dependencies in this. When you see "Open Css" i am using bs-css. When you see "Cn.make" this is a reason rewrite of classnames, used to build a css class name string. When you see "React" or "ReactDOMRe" that is part of "ReasonReact" which allows me to write React code with Reason.
4. every is exported from a file by default. This can be controlled but I didn't bother doing that for this challenge.
5. [@react.component] is an annotation that simplifies creating react components with Reason.
6. There are no such thing as class components in reason, everything is a functional component.

#### Directories

1. bindings - Contains a single file that is custom bindings for react-form-state. A binding is strongly typed reason code that interops with JS.
2. components - Individual react components, each containing their own Styles.
3. modules - Contains Styling.re which contains some constants like colors, fonts etc.
4. pages - Next.js pages directory each entry represents a route for next.

#### Building

1. Bucklescript is an ocaml/reason to js compiler. It generates .bs.js files co-located with the .re files.
2. next.config.js includes instructions to read .bs files in the pages folder.
3. next.config.js includes instructions to transpile the reasonml dependencies with babel.
4. Running yarn dev:full will build with bucklescript then run next dev server.
5. Running yarn dev:reason will run bucklescript in watch mode.
6. Running yarn dev will run just next, and is used in conjunction with yarn dev:reason for rapid development.

#### Other Libraries Used

1. bs-css allows for creation of typesafe css. This makes it so that if your styles are written incorrectly your application will not build.
2. react-hook-form - I recently discovered this amazing library for using hooks to take the pain out of form creation. They did not have any Reason bindings so it was also a fun challenge for me to create an interop-layer between reason and this library.
3. Next.js, because I am fluent with it and it is easy for me to setup.
