#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    if(argc <= 1) {
        fprintf(stderr, "You must provide a valid folder name! Usage: %s (folder_name)", argv[0]);
        return 1;
    }
    
    if(rmdir(argv[1]) == -1) {
        perror("rmdir");
        return 1;
    }
    return 0;
}
