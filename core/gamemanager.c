#include "gamemanager.h"

object (GameManager);

private (GameManager, void, MainLoop(GLFWwindow *window)) {
  context (GameManager);
  
  if (this->m_updateCallback == nullptr) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(this->m_window);
  } else {
    this->m_updateCallback(this->m_window);
  }
}

private (GameManager, void, Prepare()) {
  glClearDepth(1.0);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glEnable(GL_DEPTH_TEST);
}

public (GameManager, int, Init(GLFWwindow *window)) {
  new (GameManager);
  context (GameManager);

  this->m_window = window;
  this->m_updateCallback = nullptr;

  if (gl3wInit()) {
    fprintf(stderr, "Failed to gl3w initialize OpenGL\n");
    return -2;
  }

  if (!gl3wIsSupported(3, 3)) {
    fprintf(stderr, "OpenGL 3.3 not supported\n");
    return -3;
  }

  printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

  invoke(GameManager, Prepare());

  glfwSetWindowRefreshCallback(this->m_window, func (GameManager, MainLoop));

  return 0;
}

public (GameManager, void, Destroy()) {
  destroy (GameManager);
}

public (GameManager, void, SetUpdateCallback(UpdateCallback updateCallback)) {
  context (GameManager);
  this->m_updateCallback = updateCallback;
}
