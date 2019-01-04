module Option = {
  let unwrapUnsafely =
    fun
    | Some(v) => v
    | None => raise(Invalid_argument("unwrapUnsafely called on None"));
};

module DataTransfer = {
  type dropEffect = string;

  type effectAllowed = string;

  type file = Webapi.File.t;

  type files = array(file);

  type item = {kind: string};

  type items = array(item);

  [@bs.deriving jsConverter]
  type dataTransfer = {
    dropEffect,
    effectAllowed,
    files,
    items,
  };
};

module FormData = {
  [@bs.new] external create: unit => Js.t('a) = "FormData";
  [@bs.send] external set: (Js.t('a), string, 'a) => Js.t('a) = "set";
};

[@bs.val] [@bs.scope ("window", "location")]
external href: Js.t('a) = "href";

let redirect = newPath => {
  let href = ref(href);
  href := newPath;
};
