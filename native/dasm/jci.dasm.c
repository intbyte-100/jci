#include "jci.h"

#include "dasm_proto.h"

|.arch x64

int main(){
    jci_func_descriptor* descriptor = jci_new_func_descriptor(2);
    descriptor->returnType = jci_int;
    descriptor->argument_type[0] = jci_int;
    descriptor->argument_type[1] = jci_int;

    jci_jni_func sum = jci_compile_func(descriptor, &main);
}