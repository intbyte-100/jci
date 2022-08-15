cmake_minimum_required(VERSION 3.2)

project(jci_native)


set(SOURCES src/jci.c)

# dynasm toolchain path
set(DYNASM_TOOLCHAIN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../dynasm-toolchain)
set(DYNASM_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(DYNASM_OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dasm)

# dynasm toolchain
file(GLOB dasm_src "dasm/*.c" "dasm/*.h")
add_custom_target(dynasm COMMAND cd ${DYNASM_TOOLCHAIN_PATH} && python dynasm.py --arch X86 --dir ${DYNASM_SOURCE_DIR} --out ${DYNASM_OUT_DIR})
add_subdirectory(${DYNASM_TOOLCHAIN_PATH}/cmake Dynasm EXCLUDE_FROM_ALL)

# JCI
include_directories(src)
add_executable(jci src/jci.c)
target_link_libraries(jci PUBLIC Dynasm)
add_dependencies(jci dynasm)
