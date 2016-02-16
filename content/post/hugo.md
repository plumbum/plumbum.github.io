+++
date = "2016-02-16T13:18:37+03:00"
draft = false
title = "Генератор сайтов Hugo"
tags = [ "Hugo", "Go", "Generator", "Site" ]

+++

Hugo - генератор статичных сайтов подбный [Jekyll](https://jekyllrb.com) написанный на [Go](http://golang.org).

  * [Установка](https://gohugo.io/overview/installing/)
  * [Быстрый старт](https://gohugo.io/overview/quickstart/)
  * [Размещение на Github Pages](https://gohugo.io/tutorials/github-pages-blog/)
  * [Темы оформления](http://themes.gohugo.io/)

Для успешной работы надо ознакомится с [markdown форматированием](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

Hugo позволяет [подсвечивать код](https://gohugo.io/extras/highlighting/)

{{< highlight go >}}
package main

import "fmt"

func main() {
    fmt.Println("Hello world!")
}
{{< /highlight >}}

