#include "core/app.h"

int main(int argc, char *argv[]) {
    int appResult = AppExec(argc, argv);
    printf("App returned %d code.\n", appResult);

    return appResult;
}
