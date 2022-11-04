#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

typedef void (*UpdateCallbackFunc)(GLFWwindow *);

typedef struct {
  GLFWwindow *m_window;
  UpdateCallbackFunc m_updateCallback;
} GameManager_private;

int GameManager_Init(GLFWwindow *window);
void GameManager_Destroy(void);
void GameManager_SetUpdateCallback(UpdateCallbackFunc updateCallback);

#endif  // __GAMEMANAGER_H__