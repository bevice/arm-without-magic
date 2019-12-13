# Нужен cmake >=3.5
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

#Этот дифайн требуется для CMSIS и HAL
ADD_DEFINITIONS(-DSTM32F103xB)

# Если непонятно что происходит - включаем, cmake будет выплевывать в консоль все команды со всеми параметрами
#set(CMAKE_VERBOSE_MAKEFILE YES)

# Подключаем тулчейн для stm32
include(stm32.cmake)

# Название проекта
PROJECT(arm-nomagic-stm32)

# Добавим пути к заголовкам CMSIS
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/drivers/CMSIS/Include/
                    ${CMAKE_CURRENT_SOURCE_DIR}/drivers/CMSIS/Device/ST/STM32F1xx/Include/)


SET(PROJECT_SOURCES
        src/main.c
        src/main.h
        src/startup.c
        src/startup.h
        )


#скрипт линковки и где его искать
SET(LD_SCRIPT stm32f103c8.ld)
SET(LD_SCRIPTS_DIR ${PROJECT_SOURCE_DIR}/ld-scripts/)
SET(CMAKE_EXE_LINKER_FLAGS "-L${LD_SCRIPTS_DIR} -T${LD_SCRIPT} ${CMAKE_EXE_LINKER_FLAGS}")


# Добавляем пути поиска заголовочных файлов
INCLUDE_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}/src/
)

# Собираем исходники пректа, модули, и т.д. в elf
ADD_EXECUTABLE(${CMAKE_PROJECT_NAME}.elf
        ${PROJECT_SOURCES}
        )


# Конвертируем elf в hex и bin
ADD_CUSTOM_COMMAND(TARGET ${CMAKE_PROJECT_NAME}.elf POST_BUILD COMMAND ${CMAKE_OBJCOPY} ARGS -Obinary ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.bin)
ADD_CUSTOM_COMMAND(TARGET ${CMAKE_PROJECT_NAME}.elf POST_BUILD COMMAND ${CMAKE_SIZE} ARGS --format=sysv ${CMAKE_PROJECT_NAME}.elf)
ADD_CUSTOM_COMMAND(TARGET ${CMAKE_PROJECT_NAME}.elf POST_BUILD COMMAND ${CMAKE_SIZE} ARGS --format=berkeley ${CMAKE_PROJECT_NAME}.elf)


# команда make show-symbols 
ADD_CUSTOM_TARGET(show-symbols
	COMMAND ${CMAKE_NM} --print-size -a -n ${CMAKE_PROJECT_NAME}.elf
	DEPENDS ${CMAKE_PROJECT_NAME}.elf
	)
