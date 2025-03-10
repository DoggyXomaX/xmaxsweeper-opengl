#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include <stdio.h>
#include <GL/gl3w.h>
#include "scenelist.h"

scene (MenuScene,
  int m_time;
  GLuint m_vbo;
  GLuint m_vao;
  GLuint m_ebo;
  GLuint m_shaderId;
);

#endif  // __MENU_SCENE_H__