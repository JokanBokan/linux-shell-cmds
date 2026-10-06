#include <io.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if(argc <= 1) {
        fprintf(stderr, "You must provide a folder name! Usage: %s (folder name)", argv[0]);
        return 1;
    }
    int result = mkdir(argv[1]);
    if(result == -1) {
        perror("mkdir");
        return 1;
    }
    printf("Directory by the name of '%s' was successfully created", argv[1]);
    return 0;
}
