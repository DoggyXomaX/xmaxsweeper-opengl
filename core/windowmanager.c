#include "windowmanager.h"

// private:
GLFWwindow *m_window = NULL;
const char m_startTitle[] = "XmaxSweeper OpenGL";
const int m_startWidth = 640;
const int m_startHeight = 360;
int m_width;
int m_height;
int m_minWidth = 320;
int m_minHeight = 180;

void WindowManager_OnResize(GLFWwindow *window, int w, int h) {
  m_width = w > 300 ? w : 300;
  m_height = h > 200 ? h : 200;
  glViewport(0, 0, m_width, m_height);
}

void WindowManager_Update(GLFWwindow *window) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glfwSwapBuffers(window);
}

// public:
int WindowManager_Init(int argc, char *argv[]) {
  m_width = m_startWidth;
  m_height = m_startHeight;

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  m_window = glfwCreateWindow(m_startWidth, m_startHeight, m_startTitle, NULL, NULL);
  if (m_window == NULL) {
    fprintf(stderr, "Failed to create GLFW window\n");
    glfwTerminate();
    return -1;
  }

  glfwSetWindowSizeLimits(m_window, 320, 180, GLFW_DONT_CARE, GLFW_DONT_CARE);
  glfwSetWindowAspectRatio(m_window, 16, 9);
  glfwSetFramebufferSizeCallback(m_window, WindowManager_OnResize);
  glfwSetWindowRefreshCallback(m_window, WindowManager_Update);

  glfwMakeContextCurrent(m_window);

  if (gl3wInit()) {
    fprintf(stderr, "Failed to gl3w initialize OpenGL\n");
    return -2;
  }

  if (!gl3wIsSupported(3, 3)) {
    fprintf(stderr, "OpenGL 3.3 not supported\n");
    return -3;
  }

  printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

  glClearDepth(1.0);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glEnable(GL_DEPTH_TEST);

  while (!glfwWindowShouldClose(m_window)) {
    WindowManager_Update(m_window);
    EventManager_OnInput(m_window);
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}

void WindowManager_SetMinimumWindowSize(int baseWidth) {
  m_minWidth = baseWidth < 16 ? 16 : baseWidth;
  m_minHeight = m_minWidth / 16 * 9;
  glfwSetWindowSizeLimits(m_window, m_minWidth, m_minHeight, GLFW_DONT_CARE, GLFW_DONT_CARE);
}