open Utils;

module Styles = {
  open Css;

  let footer =
    style([
      marginTop(2.0->rem),
      paddingBottom(2.0->rem),
      flex(`num(1.0)),
      display(flexBox),
      flexDirection(column),
      justifyContent(flexEnd),
      color(rgb(160, 160, 160)),
    ]);

  let p = style([margin2(~v=0.25->rem, ~h=zero), fontSize(0.8->rem)]);

  let link =
    style([
      fontWeight(extraBold),
      color(hex("63e2ff")),
      textDecoration(none),
    ]);
};

let date = Js.Date.make()->Js.Date.getFullYear->int_of_float->string_of_int;

[@react.component]
let make = () => {
  let buildId =
    switch (Js.Undefined.toOption(Environment.commitRef)) {
    | None => "DEV"
    | Some(buildId) => buildId
    };

  <footer className=Styles.footer>
    <About />
    <p className=Styles.p>
      {{js|Made with 🥃 in Louisville, KY|js} |> React.string}
    </p>
    <p className=Styles.p>
      {"Build ID: " |> React.string}
      {switch (buildId) {
       | "DEV" => "DEV" |> React.string
       | buildId =>
         <a
           className=Styles.link
           href={"https://github.com/sean-clayton/fotup/commit/" ++ buildId}>
           {buildId
            |> Js.String.substring(~from=0, ~to_=7)
            |> React.string}
         </a>
       }}
    </p>
    <p className=Styles.p> {"Copyright " ++ date |> React.string} </p>
  </footer>;
};
