#ifndef __SCENE_TEMPLATE__
#define __SCENE_TEMPLATE__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdbool.h>

typedef struct {
  const char *name;
  int (*initFunc)(GLFWwindow*);
  void (*destroyFunc)(void);
  void (*startFunc)(GLFWwindow*);
  void (*updateFunc)(GLFWwindow*);
} SceneTemplate;

#define scene(scene_name, struct_body)          \
  int scene_name##_Init(GLFWwindow *window);    \
  void scene_name##_Destroy(void);              \
  void scene_name##_Start(GLFWwindow *window);  \
  void scene_name##_Update(GLFWwindow *window); \
  extern SceneTemplate scene_name##_template;   \
  typedef struct {                              \
    bool __start;                               \
    GLFWwindow *m_window;                       \
    struct_body                                 \
  } scene_name##_object

#define init_scene(scene_name, template_name) \
  scene_name##_object *scene_name = nullptr;    \
  SceneTemplate scene_name##_template = {       \
    template_name,                              \
    &scene_name##_Init,                         \
    &scene_name##_Destroy,                      \
    &scene_name##_Start,                        \
    &scene_name##_Update                        \
  }

#define first_update(scene_name) \
  if (scene_name->__start) {     \
    scene_name->__start = false; \
    scene_name##_Start(window);  \
  }

#define new_scene(scene_name)                                             \
  scene_name = (scene_name##_object*)malloc(sizeof(scene_name##_object)); \
  scene_name->m_window = window;                                          \
  scene_name->__start = true

#define define_scene(scene_name) \
  invoke (SceneList, AddScene(&scene_name##_template))

#endif // __SCENE_TEMPLATE__