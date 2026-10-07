#include <io.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    if(argc <= 1) {
        fprintf(stderr, "You must provide a valid path! Usage: %s (path)", argv[0]);
        return 1;
    }

    const char* path = argv[1];
    if(chdir(path) == -1) {
        perror("chdir");
        return 1;
    }

    char wd[1024];
    if(getcwd(wd, 1024) == NULL) {
        perror("getcwd");
        return 1;
    }

    printf("%s\n", wd);
    return 0;
}
