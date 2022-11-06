#ifndef __SCENELIST_H__
#define __SCENELIST_H__

#include <stdio.h>
#include <stdlib.h>

#include "../core/oop.h"
#include "../core/scenetemplate.h"

// Scene headers
#include "menu.scene.h"
#include "test.scene.h"

class (SceneList, (void),
  SceneTemplate **m_scenes;
  int m_sceneCount;
);

public (SceneList, void, AddScene(SceneTemplate *scene));
public (SceneList, SceneTemplate**, GetScenes(void));
public (SceneList, int, GetSceneCount(void));

#endif