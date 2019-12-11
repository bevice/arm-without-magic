
# STM32 Без Магии

## Toolchain
Для сборки необходимо прописать переменную среды  ```ARM_TOOLCHAIN_PATH``` с путем к 
тулчейну, скаченному с https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads

Так же потребуется cmake версии не менее 3.5 (https://cmake.org)
и утилита make, для OS Windows можно использовать из комплекта GnuWin32:
http://gnuwin32.sourceforge.net/packages/make.htm, скачать можно по ссылкам:
http://gnuwin32.sourceforge.net/downlinks/make-bin-zip.php
http://gnuwin32.sourceforge.net/downlinks/make-dep-zip.php

Для отладки потребуется Open On-Chip Debuger (https://gnutoolchains.com/arm-eabi/openocd/) 
и любой поддеживаемый отладчик (ST-Link, J-Link), а так же отладочная плата на чипе STM32F103C8, например Blue-Pill 
## Сборка проекта
Из любой временной папки запускаем 
* ```cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" /путь/до/корня/проекта```
* ```make```

## Запуск проекта
* Запустить OpenOCD: ```openocd -f OOCD/oocd_stlink_v2.cfg```
* Запустить отладчик: ```arm-none-eabi-gdb arm-nomagic-stm32.elf```
* В консоли отладчика подключиться к OpenOCD: ```target remote 127.0.0.1:3333```
* Выполнить остановку процессора ```monitor reset halt```
* Загрузить прошивку ```load```
* Выполнить инициализацию процессора ```monitor reset init```
* Шагать по строкам командой ```step``` и смотреть как процессор работает и моргает светодиодом