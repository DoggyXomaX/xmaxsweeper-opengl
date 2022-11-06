#include "scenelist.h"

object (SceneList);

public (SceneList, int, Init()) {
  new (SceneList);
  context (SceneList);

  this->m_sceneCount = 0;
  this->m_scenes = nullptr;

  // Scene defines, should be same as headers
  define_scene(MenuScene);
  define_scene(TestScene);

  return 0;
}

public (SceneList, void, Destroy()) {
  destroy (SceneList);
}

public (SceneList, void, AddScene(SceneTemplate *scene)) {
  context (SceneList);
  if (scene == nullptr)
    return;

  this->m_sceneCount++;
  this->m_scenes = (SceneTemplate**)realloc(this->m_scenes, sizeof(SceneTemplate*) * this->m_sceneCount);
  this->m_scenes[this->m_sceneCount - 1] = scene;
}

public (SceneList, SceneTemplate**, GetScenes()) {
  context (SceneList);
  return this->m_scenes;
}

public (SceneList, int, GetSceneCount()) {
  context (SceneList);
  return this->m_sceneCount;
}
