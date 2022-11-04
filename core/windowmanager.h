#ifndef __WINDOWMANAGER_H__
#define __WINDOWMANAGER_H__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

int WindowManager_Init(int argc, char *argv[]);
void WindowManager_SetMinimumWindowSize(int baseWidth);

#endif  // __WINDOWMANAGER_H__