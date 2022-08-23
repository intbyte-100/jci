#pragma once


#include "dasm_proto.h"
#include "dasm_x86.h"
#include "jci.h"

| .arch x64


dasm_State* compile_func(jci_func_descriptor* descriptor){
    dasm_State* state;
    |.section code
    dasm_init(&state, DASM_MAXSECTION);

    |.globals lbl_
    void* labels[lbl__MAX];
    dasm_setupglobal(&state, labels, lbl__MAX);
    |.actionlist actions
    dasm_setup(&state, actions);

    dasm_State** Dst = &state;

    return state;
}