#include "scenemanager.h"

object (SceneManager);

private (SceneManager, SceneTemplate**, GetScenes()) {
  context (SceneManager);
  return invoke (SceneList, GetScenes());
}

public (SceneManager, int, Init(GLFWwindow *window)) {
  new (SceneManager);
  context (SceneManager);

  this->m_window = window;
  this->m_currentScene = nullptr;
  
  int result = invoke (SceneList, Init());
  if (result != 0) {
    fprintf(stderr, "Failed to initialize SceneList!\n");
    return result;
  }

  return 0;
}

public (SceneManager, void, Destroy()) {
  if (SceneManager->m_currentScene != nullptr) {
    if (SceneManager->m_currentScene->destroyFunc != nullptr)
      SceneManager->m_currentScene->destroyFunc();
  }
  destroy (SceneManager);
}

public (SceneManager, void, ChangeScene(int index)) {
  context(SceneManager);

  printf("Changing scene to #%d...\n", index);
  SceneTemplate *scene = invoke (SceneManager, GetSceneByIndex(index));
  if (scene == nullptr) {
    fprintf(stderr, "Error: scene #%d was not found!\n", index);
    return;
  }
  
  if (this->m_currentScene != nullptr) {
    printf("Destroying previous \"%s\" scene...\n", this->m_currentScene->name);
    this->m_currentScene->destroyFunc();
  }

  this->m_currentScene = scene;

  printf("Initializing new scene \"%s\"...\n", this->m_currentScene->name);
  this->m_currentScene->initFunc(this->m_window);

  puts("Applying update frame...");
  invoke (GameManager, SetUpdateCallback(this->m_currentScene->updateFunc));

  puts("Scene was changed successfully!");
}

public (SceneManager, SceneTemplate*, GetSceneByIndex(int index)) {
  context(SceneManager);

  int sceneCount = invoke (SceneManager, GetSceneCount());
  if (index < 0 || index >= sceneCount)
    return nullptr;

  SceneTemplate **scenes = invoke (SceneManager, GetScenes());
  return scenes[index];
}

public (SceneManager, SceneTemplate*, GetSceneByName(const char *name)) {
  context (SceneManager);

  int sceneCount = invoke (SceneManager, GetSceneCount());
  SceneTemplate **scenes = invoke (SceneManager, GetScenes());
  for (int i = 0; i < sceneCount; i++)
    if (strcmp(scenes[i]->name, name) == 0)
      return scenes[i];

  return nullptr;
}

public (SceneManager, int, GetSceneCount()) {
  context (SceneManager);
  return invoke (SceneList, GetSceneCount());
}