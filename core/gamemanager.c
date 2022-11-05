#include "gamemanager.h"

object (GameManager);

private (GameManager, void, Update, (GLFWwindow *window)) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glfwSwapBuffers(GameManager->m_window);
  if (GameManager->m_updateCallback != NULL)
    GameManager->m_updateCallback(GameManager->m_window);
}

private (GameManager, void, Prepare, ()) {
  glClearDepth(1.0);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glEnable(GL_DEPTH_TEST);
}

public (GameManager, int, Init, (GLFWwindow *window)) {
  new (GameManager);

  GameManager->m_window = window;
  GameManager->m_updateCallback = NULL;

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

  GameManager_Prepare();

  glfwSetWindowRefreshCallback(GameManager->m_window, &GameManager_Update);

  return 0;
}

public (GameManager, void, Destroy, ()) {
  destroy (GameManager);
}

public (GameManager, void, SetUpdateCallback, (UpdateCallbackFunc updateCallback)) {
  GameManager->m_updateCallback = updateCallback;
}
