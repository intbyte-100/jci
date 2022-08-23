#include "jci.h"
#include "x86.h"

#if _WIN32
#include <Windows.h>
#else

#include <sys/mman.h>

#if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#define MAP_ANONYMOUS MAP_ANON
#endif
#endif

int main() {
    jci_func_descriptor *descriptor = jci_new_func_descriptor(2);
    descriptor->returnType = jci_int;
    descriptor->argument_type[0] = jci_int;
    descriptor->argument_type[1] = jci_int;

    jci_jni_func sum = jci_compile_func(descriptor, &main);
}

jci_func_descriptor *jci_new_func_descriptor(uint8_t argument_count) {
    return malloc(sizeof(jci_func_descriptor) + argument_count);
}

jci_c_func jci_compile_func(jci_func_descriptor *descriptor, jci_c_func func) {
    for (int i = 0; i < descriptor->args_count; ++i)
        if (descriptor->argument_type[i] > jci_long)
            return NULL;

    void *function;
    size_t size;
    dasm_State *state = compile_func(descriptor);
    dasm_link(&state, &size);

#ifdef _WIN32
    buf = VirtualAlloc(0, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
#else
    function = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
#endif
    dasm_encode(&state, function);
#ifdef _WIN32
    DWORD dwOld; VirtualProtect(buf, sz, PAGE_EXECUTE_READ, &dwOld);
#else
    mprotect(function, size, PROT_READ | PROT_EXEC);
#endif
}
