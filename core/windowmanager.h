#ifndef __WINDOWMANAGER_H__
#define __WINDOWMANAGER_H__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "oop.h"

typedef void(*ResizeCallbackFunc)(GLFWwindow *, int, int);

$CLASS(WindowManager, (GLFWwindow **out_window),
  const char *m_startTitle;
  const int *m_startWidth;
  const int *m_startHeight;

  GLFWwindow *m_window;
  int m_width;
  int m_height;
  int m_minWidth;
  int m_minHeight;
  ResizeCallbackFunc m_resizeCallback;
);

$METHOD(void, WindowManager, SetMinimumWindowSize, (int baseWidth));
$METHOD(void, WindowManager, SetResizeCallback, (ResizeCallbackFunc resizeCallback));

#endif  // __WINDOWMANAGER_H__