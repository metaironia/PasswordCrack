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

    CrackButtonDraw (CRACK_WINDOW_SIZE_X * 2 / 3, CRACK_WINDOW_SIZE_Y * 1 / 3);
    CrackButtonDraw (CRACK_WINDOW_SIZE_X * 2 / 3, CRACK_WINDOW_SIZE_Y * 2 / 3);

    txDeleteDC (background_image);

    return GRAPHICS_FUNC_STATUS_OK;
}

GraphicsFuncStatus CrackButtonDraw (const double x_topleft, const double y_topleft) {

    if (!txSetColor (TX_white, BUTTON_BORDER_THICKNESS))
        return GRAPHICS_FUNC_STATUS_FAIL;

    if (!txSetFillColor (TX_ORANGE))
        return GRAPHICS_FUNC_STATUS_FAIL;

    if (!txRectangle (x_topleft, y_topleft, x_topleft + BUTTON_SIZE_X, y_topleft - BUTTON_SIZE_Y))
        return GRAPHICS_FUNC_STATUS_FAIL;

    return GRAPHICS_FUNC_STATUS_OK;
}
