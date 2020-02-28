/**
 * It was way easier to just rely on Next's native typescript setup to do this
 * _document page because it uses a class Component and I haven't done a
 * _document page in Reason yet. Using this to just load up our fonts!
 */
import React from "react";
import Document, { Head, Main, NextScript } from "next/document";

const fontUrl =
  "https://fonts.googleapis.com/css?family=Merriweather:400,700|Roboto:400,700&display=swap";

export default class MyDocument extends Document {
  render() {
    return (
      <html lang="en">
        <Head>
          <meta
            name="viewport"
            content="width=device-width initial-scale=1 minimum-scale=1 maximum-scale=1"
          />
          <meta httpEquiv="Accept-CH" content="DPR, Viewport-Width, Width" />
          <link rel="preconnect" href="//fonts.googleapis.com/" />
          <link rel="preload" as="style" href={fontUrl} />
          <link rel="stylesheet" href={fontUrl} />
        </Head>
        <body>
          <div>
            <Main />
          </div>
          <NextScript />
        </body>
      </html>
    );
  }
}
