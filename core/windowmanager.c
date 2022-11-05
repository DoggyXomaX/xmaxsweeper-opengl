#include "windowmanager.h"

const char DEFAULT_TITLE[] = "XmaxSweeper OpenGL";
const int DEFAULT_WIDTH = 640;
const int DEFAULT_HEIGHT = 360;
const int DEFAULT_MIN_WIDTH = 320;
const int DEFAULT_MIN_HEIGHT = 180;

object (WindowManager);

private (WindowManager, void, OnResize, (GLFWwindow *window, int w, int h)) {
  WindowManager->m_width = w > WindowManager->m_minWidth ? w : WindowManager->m_minWidth;
  WindowManager->m_height = h > WindowManager->m_minHeight ? h : WindowManager->m_minHeight;
  if (WindowManager->m_resizeCallback != NULL)
    WindowManager->m_resizeCallback(window, w, h);
}

public (WindowManager, int, Init, (GLFWwindow **out_window)) {
  new (WindowManager);

  WindowManager->m_window = NULL;
  WindowManager->m_resizeCallback = NULL;
  WindowManager->m_width = DEFAULT_WIDTH;
  WindowManager->m_height = DEFAULT_HEIGHT;
  WindowManager->m_minWidth = DEFAULT_MIN_WIDTH;
  WindowManager->m_minHeight = DEFAULT_MIN_HEIGHT;

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  WindowManager->m_window = glfwCreateWindow(WindowManager->m_width, WindowManager->m_height, DEFAULT_TITLE, NULL, NULL);
  if (WindowManager->m_window == NULL) {
    fprintf(stderr, "Failed to create GLFW window\n");
    glfwTerminate();
    WindowManager_Destroy();
    return -1;
  }

  glfwMakeContextCurrent(WindowManager->m_window);

  glfwSetWindowSizeLimits(WindowManager->m_window, WindowManager->m_minWidth, WindowManager->m_minHeight, GLFW_DONT_CARE, GLFW_DONT_CARE);
  glfwSetWindowAspectRatio(WindowManager->m_window, 16, 9);
  glfwSetFramebufferSizeCallback(WindowManager->m_window, &WindowManager_OnResize);

  *out_window = WindowManager->m_window;

  return 0;
}

public (WindowManager, void, Destroy, ()) {
  destroy (WindowManager);
}

public (WindowManager, void, SetMinimumWindowSize, (int baseWidth)) {
  WindowManager->m_minWidth = baseWidth < 16 ? 16 : baseWidth;
  WindowManager->m_minHeight = WindowManager->m_minWidth / 16 * 9;
  glfwSetWindowSizeLimits(WindowManager->m_window, WindowManager->m_minWidth, WindowManager->m_minHeight, GLFW_DONT_CARE, GLFW_DONT_CARE);
}

public (WindowManager, void, SetResizeCallback, (ResizeCallbackFunc resizeCallback)) {
  WindowManager->m_resizeCallback = resizeCallback;
}
