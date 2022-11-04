#ifndef __WINDOWMANAGER_H__
#define __WINDOWMANAGER_H__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

typedef void(*ResizeCallbackFunc)(GLFWwindow *, int, int);

typedef struct {
  const char *m_startTitle;
  const int *m_startWidth;
  const int *m_startHeight;

  GLFWwindow *m_window;
  int m_width;
  int m_height;
  int m_minWidth;
  int m_minHeight;
  ResizeCallbackFunc m_resizeCallback;
} WindowManager_private;

int WindowManager_Init(GLFWwindow **out_window);
void WindowManager_Destroy(void);
void WindowManager_SetMinimumWindowSize(int baseWidth);
void WindowManager_SetResizeCallback(ResizeCallbackFunc resizeCallback);

#endif  // __WINDOWMANAGER_H__