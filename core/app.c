#include "app.h"

object (App);

public (App, int, Init, (int argc, char *argv[])) {
  new (App);

  App->m_window = NULL;

  printf("App executed!\n");

  int result = WindowManager_Init(&(App->m_window));
  if (result != 0 || App->m_window == NULL) {
    fprintf(stderr, "Failed to init WindowManager!\n");
    return result;
  }
  printf("WindowManager initialized successfully!\n");

  result = GameManager_Init(App->m_window);
  if (result != 0) {
    fprintf(stderr, "Failed to init GameManager!\n");
    WindowManager_Destroy();
    return result;
  }
  printf("GameManager initialized successfully!\n");

  result = EventManager_Init(App->m_window);
  if (result != 0) {
    fprintf(stderr, "Failed to init EventManager!\n");
    WindowManager_Destroy();
    GameManager_Destroy();
    return result;
  }
  printf("EventManager initialized successfully!\n");

  while (!glfwWindowShouldClose(App->m_window)) {
    EventManager_OnInput();
    glfwPollEvents();
  }

  WindowManager_Destroy();
  GameManager_Destroy();
  EventManager_Destroy();
  glfwTerminate();

  return 0;
}

public (App, void, Destroy, ()) {
  destroy (App);
}
