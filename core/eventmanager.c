#include "eventmanager.h"

object (EventManager);

public (EventManager, int, Init, (GLFWwindow *window)) {
  new (EventManager);

  EventManager->m_window = window;

  return 0;
}

public (EventManager, void, Destroy, ()) {
  destroy (EventManager);
}

public (EventManager, void, OnInput, ()) {
  if (glfwGetKey(EventManager->m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    puts("[ESC]");
    glfwSetWindowShouldClose(EventManager->m_window, true);
  }
}