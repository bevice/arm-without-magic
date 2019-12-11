# Путь к тулчейну
if (DEFINED ENV{ARM_TOOLCHAIN_PATH})
    SET(TOOLCHAIN_DIR $ENV{ARM_TOOLCHAIN_PATH})
else ()
    message(FATAL_ERROR "Please set correct ARM_TOOLCHAIN_PATH environment variable")
endif ()

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)
# Вот это очень важная инструкция, без неё CMAKE будет ругать компилятор,
# за то, что он не умеет собирать helloworld.exe
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)


# Другие полезные пути
SET(TOOLCHAIN_BIN_DIR ${TOOLCHAIN_DIR}/bin)

# если Windows - добавим суффикс .exe ко всем командам. Иначе cmake может их не найти
if (WIN32)
    SET(EXE_SUFFIX ".exe")
else ()
    SET(EXE_SUFFIX "")
endif ()
# Компиляторы
SET(CMAKE_C_COMPILER "${TOOLCHAIN_BIN_DIR}/arm-none-eabi-gcc${EXE_SUFFIX}" CACHE INTERNAL "")
SET(CMAKE_CXX_COMPILER "${TOOLCHAIN_BIN_DIR}/arm-none-eabi-g++${EXE_SUFFIX}" CACHE INTERNAL "")

# Чтобы линковщик пока не линковал лишее - мы будем вызывать таким образом.
SET(CMAKE_LINKER "${TOOLCHAIN_BIN_DIR}/arm-none-eabi-ld${EXE_SUFFIX}" CACHE INTERNAL "")
SET(CMAKE_C_LINK_EXECUTABLE "<CMAKE_LINKER> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")

# Флаги компиляторов, тут можно подкрутить
SET(CMAKE_C_FLAGS "-Wall -mcpu=cortex-m3 -mthumb -std=gnu99" CACHE INTERNAL "c compiler flags")

# objcopy и objdump для создания хексов и бинариков
SET(CMAKE_OBJCOPY "${TOOLCHAIN_BIN_DIR}/arm-none-eabi-objcopy${EXE_SUFFIX}" CACHE INTERNAL "")
SET(CMAKE_OBJDUMP "${TOOLCHAIN_BIN_DIR}/arm-none-eabi-objdump${EXE_SUFFIX}" CACHE INTERNAL "")
SET(CMAKE_SIZE "${TOOLCHAIN_BIN_DIR}/arm-none-eabi-size${EXE_SUFFIX}" CACHE INTERNAL "")

# Пути, где что искать, нам не нужно лишнего.
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Флаги компилятора для разных типов сборки.
SET(COMPILE_DEFINITIONS_DEBUG -O0 -g3 -DDEBUG)
SET(COMPILE_DEFINITIONS_RELEASE -Os)


