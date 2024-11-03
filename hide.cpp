#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

const char *hidenDirectory = "./.hide_directory";


int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Path to file not found. You must write: hide <filename>\n");
        return 1;
    }
    struct stat str;
    char *fileName = argv[1];

    if (stat(fileName, &str) != 0) {
        printf("File %s does not exist.\n", fileName);
        return 1;
    }

    mkdir(hidenDirectory, 0755);

    char newFile[1024];
    snprintf(newFile, sizeof(newFile), "%s/%s", hidenDirectory, fileName);

    if (rename(fileName, newFile) != 0) {
        perror("Failed to move file");
        return 1;
    }

    if (chmod(hidenDirectory, 311) != 0) {
        perror("Failed to set permissions for hiden directory");
        return 1;
    }

    printf("File %s has been hidden in %s\n", fileName, newFile);
    return 0;
}