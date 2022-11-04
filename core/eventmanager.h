#ifndef __EVENTMANAGER_H__
#define __EVENTMANAGER_H__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  GLFWwindow *m_window;
} EventManager_private;

int EventManager_Init(GLFWwindow *window);
void EventManager_Destroy(void);
void EventManager_OnInput(void);

#endif  // __EVENTMANAGER_H__