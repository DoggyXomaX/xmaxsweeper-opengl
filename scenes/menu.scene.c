#include "menu.scene.h"

const float TRIANGLE[9] = {
  -0.5f, -0.5f, 0.0f,
   0.5f, -0.5f, 0.0f,
   0.0f,  0.5f, 0.0f,
};

init_scene (MenuScene, "menu");

public (MenuScene, int, Init(GLFWwindow *window)) {
  new_scene (MenuScene);
  context (MenuScene);

  this->m_time = 0;
  this->m_vertexInput = TRIANGLE;

  return 0;
}

public (MenuScene, void, Destroy()) {
  destroy (MenuScene);
}

public (MenuScene, void, Start(GLFWwindow *window)) {
  context (MenuScene);
  puts("Menu scene start");
  glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
  glGenBuffers(1, &this->m_vbo);
}

public (MenuScene, void, Update(GLFWwindow *window)) {
  context (MenuScene);
  first_update (MenuScene);

  this->m_time++;
  if (this->m_time >= 60) {
    this->m_time = 0;
    printf("Tick count: %u\n", 60);
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glfwSwapBuffers(window);
}
