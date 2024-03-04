#ifndef CRACK_H
#define CRACK_H


enum CrackFuncStatus {

    CRACK_FUNC_STATUS_OK,
    CRACK_FUNC_STATUS_FAIL
};

const char NOP_OPCODE = (char) 0x90;

CrackFuncStatus CrackReplaceBytes (void);

#endif
