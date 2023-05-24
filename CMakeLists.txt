cmake_minimum_required(VERSION 3.24)
project(MQTTExample  LANGUAGES CXX)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# 启用Qt的消息记录宏
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE") 
set(CMAKE_CXX_STANDARD 17)
add_executable(MQTTExample test_qtmqtt.cpp )

find_package(Qt6 REQUIRED COMPONENTS Core Mqtt )
target_link_libraries(MQTTExample  PUBLIC Qt::Core Qt::Mqtt)


set_target_properties(MQTTExample PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_compile_definitions(MQTTExample PUBLIC
    QT_DEPRECATED_WARNINGS
)