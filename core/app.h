#ifndef __APP_H__
#define __APP_H__

#include <stdio.h>
#include <stdlib.h>

#include "oop.h"
#include "windowmanager.h"
#include "gamemanager.h"
#include "scenemanager.h"
#include "eventmanager.h"

class (App, (int argc, char *argv[]),
  GLFWwindow *m_window;
  int m_currentScene;
);

#endif  // __APP_H__
