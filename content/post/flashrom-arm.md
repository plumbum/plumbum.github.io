+++
date = "2016-05-12T16:18:49+03:00"
description = "Сборка flashrom под ARM на примере OrangePi One"
draft = true
tags = ["ARM", "Build", "OrangePi", "RaspberryPi", "Linux", "Spi", "SpiFlash"]
title = "Используем flashrom"
topics = []

+++

Для прошивки SPI Flash можно пользоваться специализированными программаторами
но при отсутствии таковых можно применить случайно оказавшийся под рукой микрокомпьютер с Linux на борту.
Например OrangePi One с [Armbian](http://www.armbian.com/orange-pi-one/).

Можно воспользоваться так же [RaspberryPi](https://www.flashrom.org/RaspberryPi).

## Подключение

**Внимание!** все соединения необходимо производить при отключенном питании.

Так что сделаем это заранее.

**Здесь должно быть фото**

**А здесь табличка**


## Сборка

Качаем свежие исходники [flashrom](https://www.flashrom.org/Downloads). На данный момент это версия [0.9.9](http://download.flashrom.org/releases/flashrom-0.9.9.tar.bz2).

Распаковываем полученный файл:

```
# tar xvf flashrom-0.9.9.tar.bz2
# cd flashrom-0.9.9
```

В armbian уже установлен компилятор, так что можем сразу запустить сборку:

```
# make CONFIG_ENABLE_LIBPCI_PROGRAMMERS=no CONFIG_ENABLE_LIBUSB1_PROGRAMMERS=no
```

Параметры указывают не использовать PCI и USB программаторы.

Если же поддержка USB программаторов нужна, то предварительно установим библиотеку для работы с USB:

```
# apt-get install libusb-1.0-0-dev
```

И библиотеку для работы с устройствами на базе FTDI если ваш программатор основан на этой микросхеме:

```
# apt-get install libftdi-dev
```

И соберём:

```
# make CONFIG_ENABLE_LIBPCI_PROGRAMMERS=no
```

В случае успеха у нас появится бинарный файл.

```
# ls -l flashrom
-rwxr-xr-x 1 root root 322308 May 12 15:45 flashrom
# file flashrom
flashrom: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux-armhf.so.3, for GNU/Linux 2.6.32, BuildID[sha1]=69769b4071bbff19ebe936fecb11fe36a0cc5c5f, not stripped
```

## Прошивка

Для начала проверим видит ли программатор подключённый чип.

```
# flashrom -p linux_spi:dev=/dev/spidev0.0
flashrom v0.9.9-r1955 on Linux 3.4.112-sun8i (armv7l)
flashrom is free software, get the source code at https://flashrom.org

Calibrating delay loop... OK.
No EEPROM/flash device found.
Note: flashrom can never write if the flash chip isn't found automatically.
```

```
# flashrom -p linux_spi:dev=/dev/spidev0.0 
flashrom v0.9.9-r1955 on Linux 3.4.112-sun8i (armv7l)
flashrom is free software, get the source code at https://flashrom.org

Calibrating delay loop... OK.
Found Spansion flash chip "S25FL032A/P" (4096 kB, SPI) on linux_spi.
No operations were specified.
```

TODO чтение

TODO запись

## На сладкое

Во flashrom наконец добавили поддержку "народного" программатора на базе микросхемы `CH341A`

```
Supported USB devices for the ch341a_spi programmer:
Vendor            Device   USB IDs    Status
Winchiphead (WCH) CH341A   1a86:5512  OK
```

К сожалению поддерживается только SPI но не I2C.

