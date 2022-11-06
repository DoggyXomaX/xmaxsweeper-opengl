#include "test.scene.h"

init_scene(TestScene, "test");

public (TestScene, int, Init(GLFWwindow* window)) {
  new_scene (TestScene);

  return 0;
}

public (TestScene, void, Destroy(void)) {
  destroy (TestScene);
}

public (TestScene, void, Start(GLFWwindow* window)) {
  glClearColor(1.0f, 0.5f, 0.0f, 1.0f);
  puts("Test scene start");
}

public (TestScene, void, Update(GLFWwindow* window)) {
  first_update (TestScene);

  puts("Test scene update");

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glfwSwapBuffers(window);
}
