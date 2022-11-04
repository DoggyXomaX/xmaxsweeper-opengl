#include "menu.scene.h"

MenuScene_private *MenuScene = NULL;

int MenuScene_Init(GLFWwindow *window) {
  MenuScene = (MenuScene_private*)malloc(sizeof(MenuScene_private));
}

void MenuScene_Destroy() {
  free(MenuScene);
}

void MenuScene_Start(GLFWwindow *window) {
}

void MenuScene_Update(GLFWwindow *window) {
}