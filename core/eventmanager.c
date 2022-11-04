#include "eventmanager.h"

$OBJECT(EventManager);

// public:
$PUBLIC(int, EventManager, Init, (GLFWwindow *window)) {
  $NEW(EventManager);

  EventManager->m_window = window;

  return 0;
}

$PUBLIC(void, EventManager, Destroy, ()) {
  $DESTROY(EventManager);
}

$PUBLIC(void, EventManager, OnInput, ()) {
  if (glfwGetKey(EventManager->m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    puts("[ESC]");
    glfwSetWindowShouldClose(EventManager->m_window, true);
  }
}