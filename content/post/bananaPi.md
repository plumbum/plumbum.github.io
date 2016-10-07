+++
date = "2016-02-17"
title = "Banana Pi"
description = "одноплатный компьютер"
draft = false
tags = ["ARM", "MCU", "Embedded", "Raspberry", "Linux"]
topics = ["Electronics"]

+++

Banana Pi — семейство одноплатных компьютеров на базе микроконтроллеров с ядром ARM производства Allwinner.

Может работать под управлением различных операционных систем: Android 4.2, Android 4.4, Lubuntu, Raspbian, Debian, Fedora, Arch Linux, Gentoo, openSUSE, Berryboot, FreeBSD, OpenWrt, Slackware, Tiny Core Linux.

<!--more-->

## Links

  * http://www.armbian.com/banana-pi/
  * https://www.bananian.org/details
  * https://www.bananian.org/download

## User-Define LED (Green)

Управляем светодиодом через GPIO:

    $ echo gpio > /sys/class/leds/green\:ph24\:led1/trigger
    $ echo 255 > /sys/class/leds/green:ph24:led1/brightness # On
    $ echo 255 > /sys/class/leds/green:ph24:led1/brightness # Off

Отключить триггер:

    $ echo none > /sys/class/leds/green\:ph24\:led1/trigger

Посмотреть все доступные триггеры

    $ cat /sys/class/leds/green\:ph24\:led1/trigger
    none battery-charging-or-full battery-charging battery-charging-or-full
    battery-charging-blink-full-solid ac-online usb-online mmc0 timer
    heartbeat backlight [gpio] cpu0 cpu1 default-on

