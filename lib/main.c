#include "../include/core.h"

int main(int argc, char *argv[]) {
    const char *path = (argc >= 2) ? argv[1] : ".";

    printf("Files in directory '%s':\n", path);
    list_files(path);

    return 0;
}

// directory -- files inside .... 
// 0 0 0 0 0
// 0 0 0 0 0 
// 0 0 0 0 0 