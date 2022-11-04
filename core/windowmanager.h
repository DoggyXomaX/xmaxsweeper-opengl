#ifndef __WINDOWMANAGER_H__
#define __WINDOWMANAGER_H__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h> 

#include "oop.h"

$CALLBACK(ResizeCallbackFunc, void, (GLFWwindow*, int, int));

$CLASS(WindowManager, (GLFWwindow **out_window),
  GLFWwindow *m_window;
  ResizeCallbackFunc m_resizeCallback;
  int m_width;
  int m_height;
  int m_minWidth;
  int m_minHeight;
);

$PUBLIC(void, WindowManager, SetMinimumWindowSize, (int baseWidth));
$PUBLIC(void, WindowManager, SetResizeCallback, (ResizeCallbackFunc resizeCallback));

#endif  // __WINDOWMANAGER_H__