#include "app.h"

object (App);

private (App, void, OnResize(GLFWwindow *window, int width, int height)) {
  glViewport(0, 0, width, height);
}

private (App, void, OnInput(GLFWwindow *window, int key, int scancode, int action, int mods)) {
  context (App);

  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    puts("[ESC]");
    glfwSetWindowShouldClose(this->m_window, GL_TRUE);
    return;
  }

  if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
    puts("[Q]");
    this->m_currentScene++;
    if (this->m_currentScene >= invoke (SceneManager, GetSceneCount()))
      this->m_currentScene = 0;
    invoke (SceneManager, ChangeScene(this->m_currentScene));
    return;
  }

  if (key == GLFW_KEY_W && action == GLFW_PRESS) {
    puts("[W]");
    this->m_debugWireframe ^= true;
    glPolygonMode(GL_FRONT_AND_BACK, this->m_debugWireframe ? GL_LINE : GL_FILL);
    return;
  }
}

public (App, int, Init(int argc, char *argv[])) {
  new (App);
  context (App);

  this->m_window = nullptr;
  this->m_currentScene = 0;
  this->m_debugWireframe = false;

  printf("App executed!\n");
  fflush(stdout);

  int result = invoke (WindowManager, Init(&(this->m_window)));
  if (result != 0 || this->m_window == nullptr) {
    fprintf(stderr, "Failed to init WindowManager!\n");
    return result;
  }
  invoke (WindowManager, SetResizeCallback(func (App, OnResize)));
  printf("WindowManager initialized successfully!\n");
  
  result = invoke (GameManager, Init(this->m_window));
  if (result != 0) {
    fprintf(stderr, "Failed to init GameManager!\n");
    return result;
  }
  printf("GameManager initialized successfully!\n");

  result = invoke (SceneManager, Init(this->m_window));
  if (result != 0) {
    fprintf(stderr, "Failed to init SceneManager!\n");
    return result;
  }
  printf("SceneManager initialized successfully!\n");

  result = invoke (EventManager, Init(this->m_window, func (App, OnInput)));
  if (result != 0) {
    fprintf(stderr, "Failed to init EventManager\n");
    return result;
  }
  printf("EventManager initialized successfully!\n");

  printf("Scene count: %d\n", invoke (SceneManager, GetSceneCount()));
  invoke (SceneManager, ChangeScene(0));
  fflush(stdout);

  while (!glfwWindowShouldClose(this->m_window)) {
    glfwPollEvents();

    invoke (GameManager, MainLoop(this->m_window));
  }
  
  return result;
}

public (App, void, Destroy()) {
  invoke (WindowManager, Destroy());
  invoke (GameManager, Destroy());
  invoke (SceneManager, Destroy());

  destroy (App);
}
