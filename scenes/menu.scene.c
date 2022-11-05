#include "menu.scene.h"

object (MenuScene);

public (MenuScene, int, Init, (GLFWwindow *window)) {
  new (MenuScene);
}

public (MenuScene, void, Destroy, ()) {
  destroy (MenuScene);
}

public (MenuScene, void, Start, (GLFWwindow *window)) {
  // Start scene
}

public (MenuScene, void, Update, (GLFWwindow *window)) {
  // Update scene
}
