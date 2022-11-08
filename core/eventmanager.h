#ifndef __EVENTMANAGER_H__
#define __EVENTMANAGER_H__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "oop.h"
#include "keyevents.h"

class (EventManager, (GLFWwindow *window, KeyEvent appKeyEvent),
  GLFWwindow *m_window;
  KeyDownEvent m_keyDownEvent;
  KeyUpEvent m_keyUpEvent;
  KeyEvent m_keyEvent;
  KeyEvent m_appKeyEvent;
);

public (EventManager, void, SetKeyDownEvent(KeyDownEvent e));
public (EventManager, void, SetKeyUpEvent(KeyUpEvent e));
public (EventManager, void, SetKeyEvent(KeyEvent e));

#endif // __EVENTMANAGER_H__