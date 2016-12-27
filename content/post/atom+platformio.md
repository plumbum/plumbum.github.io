+++
description = "Установка и настройка"
date = "2016-12-26T22:28:30+03:00"
title = "Atom+PlatformIO"
draft = false
tags = [
    "Electronis", "Development", "IDE", "Editor"
]
topics = [
    "Development"
]

+++

Среду разработки для Arduino сложно назвать полноценной средой разработки
по соверменным меркам. Хотя она и содержит в своём составе средства
для управления библиотеками и платформами используемый в ней редактор исходных
кодов очень слаб, да и управление проектами по сути отсутствует.

На выручку нам приходит [PlatformIO](http://platformio.org/). 

<!--more-->

По сути это набор утилит командной строки позволяющих управлять проектами,
библиотеками, сборкой и деплоем в готовые устройства.

Для удобной работы с исходным кодом среда может быть интегрирована в различные
редакторы и IDE, а на базе редактора [Atom](https://atom.io/) создана
собственная [IDE](http://platformio.org/platformio-ide).

На самом деле в *Atom* среда интегрируется посредством пакета, так что
тот же самый функционал можно получить не ставя *PlatformIO IDE*, а установив
нужный пакет в *Atom*.

На мой взгляд вариант с установкой пакета имеет то преимущество, что версии
оригинального *Atom* новее версий *Atom-а* входящего в состав *PlatformIO IDE*.


## Atom

Ставим редактор [Atom](https://atom.io/).

Тут никаких сложностей, просто качаем и устанавливаем пакет для своей системы.

![Welcome atom](https://ipfs.io/ipfs/QmagXg7Y11R1dPbtXby3W1tYSddkAudHKwfQ12rUqH6hSU/atom_welcome.png)


## Vim mode

Для vim-еров ставим [Vim mode plus](https://atom.io/packages/vim-mode-plus).

...и дополнительно пакет для поддержки минимального набора ex (`:`) команд [ex mode](https://atom.io/packages/vim-mode-plus-ex-mode).

Не забудьте прописать keymap:

```
'atom-text-editor.vim-mode-plus.normal-mode':
  ':': 'vim-mode-plus-ex-mode:open'
  '!': 'vim-mode-plus-ex-mode:toggle-setting'
```

Пакет не реализует весь функционал оригинального *vim*, но вполне достаточный,
что-бы чувствовать себя комфортно.

![Install vim mode](https://ipfs.io/ipfs/QmagXg7Y11R1dPbtXby3W1tYSddkAudHKwfQ12rUqH6hSU/install_vim_mode.png)

## Оформление

На мой взгляд тема *Atom-a* резковата.

Мне нравится тема [Lucius dark](https://atom.io/themes/lucius-dark-syntax),

И моноширный шрифт [Input](http://input.fontbureau.com/).
На сайте можно поиграться и собрать шрифт под себя.


## PlatformIO


Ставим пакет [PlatformIO IDE](https://atom.io/packages/platformio-ide).

Ставим пакет терминала [PlatformIO IDE terminal](https://atom.io/packages/platformio-ide-terminal).

PlatformIO IDE предоставляет:

  * поддержку большого количества плат, платформ и фреймворков.
  * Автозавершение кода.
  * Проверку кода на лету.
  * Управление библиотеками.
  * Работа с несколькими проектами.
  * Монитор последовательного порта.

После перезапуска *Atom* видим экран приглашения *PlatformIO* с быстрым доступом
к некоторым командам среды.

![Home screen](https://ipfs.io/ipfs/QmTm9ig4B5gCBe8B6yHZAMTN7tCqydy7r8VKAiDqvD9Zox/platformio_home.png)

Его можно отключить сняв галку `Show PlatformIO Home screen`

## Переход к определению символа

Тут не всё так гладко. Для автокомплита PlatformIO IDE использует пакет [autocomplete clang](https://atom.io/packages/autocomplete-clang).

Он умеет кроме автокомплита переходить к определению символа, а вот возвращаться обратно не умеет (или я не нашел?)

Я переопределил переход на клавишу `F12`.

```
'.workspace':
  'f12': 'autocomplete-clang:go-declaration'
```

Этот способ имеет то преимущество, что позволяет скакать не только по файлам проекта, но и к стандартным библиотекам.

Для удобной навигации по проекту воспользуемся ctags.

Для этого устанавливаем пакет [Atom ctags](https://atom.io/packages/atom-ctags) на замену штаному *symbols-view*.

Ну и можно переопределить под себя клавиатурные сочетания:

```
'atom-text-editor':
  'ctrl-]': 'atom-ctags:go-to-declaration'
  'ctrl-t': 'atom-ctags:return-from-declaration'
  'ctrl-f12':	'atom-ctags:toggle-file-symbols'
  'ctrl-shift-f12':	'atom-ctags:toggle-project-symbols'
  'ctrl-f11':	'atom-ctags:rebuild'
```

Для нормальной работы придётся периодически пересобирать `ctags` (Atom Ctags: Rebuild).

В настройках *Atom ctags* желательно прописать исключения файлов, который не должны попадать в индекс.

```
--exclude=.* --exclude=*.json --exclude=*.yml
```

![Atom ctags cmd args](https://ipfs.io/ipfs/QmRNiHPduVt83NYK95bnEJvDsTUywRGfFAqjeG6PmmhokC/ctags-cmd-args.png)

## Новый проект

Можно открыть `PlatformIO Home` и выбрать команду создания там.
Можно в панели быстрого доступа `Ctrl+Shift+p` набрать `pio new proj` и вызвать диалог создания непосредственно.

В диалоге выбираем платформы, под которые собирается проект (их может быть несколько) и каталог проекта.

![PlatformIO New Project](https://ipfs.io/ipfs/QmXPUdYJUtAocGHp59Zf781MqW11URC55mS5Qshkk9yqs7/pio_new_proj.png)

Я сейчас рассматриваю `NodeMcu`.

Перед нами пустой проект. В каталог `src` складываем наши исходники, в каталог `lib` будут помещены сторонние библиотеки.

Созданим в каталоге `src` файл `main.cpp` следующего содержания:

```cpp
#include <Arduino.h>

#define LED_BUILTIN 16

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
   // wait for a 0.1 second
  delay(100);
}
```

Тот кто уже в теме без сомнения узнал обычную ардуиновскую мигалку.

Что бы собрать проект воспользуемся быстрой кнопкой слева в виде галочки. Она самая верхняя.

![Build project](https://ipfs.io/ipfs/QmTm9ig4B5gCBe8B6yHZAMTN7tCqydy7r8VKAiDqvD9Zox/build.png)

Теоретически сборка должна запускаться комбинацией клавиш `Ctrl-Shift-B`, но у меня это не получилось. Видимо какой-то плагин перетянул на себя одеяло.

В прочем, ничего не мешает забиндить свои комбинации на сборку и загрузку:

```
'atom-workspace, atom-text-editor':
  'F5': 'platformio-ide:target:upload'
  'F6': 'platformio-ide:target:build'
```

Для загрузки проекта в устройство можно воспользоваться быстрой кнопкой в виде стрелки, либо штатной комбинацией `Ctrl-Shift-U`.
Да, можно и нашей новой клавишей `F5`.

![Upload project](https://ipfs.io/ipfs/QmTm9ig4B5gCBe8B6yHZAMTN7tCqydy7r8VKAiDqvD9Zox/upload.png)

Загрузка идёт достаточно медленно от того, что по умолчанию скорость загрузки **115200** бод.

Что бы раскочегарить процесс, откроем файл `platformio.ini` и добавим
в секцию `[env:nodemcuv2]` строчку `upload_speed = 460800`.
А если железо позволяет, то даже `upload_speed = 921600`.
Хотя в моём случае, повышение скорости порта наоборот увеличило время записи.

Подробнее о настройках можно прочитать (в документации)[http://docs.platformio.org/en/stable/platforms/espressif8266.html].

## Терминал

PlatformIO IDE так же позволяет подключиться к последовательному порту, и взаимодействовать с вашей программой.

Модифицируем файл `main.cpp` следующим образом:

```cpp
#include <Arduino.h>

#define LED_BUILTIN 16

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(115200);
  Serial.println("Hello ES8266!");
}

void loop()
{
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd.equalsIgnoreCase(String("on"))) {
      digitalWrite(LED_BUILTIN, LOW);
    } else if (cmd.equalsIgnoreCase(String("off"))) {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    Serial.print("Command: ");
    Serial.println(cmd);
  }
}
```

Соберём и загрузим прошивку в устройство (`Ctrl-Shift-U`).

Вызвать **Serial Monitor** можно либо из левой панели кнопок (кнопка с вилкой) либо комбинацией `Alt-Shift-M`.

![Serial monitor](https://ipfs.io/ipfs/QmP43tCfddGhmpJPMPjRNWENYVmiEWnotYd6f6fWTwjmBh/serial_monitor.png)

В появившемся диалоге выбираем порт, на котором висит устройство и скорость соединения (в нашем случае 115200 bod).

После этого откроется монитор. Если нажать кнопку сброса, то увидим мусор (это инициализируется ESP8266) и затем приглашение `Hello ESP8266!`.

Давая команды `on<Enter>` и `off<Enter>` можем включать и выключать светодиод.

Кстати, *PlatformIO IDE* предоставляет удобную фичу. Нет нужды закрывать монитор
перед загрузкой проект. Среда сама закроет монитор, загрузит проект, и откроет
монитор повторно.
