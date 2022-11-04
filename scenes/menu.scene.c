#include "menu.scene.h"

$OBJECT(MenuScene);

$PUBLIC(int, MenuScene, Init, (GLFWwindow *window)) {
  $NEW(MenuScene);
}

$PUBLIC(void, MenuScene, Destroy, ()) {
  $DESTROY(MenuScene);
}

$PUBLIC(void, MenuScene, Start, (GLFWwindow *window)) {
  // Start scene
}

$PUBLIC(void, MenuScene, Update, (GLFWwindow *window)) {
  // Update scene
}
