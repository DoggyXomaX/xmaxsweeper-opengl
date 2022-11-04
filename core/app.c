#include "app.h"

// private:
App_private *App = NULL;

// public:
int App_Init(int argc, char *argv[]) {
  App = (App_private*)malloc(sizeof(App_private));

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

void App_Destroy() {
  free(App);
}
