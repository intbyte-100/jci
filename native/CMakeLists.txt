cmake_minimum_required(VERSION 3.2)

project(jci_native)


set(SOURCES)

# dynasm toolchain path
set(DYNASM_TOOLCHAIN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../dynasm-toolchain)
set(DYNASM_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dasm)
set(DYNASM_OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)

# dynasm toolchain
file(GLOB dasm_src "src/*.c" "src/*.h")
execute_process(COMMAND cd ${DYNASM_TOOLCHAIN_PATH} && python dynasm.py --arch X64 --dir ${DYNASM_SOURCE_DIR} --out ${DYNASM_OUT_DIR})
add_custom_target(dynasm COMMAND cd ${DYNASM_TOOLCHAIN_PATH} && python dynasm.py --arch X64 --dir ${DYNASM_SOURCE_DIR} --out ${DYNASM_OUT_DIR})
add_subdirectory(${DYNASM_TOOLCHAIN_PATH}/cmake Dynasm EXCLUDE_FROM_ALL)

# JCI
include_directories(src)
add_executable(jci ${dasm_src})
target_link_libraries(jci PUBLIC Dynasm)
add_dependencies(jci dynasm)
