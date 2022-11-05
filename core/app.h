#ifndef __APP_H__
#define __APP_H__

#include <stdio.h>
#include <stdlib.h>

#include "oop.h"
#include "eventmanager.h"
#include "gamemanager.h"
#include "windowmanager.h"

class (App, (int argc, char *argv[]),
  GLFWwindow *m_window;
);

#endif  // __APP_H__
