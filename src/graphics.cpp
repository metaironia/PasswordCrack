#include "../lib/TXLib.h"

#include "graphics.h"
#include "crack.h"

GraphicsFuncStatus CrackProgramRun (void) {

    txCreateWindow (CRACK_WINDOW_SIZE_X, CRACK_WINDOW_SIZE_Y);

    txTextCursor (false);

    if (BackgroundMusicSet ("CrackSounds\\main_menu") == GRAPHICS_FUNC_STATUS_FAIL)
        return GRAPHICS_FUNC_STATUS_FAIL;

    HDC background_image = BackgroundImageSet (BackgroundImagePathGen());

    if (!background_image)
        return GRAPHICS_FUNC_STATUS_FAIL;

    Win32::TransparentBlt (txDC(),           0, 0, CRACK_WINDOW_SIZE_X,             CRACK_WINDOW_SIZE_Y,
                           background_image, 0, 0, txGetExtentX (background_image), txGetExtentY (background_image),
                           TX_NULL);

    CrackButtonDraw (CRACK_WINDOW_SIZE_X * 2 / 3, CRACK_WINDOW_SIZE_Y * 1 / 3, "ЗВЯКНУТЬ ДЕДУ");
    CrackButtonDraw (CRACK_WINDOW_SIZE_X * 2 / 3, CRACK_WINDOW_SIZE_Y * 2 / 3, "CRACK");

    while (1) {

        if (MouseInsideButtonCheck (CRACK_WINDOW_SIZE_X * 2 / 3, CRACK_WINDOW_SIZE_Y * 1 / 3))
            txMessageBox ("Дед умер, звякайте менторам");

        if (PressedButtonCheck (CRACK_WINDOW_SIZE_X * 2 / 3, CRACK_WINDOW_SIZE_Y * 2 / 3)) {

            txDeleteDC (background_image);

            CrackTry();

            break;
        }
    }

    return GRAPHICS_FUNC_STATUS_OK;
}

bool PressedButtonCheck (const double x_topleft, const double y_topleft) {

    if (MouseInsideButtonCheck (x_topleft, y_topleft) && txMouseButtons() == LEFT_BUTTON)
        return true;

    return false;
}

bool MouseInsideButtonCheck (const double x_topleft, const double y_topleft) {

    const double mouse_pos_x = txMouseX();
    const double mouse_pos_y = txMouseY();

    if (x_topleft <= mouse_pos_x && mouse_pos_x <= x_topleft + BUTTON_SIZE_X &&
        y_topleft <= mouse_pos_y && mouse_pos_y <= y_topleft + BUTTON_SIZE_Y)

        return true;

    return false;
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

    if (!txRectangle (x_topleft, y_topleft, x_topleft + BUTTON_SIZE_X, y_topleft + BUTTON_SIZE_Y))
        return GRAPHICS_FUNC_STATUS_FAIL;

    if (!txSetColor (TX_BLM, BUTTON_BORDER_THICKNESS))
        return GRAPHICS_FUNC_STATUS_FAIL;

    txSelectFont ("Times New Roman", 30, 6, FW_BOLD);

    if (!txDrawText (x_topleft, y_topleft, x_topleft + BUTTON_SIZE_X, y_topleft + BUTTON_SIZE_Y, button_text))
        return GRAPHICS_FUNC_STATUS_FAIL;

    return GRAPHICS_FUNC_STATUS_OK;
}

HDC BackgroundImageSet (const char *image_path) {

    assert (image_path);

    HDC background_image = txLoadImage (image_path);

    if (!background_image) {

        txMessageBox ("Верните картинки по-хорошему");
        return NULL;
    }

    return background_image;
}

GraphicsFuncStatus BackgroundMusicSet (const char *music_path) {

    assert (music_path);

    if (!txPlaySound (music_path, SND_LOOP)) {

        txMessageBox ("Срочно верните звуки или вам станет плохо");
        return GRAPHICS_FUNC_STATUS_FAIL;
    }

    return GRAPHICS_FUNC_STATUS_OK;
}

GraphicsFuncStatus CrackTry (void) {

    bool is_crack_success = (bool) (rand() % 2);

    const char *image_path = NULL;
    const char *music_path = NULL;

    if (is_crack_success)
        if (CrackReplaceBytes() == CRACK_FUNC_STATUS_FAIL)
            is_crack_success = false;

    if (is_crack_success) {

        image_path = "CrackImages\\hack_success.bmp";
        music_path = "CrackSounds\\hack_success.wav";
    }

    else {

        image_path = "CrackImages\\hack_fail.bmp";
        music_path = "CrackSounds\\hack_fail.wav";
    }

    if (BackgroundMusicSet (music_path) == GRAPHICS_FUNC_STATUS_FAIL)
        return GRAPHICS_FUNC_STATUS_FAIL;

    HDC background_image = BackgroundImageSet (image_path);

    if (!background_image)
        return GRAPHICS_FUNC_STATUS_FAIL;

    Win32::StretchBlt (txDC(),           0, 0, CRACK_WINDOW_SIZE_X,             CRACK_WINDOW_SIZE_Y,
                       background_image, 0, 0, txGetExtentX (background_image), txGetExtentY (background_image),
                       SRCCOPY);

    txDeleteDC (background_image);

    return GRAPHICS_FUNC_STATUS_OK;
}
