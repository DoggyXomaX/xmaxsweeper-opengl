#include "windowmanager.h"

const char DEFAULT_TITLE[] = "XmaxSweeper OpenGL";
const int DEFAULT_WIDTH = 640;
const int DEFAULT_HEIGHT = 360;
const int DEFAULT_MIN_WIDTH = 320;
const int DEFAULT_MIN_HEIGHT = 180;

object (WindowManager);

private (WindowManager, void, OnResize(GLFWwindow *window, int w, int h)) {
  context (WindowManager);

  this->m_width = w > this->m_minWidth ? w : this->m_minWidth;
  this->m_height = h > this->m_minHeight ? h : this->m_minHeight;
  if (this->m_resizeCallback != nullptr)
    this->m_resizeCallback(window, this->m_width, this->m_height);
}

public (WindowManager, int, Init(GLFWwindow **out_window)) {
  new (WindowManager);
  context (WindowManager);

  this->m_window = nullptr;
  this->m_resizeCallback = nullptr;
  this->m_width = DEFAULT_WIDTH;
  this->m_height = DEFAULT_HEIGHT;
  this->m_minWidth = DEFAULT_MIN_WIDTH;
  this->m_minHeight = DEFAULT_MIN_HEIGHT;

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  this->m_window = glfwCreateWindow(this->m_width, this->m_height, DEFAULT_TITLE, nullptr, nullptr);
  if (this->m_window == nullptr) {
    fprintf(stderr, "Failed to create GLFW window\n");
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(this->m_window);

  glfwSetWindowSizeLimits(this->m_window, this->m_minWidth, this->m_minHeight, GLFW_DONT_CARE, GLFW_DONT_CARE);
  glfwSetWindowAspectRatio(this->m_window, 16, 9);
  glfwSetFramebufferSizeCallback(this->m_window, func (WindowManager, OnResize));

  *out_window = this->m_window;

  return 0;
}

public (WindowManager, void, Destroy()) {
  destroy (WindowManager);
}

public (WindowManager, void, SetMinimumWindowSize(int baseWidth)) {
  context (WindowManager);
  this->m_minWidth = baseWidth < 16 ? 16 : baseWidth;
  this->m_minHeight = this->m_minWidth / 16 * 9;
  glfwSetWindowSizeLimits(this->m_window, this->m_minWidth, this->m_minHeight, GLFW_DONT_CARE, GLFW_DONT_CARE);
}

public (WindowManager, void, SetResizeCallback(ResizeCallbackFunc resizeCallback)) {
  context (WindowManager);
  this->m_resizeCallback = resizeCallback;
}

