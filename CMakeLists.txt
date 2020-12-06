cmake_minimum_required(VERSION 3.17)
project(AdventOfCode2020)

set(CMAKE_CXX_STANDARD 17)

add_executable(AoC-01 01/main.cpp 01/main.h)
add_custom_command(TARGET AoC-01 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/01/input $<TARGET_FILE_DIR:AoC-01>/)

add_executable(AoC-02 02/main.cpp 02/main.h)
add_custom_command(TARGET AoC-02 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/02/input $<TARGET_FILE_DIR:AoC-02>/)

add_executable(AoC-03 03/main.cpp 03/main.h)
add_custom_command(TARGET AoC-03 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/03/input $<TARGET_FILE_DIR:AoC-03>/)

add_executable(AoC-04 04/main.cpp 04/main.h)
add_custom_command(TARGET AoC-04 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/04/input $<TARGET_FILE_DIR:AoC-04>/)

add_executable(AoC-05 05/main.cpp 05/main.h)
add_custom_command(TARGET AoC-05 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/05/input $<TARGET_FILE_DIR:AoC-05>/)

add_executable(AoC-06 06/main.cpp 06/main.h)
add_custom_command(TARGET AoC-06 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/06/input $<TARGET_FILE_DIR:AoC-06>/)

add_executable(AoC-07 07/main.cpp 07/main.h)
add_custom_command(TARGET AoC-07 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/07/input $<TARGET_FILE_DIR:AoC-07>/)

