#include "eventmanager.h"

EventManager_private *EventManager = NULL;

// public:
int EventManager_Init(GLFWwindow *window) {
  EventManager = (EventManager_private*)malloc(sizeof(EventManager_private));

  EventManager->m_window = window;

  return 0;
}

void EventManager_Destroy() {
  free(EventManager);
}

void EventManager_OnInput() {
  if (glfwGetKey(EventManager->m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(EventManager->m_window, true);
}