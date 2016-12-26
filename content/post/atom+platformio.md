+++
description = "Установка и настройка"
date = "2016-12-26T14:28:30+03:00"
title = "Atom+PlatformIO"
draft = true
tags = [
    "Electronis", "Development", "IDE", "Editor"
]
topics = [
    "Development"
]

+++

<!--more-->

## Atom

Ставим редактор [Atom](https://atom.io/).

## Vim mode

Для vim-еров ставим [Vim mode plus](https://atom.io/packages/vim-mode-plus).

...и дополнительно пакет для поддержки минимального набора ex (`:`) команд [ex mode](https://atom.io/packages/vim-mode-plus-ex-mode).

Не забудьте прописать keymap:

```
'atom-text-editor.vim-mode-plus.normal-mode':
  ':': 'vim-mode-plus-ex-mode:open'
  '!': 'vim-mode-plus-ex-mode:toggle-setting'
```

## Оформление

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

## Новый проект

Можно открыть `PlatformIO Home` и выбрать команду создания там.
Можно в панели быстрого доступа `Ctrl+Shift+p` набрать `pio new proj` и вызвать диалог создания непосредственно.

В диалоге выбираем платформы, под которые собирается проект (их может быть несколько) и каталог проекта.

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

Теоретически сборка должна запускаться комбинацией клавиш `Ctrl-Shift-B`, но у меня это не получилось. Видимо какой-то плагин перетянул на себя одеяло.

В прочем, ничего не мешает забиндить свои комбинации на сборку и заливку:

```
'atom-workspace, atom-text-editor':
  'F5': 'platformio-ide:target:upload'
  'F6': 'platformio-ide:target:build'
```

Для заливки проекта в устройство можно воспользоваться быстрой кнопкой в виде стрелки, либо штатной комбинацией `Ctrl-Shift-U`.
Да, можно и нашей новой клавишей `F5`.

Заливка идёт достаточно медленно от того, что по умолчанию скорость заливки 115200 бод.

Что бы раскочегарить процесс, откроем файл `platformio.ini` и добавим
в секцию `[env:nodemcuv2]` строчку `upload_speed = 460800`.
А если железо позволяет, то даже `upload_speed = 921600`.
Хотя в моём случае, повышение скорости порта наоборот увеличело время записи.

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

В появившемся диалоге выбираем порт, на котором висит устройство и скорость соединения (в нашем случае 115200 bod).

После этого откроется монитор. Если нажать кнопку сброса, то увидим мусор (это инициализируется ESP8266) и затем приглашение `Hello ESP8266!`.

Давая команды `on<Enter>` и `off<Enter>` можем включать и выключать светодиод.

