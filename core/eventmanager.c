#include "eventmanager.h"

object (EventManager);

private (EventManager, void, OnInput(GLFWwindow *window, int key, int scancode, int action, int mods)) {
  context (EventManager);

  if (this->m_appKeyEvent != nullptr)
    this->m_appKeyEvent(window, key, scancode, action, mods);

  if (this->m_keyEvent != nullptr)
    this->m_keyEvent(window, key, scancode, action, mods);

  switch (action) {
    case GLFW_PRESS: {
      if (this->m_keyDownEvent != nullptr)
        this->m_keyDownEvent(window, scancode);
      break;
    }
      
    case GLFW_RELEASE: {
      if (this->m_keyUpEvent != nullptr)
        this->m_keyUpEvent(window, scancode);
      break;
    }
  }
}

public (EventManager, int, Init(GLFWwindow *window, KeyEvent appKeyEvent)) {
  new (EventManager);
  context (EventManager);

  this->m_window = window;
  this->m_keyDownEvent = nullptr;
  this->m_keyUpEvent = nullptr;
  this->m_keyEvent = nullptr;
  this->m_appKeyEvent = appKeyEvent;

  glfwSetKeyCallback(this->m_window, func(EventManager, OnInput));

  return 0;
}

public (EventManager, void, Destroy()) {
  destroy (EventManager);
}

public (EventManager, void, SetKeyDownEvent(KeyDownEvent e)) {
  context (EventManager);
  this->m_keyDownEvent = e;
}

public (EventManager, void, SetKeyUpEvent(KeyUpEvent e)) {
  context (EventManager);
  this->m_keyUpEvent = e;
}

public (EventManager, void, SetKeyEvent(KeyEvent e)) {
  context (EventManager);
  this->m_keyEvent = e;
}
