#include <stdio.h>

#include "crack.h"

CrackFuncStatus CrackReplaceBytes (void) {

    FILE *file_to_crack = fopen ("password.com", "r+b");

    if (!file_to_crack)
        return CRACK_FUNC_STATUS_FAIL;

    fseek (file_to_crack, 0x7D, SEEK_SET);

    fputc (NOP_OPCODE, file_to_crack);
    fputc (NOP_OPCODE, file_to_crack);

    if (ferror (file_to_crack)) {

        fclose (file_to_crack);
        return CRACK_FUNC_STATUS_FAIL;
    }

    fclose (file_to_crack);
    file_to_crack = NULL;

    return CRACK_FUNC_STATUS_OK;
}
