#ifndef __SCENEMANAGER_H__
#define __SCENEMANAGER_H__

#include <stdlib.h>

#define scene(scene_name, struct_body)   \
  int scene_name##_Init(GLFWwindow *window);    \
  void scene_name##_Destroy(void);              \
  void scene_name##_Start(GLFWwindow *window);  \
  void scene_name##_Update(GLFWwindow *window); \
  typedef struct {                              \
    struct_body                                 \
  } scene_name##_private;

#endif // __SCENEMANAGER_H__