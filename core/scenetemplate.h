#ifndef __SCENE_TEMPLATE_H__
#define __SCENE_TEMPLATE_H__

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <stdbool.h>

callback (SceneInitEvent, int, (GLFWwindow*));
callback (SceneDestroyEvent, void, (void));
callback (SceneKeyEvent, void, (GLFWwindow*, int, int, int, int));
callback (SceneStartEvent, void, (GLFWwindow*));
callback (SceneUpdateEvent, void, (GLFWwindow*));

typedef struct {
  const char *name;
  SceneInitEvent initFunc;
  SceneDestroyEvent destroyFunc;
  SceneKeyEvent keyFunc;
  SceneStartEvent startFunc;
  SceneUpdateEvent updateFunc;
} SceneTemplate;

#define scene(scene_name, struct_body)                                                    \
  int scene_name##_Init(GLFWwindow *window);                                              \
  void scene_name##_Destroy(void);                                                        \
  void scene_name##_Key(GLFWwindow *window, int key, int scancode, int action, int mods); \
  void scene_name##_Start(GLFWwindow *window);                                            \
  void scene_name##_Update(GLFWwindow *window);                                           \
  extern SceneTemplate scene_name##_template;                                             \
  typedef struct {                                                                        \
    bool __start;                                                                         \
    GLFWwindow *m_window;                                                                 \
    struct_body                                                                           \
  } scene_name##_object

#define init_scene(scene_name, template_name) \
  scene_name##_object *scene_name = nullptr;  \
  SceneTemplate scene_name##_template = {     \
    template_name,                            \
    &scene_name##_Init,                       \
    &scene_name##_Destroy,                    \
    &scene_name##_Key,                        \
    &scene_name##_Start,                      \
    &scene_name##_Update                      \
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