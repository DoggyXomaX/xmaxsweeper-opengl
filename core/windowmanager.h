#ifndef __WINDOWMANAGER_H__
#define __WINDOWMANAGER_H__

#include <stdio.h>
#include <stdlib.h>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

int WindowManager_Init(int argc, char *argv[]);
void WindowManager_SetMinimumWindowSize(int baseWidth);

#endif // __WINDOWMANAGER_H__