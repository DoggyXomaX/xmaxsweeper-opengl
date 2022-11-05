#ifndef __EVENTMANAGER_H__
#define __EVENTMANAGER_H__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "oop.h"

class (EventManager, (GLFWwindow *window), 
  GLFWwindow *m_window;
); 

public (EventManager, void, OnInput, (void));

#endif  // __EVENTMANAGER_H__