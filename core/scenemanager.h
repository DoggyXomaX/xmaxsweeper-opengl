#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "oop.h"
#include "scenetemplate.h"
#include "../scenes/scenelist.h"
#include "gamemanager.h"
#include "eventmanager.h"

callback (DestructorCallback, void, (void));

class (SceneManager, (GLFWwindow *window),
  GLFWwindow *m_window;
  SceneTemplate *m_currentScene;
  SceneList_object *m_sceneList;
);

public (SceneManager, void, ChangeScene(int index));
public (SceneManager, SceneTemplate*, GetSceneByIndex(int index));
public (SceneManager, SceneTemplate*, GetSceneByName(const char *name));
public (SceneManager, int, GetSceneCount(void));

#endif // __SCENEMANAGER_H__