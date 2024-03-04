#include "../lib/TXLib.h"

#include "graphics.h"

GraphicsFuncStatus CrackProgramRun (void) {

    txCreateWindow (CRACK_WINDOW_SIZE_X, CRACK_WINDOW_SIZE_Y);

    txTextCursor (false);

    HDC background_image = txLoadImage ("CrackImages\\anonymous1.bmp");

    if (!background_image) {

        txMessageBox ("Верните картинки по-хорошему");
        return GRAPHICS_FUNC_STATUS_FAIL;
    }

    Win32::TransparentBlt (txDC(),           0, 0, CRACK_WINDOW_SIZE_X,             CRACK_WINDOW_SIZE_Y,
                           background_image, 0, 0, txGetExtentX (background_image), txGetExtentY (background_image),
                           TX_NULL);


    txDeleteDC (background_image);

    return GRAPHICS_FUNC_STATUS_OK;
}


