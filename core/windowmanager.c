#include "windowmanager.h"

// const:
const char *START_TITLE = "XmaxSweeper OpenGL";
const int START_WIDTH = 640;
const int START_HEIGHT = 360;

// private:
WindowManager_private *WindowManager = NULL;

void WindowManager_OnResize(GLFWwindow *window, int w, int h) {
  WindowManager->m_width = w > WindowManager->m_minWidth ? w : WindowManager->m_minWidth;
  WindowManager->m_height = h > WindowManager->m_minHeight ? h : WindowManager->m_minHeight;
  if (WindowManager->m_resizeCallback != NULL)
    WindowManager->m_resizeCallback(window, w, h);
}

// public:
int WindowManager_Init(GLFWwindow **out_window) {
  WindowManager = (WindowManager_private*)malloc(sizeof(WindowManager_private));

  WindowManager->m_startTitle = START_TITLE;
  WindowManager->m_startWidth = &START_WIDTH;
  WindowManager->m_startHeight = &START_HEIGHT;

  WindowManager->m_width = *(WindowManager->m_startWidth);
  WindowManager->m_height = *(WindowManager->m_startHeight);
  WindowManager->m_minWidth = 320;
  WindowManager->m_minHeight = 180;

  WindowManager->m_window = NULL;
  WindowManager->m_resizeCallback = NULL;

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  WindowManager->m_window = glfwCreateWindow(*(WindowManager->m_startWidth), *(WindowManager->m_startHeight), WindowManager->m_startTitle, NULL, NULL);
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

void WindowManager_Destroy() {
  free(WindowManager);
}

void WindowManager_SetMinimumWindowSize(int baseWidth) {
  WindowManager->m_minWidth = baseWidth < 16 ? 16 : baseWidth;
  WindowManager->m_minHeight = WindowManager->m_minWidth / 16 * 9;
  glfwSetWindowSizeLimits(WindowManager->m_window, WindowManager->m_minWidth, WindowManager->m_minHeight, GLFW_DONT_CARE, GLFW_DONT_CARE);
}

void WindowManager_SetResizeCallback(ResizeCallbackFunc resizeCallback) {
  WindowManager->m_resizeCallback = resizeCallback;
}
