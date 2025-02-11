# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

# Altere o nome do projeto
project(Codigo C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Adicione o executável com o novo nome
add_executable(Codigo
        Codigo.c  # Alterado para refletir o novo nome do arquivo
        )

# Pull in common dependencies and additional pwm hardware support
target_link_libraries(Codigo pico_stdlib hardware_pwm)

# Create map/bin/hex file etc.
pico_add_extra_outputs(Codigo)

# Add URL via pico_set_program_url
