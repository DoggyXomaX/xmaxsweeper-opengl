#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "oop.h"

callback (UpdateCallback, void, (GLFWwindow*)); 

class (GameManager, (GLFWwindow *window),
  GLFWwindow *m_window;
  UpdateCallback m_updateCallback;
);

public (GameManager, void, MainLoop(GLFWwindow *window));
public (GameManager, void, SetUpdateCallback(UpdateCallback updateCallback));

#endif  // __GAMEMANAGER_H__