#include "menu.scene.h"

init_scene (MenuScene, "menu");

public (MenuScene, int, Init(GLFWwindow *window)) {
  new_scene (MenuScene);
  return 0;
}

public (MenuScene, void, Destroy()) {
  destroy (MenuScene);
}

public (MenuScene, void, Start(GLFWwindow *window)) {
  context (MenuScene);
  puts("Menu scene start");
  glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
}

public (MenuScene, void, Update(GLFWwindow *window)) {
  context (MenuScene);
  first_update (MenuScene);

  puts("Menu scene update");

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glfwSwapBuffers(window);
}
