#include "menu.scene.h"

GLfloat TRIANGLE[] = {
     0.5f,  0.5f, 0.0f,  // Верхний правый угол
     0.5f, -0.5f, 0.0f,  // Нижний правый угол
    -0.5f, -0.5f, 0.0f,  // Нижний левый угол
    -0.5f,  0.5f, 0.0f   // Верхний левый угол
};

GLuint INDICES[] = {
  0, 1, 3,
  1, 2, 3
};

#include <basic.vert.h>
#include <basic.frag.h>

init_scene (MenuScene, "menu");

public (MenuScene, int, Init(GLFWwindow *window)) {
  new_scene (MenuScene);
  context (MenuScene);

  this->m_time = 0;

  this->m_vbo = 0;
  this->m_ebo = 0;
  this->m_vao = 0;

  return 0;
}

public (MenuScene, void, Destroy()) {
  context (MenuScene);

  if (this->m_vbo != 0)
    glDeleteBuffers(1, &this->m_vbo);
  
  if (this->m_ebo != 0)
    glDeleteBuffers(1, &this->m_ebo);

  if (this->m_vao != 0)
    glDeleteVertexArrays(1, &this->m_vao); 

  destroy (MenuScene);
}

public (MenuScene, void, Key(GLFWwindow *window, int key, int scancode, int action, int mods)) {
  if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
    puts("MenuScene: LEFT");

  if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    puts("MenuScene: UP");

  if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    puts("MenuScene: RIGHT");

  if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
    puts("MenuScene: DOWN");
}

public (MenuScene, void, Start(GLFWwindow *window)) {
  context (MenuScene);
  puts("MenuScene: START");
  glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
  
  // Gen buffers
  glGenBuffers(1, &this->m_vbo);
  glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(TRIANGLE), TRIANGLE, GL_STATIC_DRAW);

  // Gen element buffer
  glGenBuffers(1, &this->m_ebo);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(INDICES), INDICES, GL_STATIC_DRAW);
  
  // Gen vertex arrays
  glGenVertexArrays(1, &this->m_vao);
  glBindVertexArray(this->m_vao);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(0);
 
  // Unbind all
  glBindVertexArray(0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Vertex shader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &BASIC_VERT, NULL);
  glCompileShader(vertexShader);
  GLint success;
  GLchar infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    fprintf(stderr, "MenuScene: Failed to compile vertex shader:\n%s\n", infoLog);
    return;
  }

  // Fragment shader
  GLint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &BASIC_FRAG, NULL);
  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    fprintf(stderr, "MenuScene: Failed to compile fragment shader:\n%s\n", infoLog);
    return;
  }

  // Shader program
  this->m_shaderId = glCreateProgram();
  glAttachShader(this->m_shaderId, vertexShader);
  glAttachShader(this->m_shaderId, fragmentShader);
  glLinkProgram(this->m_shaderId);
  glGetProgramiv(this->m_shaderId, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(this->m_shaderId, 512, NULL, infoLog);
    fprintf(stderr, "MenuScene: Failed to link shader program:\n%s\n", infoLog);
    return;
  }
  glUseProgram(this->m_shaderId);
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  puts("MenuScene: Start complete");
}

public (MenuScene, void, Update(GLFWwindow *window)) {
  first_update (MenuScene);
  context (MenuScene);

  this->m_time++;
  if (this->m_time >= 60) {
    this->m_time = 0;
    puts("MenuScene: TICK");
    fflush(stdout);
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glUseProgram(this->m_shaderId);

  glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo);
  glBindVertexArray(this->m_vao);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ebo);
  
  glDrawElements(GL_TRIANGLES, lengthof(INDICES), GL_UNSIGNED_INT, 0);
  
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);  

  glfwSwapBuffers(window);
}
