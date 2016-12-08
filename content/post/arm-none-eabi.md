+++
tags = [ "Arm", "Gcc", "Embedded", "Mcu", "Compiler", "Toolchain" ]
topics = [ "Electronics", "Tools" ]
description = "Кросскомпилятор и набор инструментов для микроконтроллеров на базе ARM"
date = "2016-12-08T10:21:32+03:00"
title = "Компилируем для ARM"
draft = false

+++

Как известно, программный код на языке выского уровня сам в микроконтроллер не полезет,
его требуется предварительно скомпилировать в машинный код
(мы не берём интерпретируемые языки, но в этом случае в микроконтроллер должен быть уже прошит интерпретатор).
Для микроконтроллеров на базе ядра ARM/Cortex можно воспользовать кросскопилятором `gcc-arm-none-eabi`.

<!--more-->

Магическое название компилятора `gcc-arm-none-eabi` означает следующее:

  * `gcc` - название компилятора;
  * `arm` - архитектура процессора;
  * `none` - компилятор не вносит никакого дополнительного bootstrap кода от себя;
  * `eabi` - код соответствует спецификации [EABI](https://ru.wikipedia.org/wiki/%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D1%8B%D0%B9_%D0%B8%D0%BD%D1%82%D0%B5%D1%80%D1%84%D0%B5%D0%B9%D1%81_%D0%BF%D1%80%D0%B8%D0%BB%D0%BE%D0%B6%D0%B5%D0%BD%D0%B8%D0%B9).

## GCC ARM Embedded

Самый простой способ, это использовать готовые [бинарные сборки](https://launchpad.net/gcc-arm-embedded) для своей операционной системы. Доступны сборки для Linux, Mac, Windows.

Сборка уже все необходимые инструменты для компиляции ваших приложений а так же адаптированную для встраиваемых устройств стандартную библиотеку функция [newlib](https://sourceware.org/newlib/).

TODO как распаковать и прописать пути.

## Ubuntu

Если у вас Ubuntu 12.04/14.04/15.10/16.04 32/64-bit, то вы можете воспользоваться [PPA репозиторием](https://launchpad.net/~team-gcc-arm-embedded/+archive/ubuntu/ppa).

## Debian

В свою очередь Debian начиная с Jessie содержит в своих репозиториях пакетов сборку `arm-none-eabi-gcc`. Версии пакетов не самые свежие, но как правило вполне достаточные для работы.

Установить полный фарш можно командой:

    sudo apt-get install -t jessie-backports gcc-arm-none-eabi binutils-arm-none-eabi gdb-arm-none-eabi libnewlib-arm-none-eabi libnewlib-dev libstdc++-arm-none-eabi-newlib

Дополнительно можно установить документацию по `newlib`:

    sudo apt-get install -t jessie-backports libnewlib-doc

Обратите внимание на параметр `-t jessie-backports`. В моём случае он означает, что пакеты необходимо устанавливать из репозитория [backports](https://backports.debian.org/), там они новее, чем в stable версии.

