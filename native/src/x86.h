/*
** This file has been pre-processed with DynASM.
** https://luajit.org/dynasm.html
** DynASM version 1.3.0, DynASM x64 version 1.3.0
** DO NOT EDIT! The original file is in "/home/intbyte/CLionProjects/jci/native/dasm/x86.dasm.h".
*/

#line 1 "/home/intbyte/CLionProjects/jci/native/dasm/x86.dasm.h"
#pragma once


#include "dasm_proto.h"
#include "dasm_x86.h"
#include "jci.h"

//| .arch x64
#if DASM_VERSION != 10300
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 9 "/home/intbyte/CLionProjects/jci/native/dasm/x86.dasm.h"


dasm_State* compile_func(jci_func_descriptor* descriptor){
    dasm_State* state;
    //|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 14 "/home/intbyte/CLionProjects/jci/native/dasm/x86.dasm.h"
    dasm_init(&state, DASM_MAXSECTION);

    //|.globals lbl_
enum {
  lbl__MAX
};
#line 17 "/home/intbyte/CLionProjects/jci/native/dasm/x86.dasm.h"
    void* labels[lbl__MAX];
    dasm_setupglobal(&state, labels, lbl__MAX);
    //|.actionlist actions
static const unsigned char actions[1] = {
  255
};

#line 20 "/home/intbyte/CLionProjects/jci/native/dasm/x86.dasm.h"
    dasm_setup(&state, actions);

    dasm_State** Dst = &state;

    return state;
}
