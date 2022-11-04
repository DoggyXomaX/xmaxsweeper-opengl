#include "gamemanager.h"

// private:
GameManager_private *GameManager = NULL;

void GameManager_Update() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glfwSwapBuffers(GameManager->m_window);
  if (GameManager->m_updateCallback != NULL)
    GameManager->m_updateCallback(GameManager->m_window);
}

void GameManager_Prepare() {
  glClearDepth(1.0);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glEnable(GL_DEPTH_TEST);
}

// public:
int GameManager_Init(GLFWwindow *window) {
  GameManager = (GameManager_private*)malloc(sizeof(GameManager_private));

  GameManager->m_window = window;

  if (gl3wInit()) {
    fprintf(stderr, "Failed to gl3w initialize OpenGL\n");
    GameManager_Destroy();
    return -2;
  }

  if (!gl3wIsSupported(3, 3)) {
    fprintf(stderr, "OpenGL 3.3 not supported\n");
    GameManager_Destroy();
    return -3;
  }

  printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

  glfwSetWindowRefreshCallback(GameManager->m_window, &GameManager_Update);
  GameManager_Prepare();

  return 0;
}

void GameManager_Destroy() {
  free(GameManager);
}

void GameManager_SetUpdateCallback(UpdateCallbackFunc updateCallback) {
  GameManager->m_updateCallback = updateCallback;
}
