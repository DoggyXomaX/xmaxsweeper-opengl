#include "menu.scene.h"

const float TRIANGLE[9] = {
  -0.5f, -0.5f, 0.0f,
   0.5f, -0.5f, 0.0f,
   0.0f,  0.5f, 0.0f,
};

#include <basic.vert.h>
#include <basic.frag.h>

init_scene (MenuScene, "menu");

public (MenuScene, int, Init(GLFWwindow *window)) {
  new_scene (MenuScene);
  context (MenuScene);

  this->m_time = 0;
  this->m_vertexInput = TRIANGLE;
  this->m_vertexCount = lengthof(TRIANGLE);

  return 0;
}

public (MenuScene, void, Destroy()) {
  destroy (MenuScene);
}

public (MenuScene, void, Start(GLFWwindow *window)) {
  context (MenuScene);
  puts("Menu scene start");
  glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
  
  glGenBuffers(1, &this->m_vbo);
  glGenVertexArrays(1, &this->m_vao);
  glBindVertexArray(this->m_vao);
  glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(TRIANGLE), this->m_vertexInput, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Vertex shader
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &BASIC_VERT, NULL);
  glCompileShader(vertexShader);
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    fprintf(stderr, "Failed to compile vertex shader:\n%s\n", infoLog);
    return;
  }

  // Fragment shader
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &BASIC_FRAG, NULL);
  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    fprintf(stderr, "Failed to compile fragment shader:\n%s\n", infoLog);
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
    fprintf(stderr, "Failed to link shader program:\n%s\n", infoLog);
    return;
  }
  glUseProgram(this->m_shaderId);
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

public (MenuScene, void, Update(GLFWwindow *window)) {
  context (MenuScene);
  first_update (MenuScene);

  this->m_time++;
  if (this->m_time >= 60) {
    this->m_time = 0;
    printf("Vertex shader:\n%s\n", BASIC_VERT);
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
  glUseProgram(this->m_shaderId);
  glBindVertexArray(this->m_vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  
  glfwSwapBuffers(window);
}
