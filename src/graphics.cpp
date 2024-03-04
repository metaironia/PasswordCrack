#include "../lib/TXLib.h"

#include "graphics.h"

GraphicsFuncStatus CrackProgramRun (void) {

    txCreateWindow (CRACK_WINDOW_SIZE_X, CRACK_WINDOW_SIZE_Y);

    txTextCursor (false);

    HDC background_image = txLoadImage (BackgroundImagePathGen());

    if (!background_image) {

        txMessageBox ("Верните картинки по-хорошему");
        return GRAPHICS_FUNC_STATUS_FAIL;
    }

    Win32::TransparentBlt (txDC(),           0, 0, CRACK_WINDOW_SIZE_X,             CRACK_WINDOW_SIZE_Y,
                           background_image, 0, 0, txGetExtentX (background_image), txGetExtentY (background_image),
                           TX_NULL);

    CrackButtonDraw (CRACK_WINDOW_SIZE_X * 2 / 3, CRACK_WINDOW_SIZE_Y * 1 / 3, "ПОЗВОНИТЬ В МВД");
    CrackButtonDraw (CRACK_WINDOW_SIZE_X * 2 / 3, CRACK_WINDOW_SIZE_Y * 2 / 3, "CRACK");

    txDeleteDC (background_image);

    return GRAPHICS_FUNC_STATUS_OK;
}

const char *BackgroundImagePathGen (void) {

    static char background_image_path[PATH_TO_IMAGE_LENGTH] = {};

    const int background_image_number = rand() % BACKGROUND_IMAGES_NUMBER + 1;

    snprintf (background_image_path, PATH_TO_IMAGE_LENGTH, "CrackImages\\anonymous%d.bmp", background_image_number);

    return background_image_path;
}

GraphicsFuncStatus CrackButtonDraw (const double x_topleft, const double y_topleft, const char *button_text) {

    if (!txSetColor (TX_white, BUTTON_BORDER_THICKNESS))
        return GRAPHICS_FUNC_STATUS_FAIL;

    if (!txSetFillColor (TX_ORANGE))
        return GRAPHICS_FUNC_STATUS_FAIL;

    if (!txRectangle (x_topleft, y_topleft - BUTTON_SIZE_Y, x_topleft + BUTTON_SIZE_X, y_topleft))
        return GRAPHICS_FUNC_STATUS_FAIL;

    if (!txSetColor (TX_BLM, BUTTON_BORDER_THICKNESS))
        return GRAPHICS_FUNC_STATUS_FAIL;

    txSelectFont ("Times New Roman", 30, 6, FW_BOLD);

    if (!txDrawText (x_topleft, y_topleft - BUTTON_SIZE_Y, x_topleft + BUTTON_SIZE_X, y_topleft, button_text))
        return GRAPHICS_FUNC_STATUS_FAIL;

    return GRAPHICS_FUNC_STATUS_OK;
}
