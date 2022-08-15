#pragma once

#include <stdint.h>


enum jci_types {
    jci_long,
    jci_double,
    jci_float,
    jci_int,
    jci_short,
    jci_byte
};

typedef void* jci_jni_func;
typedef void* jci_c_func;

typedef struct {
    uint8_t returnType;
    uint8_t args_count;
    uint8_t argument_type[];
} jci_func_descriptor;



jci_func_descriptor *jci_new_func_descriptor(uint8_t argument_count);
jci_c_func jci_compile_func(jci_func_descriptor* descriptor, jci_c_func func);