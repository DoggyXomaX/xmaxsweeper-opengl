#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include <stdio.h>
#include <GL/gl3w.h>
#include "scenelist.h"

scene (MenuScene,
  int m_time;
  const float *m_vertexInput;
  unsigned int m_vbo;
  unsigned int m_ebo;
  unsigned int m_vao;
  unsigned int m_shaderId;
  unsigned int m_vertexCount;
);

#endif  // __MENU_SCENE_H__