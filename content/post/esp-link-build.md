+++
date = "2016-02-17T12:45:47+03:00"
description = ""
draft = true
tags = ["esp8266", "http", "serial", "toolchain"]
title = "ESP-link - сервер последовательного порта"
topics = ["Electronics"]

+++

[ESP-link](https://github.com/jeelabs/esp-link) это WiFi-Serial мост на базе ESP8266 с дополнительными возможностями:

<!--more-->

  * Программатор микроконтроллеров AVR, микроконтроллеров NXP серии LPC800, а так же модулей ESP8266
  * Программатор STK500v1 с загрузкой hex-файлов через HTTP
  * Проброс REST HTTP запросов от микроконтроллера в интернет
  * Отправка и получение MQTT запросов

Сборка тулчейна
---------------

В первую очередь нам необходимо собрать тулчейн [ESP Open SDK](https://github.com/pfalcon/esp-open-sdk)

Здесь и далее рассматриваем сборку под Linux.

Подготавливаем каталог:

~~~
mkdir -p $HOME/src/esp
cd $HOME/src/esp
~~~

[Устанавлинваем необходимые зависимости](https://github.com/pfalcon/esp-open-sdk#debianubuntu).

Получаем исходный код:

~~~
git clone --recursive https://github.com/pfalcon/esp-open-sdk.git
cd esp-open-sdk
~~~

Собираем тулчейн

~~~
make
~~~

Установка проприетарного SDK
----------------------------

Для нормальной сборки нам всё равно понадобятся части проприетарного SDK

[Скачать](http://bbs.espressif.com/viewtopic.php?f=46&t=850) его можно на форуме Espressif-а.


Вернёмся в наш основной каталог и распакуем SDK:

~~~
cd $HOME/src/esp
unzip ESP8266_NONOS_SDK_V1.5.2_16_01_29.zip
~~~

Понятно, что имя полученного вами SDK может отличаться от приведённого.

Сейчас есть одна тонкость. Esp-link хочет версию 1.5.1, последняя версия 1.5.2.
Просто сделаем симлинк:

~~~
ln -s esp_iot_sdk_v1.5.2 esp_iot_sdk_v1.5.1
~~~

Сборка Esp-link
---------------

Теперь получим исходные коды:

~~~
git clone https://github.com/jeelabs/esp-link.git
~~~

Перейдём в каталог:

~~~
cd esp-link
~~~

И соберём прошивку:

~~~
make
~~~

В случае успеха файлы прошивки будут лежать в каталоге `firmware`.

