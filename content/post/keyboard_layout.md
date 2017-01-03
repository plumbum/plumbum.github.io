+++
date = "2016-06-14T11:00:00+03:00"
title = "Настройка раскладок клавиатуры"
description = ""
draft = false
tags = ["Linux", "Keyboard", "X11"]
topics = ["Linux", "Tips"]

+++

Настройка раскладок клавиатуры в X11/Xorg

<!--more-->

## Просмотр текущих опций

    $ setxkbmap -query
    rules:      evdev
    model:      pc105
    layout:     us,ru
    variant:    ,
    options:    ctrl:nocaps,grp:alt_shift_toggle,grp_led:scroll

## Установка новых значений

    $ setxkbmap -option -option "ctrl:nocaps,grp:alt_shift_toggle,grp_led:scroll"

Двойной `-option` нужен, что бы стереть старые опции.
Если указать только один `-option`, то значения будут дописаны к существующим.


