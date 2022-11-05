#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "oop.h"

callback (UpdateCallbackFunc, void, (GLFWwindow*)); 

class (GameManager, (GLFWwindow *window),
  GLFWwindow *m_window;
  UpdateCallbackFunc m_updateCallback;
);

public (GameManager, void, SetUpdateCallback, (UpdateCallbackFunc updateCallback));

#endif  // __GAMEMANAGER_H__