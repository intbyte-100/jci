/*
** This file has been pre-processed with DynASM.
** https://luajit.org/dynasm.html
** DynASM version 1.3.0, DynASM x64 version 1.3.0
** DO NOT EDIT! The original file is in "/home/intbyte/CLionProjects/jci/native/dasm/jci.dasm.c".
*/

#line 1 "/home/intbyte/CLionProjects/jci/native/dasm/jci.dasm.c"
#include "jci.h"

#include "dasm_proto.h"

//|.arch x64
#if DASM_VERSION != 10300
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 6 "/home/intbyte/CLionProjects/jci/native/dasm/jci.dasm.c"

int main(){
    jci_func_descriptor* descriptor = jci_new_func_descriptor(2);
    descriptor->returnType = jci_int;
    descriptor->argument_type[0] = jci_int;
    descriptor->argument_type[1] = jci_int;

    jci_jni_func sum = jci_compile_func(descriptor, &main);
}
