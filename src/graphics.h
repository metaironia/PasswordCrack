#ifndef GRAPHICS_H
#define GRAPHICS_H

const int CRACK_WINDOW_SIZE_X = 600;
const int CRACK_WINDOW_SIZE_Y = 400;

enum GraphicsFuncStatus {

    GRAPHICS_FUNC_STATUS_OK,
    GRAPHICS_FUNC_STATUS_FAIL
};

GraphicsFuncStatus CrackProgramRun (void);


#endif
