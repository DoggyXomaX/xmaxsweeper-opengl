#include "app.h"

int AppExec(int argc, char *argv[]) {
  printf("App executed!\n");

  return WindowManager_Init(argc, argv);
}
