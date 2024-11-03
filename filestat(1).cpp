
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>



int main () {
    const char* path = ".";
    struct dirent* file;
    int count[3] = {0,0,0};
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("Error on opening directory");
        return 0;
    }
    while ((file = readdir(dir)) != NULL)
    {
        if (file->d_type == DT_LNK)
            count[0] ++;
        if (file->d_type == DT_REG)
            count[1] ++;
        if (file->d_type == DT_UNKNOWN)
            count[2] ++;
    }
    printf("There's %d links in the current directory.\n", count[0]);
    printf("There's %d regular files in the current directory.\n", count[1]);
    printf("There's %d unknown files in the current directory.\n", count[2]);
    return 0;
}