#include "../include/core.h"

void list_files(const char *basepath) {
    struct dirent *dp;
    DIR *dir = opendir(basepath);

    if (!dir) {
        return; // Directory could not be opened
    }

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            char path[1024];
            snprintf(path, sizeof(path), "%s/%s", basepath, dp->d_name);

            struct stat statbuf;
            if (stat(path, &statbuf) != 0) {
                continue; // Skip if unable to read the file status
            }

            if (S_ISDIR(statbuf.st_mode)) {
                list_files(path);
            } else {
                printf("%s\n", path);
            }
        }
    }

    closedir(dir);
}