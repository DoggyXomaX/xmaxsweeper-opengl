#include "core/app.h"

int main(int argc, char *argv[]) {
  int appResult = App_Init(argc, argv);
  printf("App returned %d code.\n", appResult);
  App_Destroy();

  return appResult;
}
