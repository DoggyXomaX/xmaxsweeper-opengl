#include "app.h"

object (App);

int QKey = 0;

private (App, void, OnInput()) {
  context (App);

  if (glfwGetKey(this->m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    puts("[ESC]");
    glfwSetWindowShouldClose(this->m_window, true);
    return;
  }

  int qKey = glfwGetKey(this->m_window, GLFW_KEY_Q);
  if (QKey != qKey) {
    QKey = qKey;
    if (QKey == GLFW_PRESS) {
      puts("[Q]");
      this->m_currentScene++;
      if (this->m_currentScene >= invoke (SceneManager, GetSceneCount()))
        this->m_currentScene = 0;
      invoke (SceneManager, ChangeScene(this->m_currentScene));
    }
  }
}

public (App, int, Init(int argc, char *argv[])) {
  new (App);
  context (App);

  this->m_window = nullptr;
  this->m_currentScene = 0;

  printf("App executed!\n");

  int result = invoke (WindowManager, Init(&(this->m_window)));
  if (result != 0 || this->m_window == nullptr) {
    fprintf(stderr, "Failed to init WindowManager!\n");
    return result;
  }
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

  printf("Scene count: %d\n", invoke (SceneManager, GetSceneCount()));
  invoke (SceneManager, ChangeScene(0));

  while (!glfwWindowShouldClose(this->m_window)) {
    invoke (App, OnInput());
    invoke (GameManager, MainLoop(this->m_window));
    glfwPollEvents();
  }
  
  return result;
}

public (App, void, Destroy()) {
  invoke (WindowManager, Destroy());
  invoke (GameManager, Destroy());
  invoke (SceneManager, Destroy());

  destroy (App);
}
