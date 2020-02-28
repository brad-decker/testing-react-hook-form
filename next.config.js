const withTM = require("next-transpile-modules")(["bs-platform", "bs-css"]);

module.exports = withTM({
  pageExtensions: ["jsx", "js", "bs.js", "tsx"]
});
