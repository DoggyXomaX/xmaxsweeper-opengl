#ifndef __KEYEVENTS_H__
#define __KEYEVENTS_H__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#include "oop.h"

callback (KeyDownEvent, void, (GLFWwindow *window, int scancode));
callback (KeyUpEvent, void, (GLFWwindow *window, int scancode));
callback (KeyEvent, void, (GLFWwindow *window, int key, int scancode, int action, int mods));

#endif // __KEYEVENTS_H__