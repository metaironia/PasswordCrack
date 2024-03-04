#ifndef GRAPHICS_H
#define GRAPHICS_H

enum GraphicsFuncStatus {

    GRAPHICS_FUNC_STATUS_OK,
    GRAPHICS_FUNC_STATUS_FAIL
};

const int LEFT_BUTTON = 1;

const int PATH_TO_IMAGE_LENGTH     = 32;
const int BACKGROUND_IMAGES_NUMBER = 3;

const int CRACK_WINDOW_SIZE_X = 600;
const int CRACK_WINDOW_SIZE_Y = 400;

const double BUTTON_BORDER_THICKNESS = 3;
const double BUTTON_SIZE_X           = 150;
const double BUTTON_SIZE_Y           = 60;

GraphicsFuncStatus CrackProgramRun (void);

const char *BackgroundImagePathGen (void);

GraphicsFuncStatus CrackButtonDraw (const double x_topleft, const double y_topleft, const char *button_text);

bool PressedButtonCheck (const double x_topleft, const double y_topleft);

bool MouseInsideButtonCheck (const double x_topleft, const double y_topleft);

HDC BackgroundImageSet (const char *image_path);

GraphicsFuncStatus BackgroundMusicSet (const char *music_path);

GraphicsFuncStatus CrackTry (void);

#endif
