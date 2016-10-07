+++
date = "2016-02-16T13:18:37+03:00"
draft = false
title = "Генератор сайтов Hugo"
tags = [ "Hugo", "Go", "Generator", "Site", "Html" ]
topics = ["Hugo", "Tools"]

+++

Hugo - генератор статичных сайтов  подбный [Jekyll](https://jekyllrb.com) и написанный на языке программирования [Go](http://golang.org).

<!--more-->

## Документация
  * [Установка](https://gohugo.io/overview/installing/)
  * [Быстрый старт](https://gohugo.io/overview/quickstart/)
  * [Размещение на Github Pages](https://gohugo.io/tutorials/github-pages-blog/)
  * [Темы оформления](http://themes.gohugo.io/)
  * [Шаблоны страниц](https://gohugo.io/templates/go-templates/)
  * [Переменные шаблонов](https://gohugo.io/templates/variables/)

Для успешной работы надо ознакомится с [markdown форматированием](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

## Подстветка

Hugo позволяет [подсвечивать код](https://gohugo.io/extras/highlighting/)

{{< highlight go >}}
package main

import "fmt"

func main() {
    fmt.Println("Hello world!")
}
{{< /highlight >}}

## Tips

Метатег `<!--more-->` отрезает текст и вставляет ссылку "Read more".

