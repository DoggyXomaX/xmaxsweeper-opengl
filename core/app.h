#ifndef __APP_H__
#define __APP_H__

#include <stdio.h>
#include <stdlib.h>

#include "eventmanager.h"
#include "gamemanager.h"
#include "windowmanager.h"

typedef struct {
  GLFWwindow *m_window;
} App_private;

int App_Init(int argc, char *argv[]);
void App_Destroy(void);

#endif  // __APP_H__
