+++
date = "2016-03-14T11:25:34+03:00"
title = "EmGo"
description = "Язык для программирования микроконтроллеров с Go-синтаксисом"
draft = false
tags = ["Go", "STM32", "ARM", "MCU", "Embedded"]
topics = ["Electronics"]

+++

[EmGo](https://github.com/ziutek/emgo) - язык для программирования микроконтроллеров с Go-синтаксисом.

<!--more-->

## Установка

Для установки нам потребуется [Go версии 1.6+](https://golang.org/dl/)

Получаем код:

    go get -u -v github.com/ziutek/emgo

Устанавливаем компилятор

    go install -v github.com/ziutek/emgo/egc

Прописываем пременные окружения:

```
export EGCC=/usr/local/arm/gcc-arm-none-eabi/bin/arm-none-eabi-gcc
export EGLD=/usr/local/arm/gcc-arm-none-eabi/bin/arm-none-eabi-ld
export EGAR=/usr/local/arm/gcc-arm-none-eabi/bin/arm-none-eabi-ar

export EGROOT=$HOME/go/src/github.com/ziutek/emgo/egroot
export EGPATH=$HOME/go/src/github.com/ziutek/emgo/egpath
```

Для сборки бинарного файла egc использует gcc тулчейн. Можно взять например этот [GCC ARM Embedded](https://launchpad.net/gcc-arm-embedded)

Я обычно распаковываю его как есть в `/usr/local/arm` и делаю симлинк:

```
cd /usr/local/arm
sudo tar xvf ~/Downloads/gcc-arm-none-eabi-5_2-2015q4-20151219-linux.tar.bz2
sudo ln -s gcc-arm-none-eabi-5_2-2015q4 gcc-arm-none-eabi
```

Так же нужно установить `OpenOCD`, если он ещё не установлен:

    sudo apt-get install openocd

Или можно использовать тулзу [StLink](https://github.com/texane/stlink).


## Прошивка тестового примера

После этого, можно отправится к примерам. Из коробки поддерживается демоборда `F4 Discovery`, которая у меня была под рукоу.

Сразу возьмём что нибудь по-нагляднее <del>с блекджеком и...</del> т.е. с каналами и горутинами:

    cd $EGPATH/src/stm32/examples/f4-discovery/channels

Мне не удалось запустить приложение из RAM, поэтому я отредактировал `script.ld` и заменил строчку

    INCLUDE stm32/loadram

на

    INCLUDE stm32/loadflash

Теперь собираем наше приложение:

    ../build.sh

Если копиляция прошла успешно, получили бинарник в elf-е `cortexm4f.elf`. Прошиваем его в демоплату через OpenOCD:

    ../load-oocd.sh flash

Бинго! Плата начинает нам весело подмигивать всеми четырьмя светодиодами.

## Что дальше?

Дальше изучать [примеры](https://github.com/ziutek/emgo/tree/master/egpath/src/stm32/examples), читать [документацию](https://sites.google.com/site/embeddedgo/) (пока она весьма условна), писать собственные приложения.

