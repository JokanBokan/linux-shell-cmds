#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int show_dots = 0;

int main(int argc, char** argv) {
    int opt;
    while((opt = getopt(argc, argv, "a")) != -1) {
        switch(opt) {
            case 'a' :
                show_dots = 1;
                break;
            default: 
                printf("Usage: %s [flag] [path or nothing]", argv[0]);
                exit(1);
                break; 
        }
    }
    const char* path = (optind < argc) ? *(argv + optind) : ".";
    DIR* root = opendir(path);
    if(!root) {
        perror("opendir");
        return 1;
    }
    struct dirent* temp;

    printf("NAME\t\t\tLENGHT\n-------------------------\n");
    while((temp = readdir(root)) != NULL) {
        if(!show_dots && temp->d_name[0] == '.') {
            continue;
        }
        printf("%s\t\t\tTEMP\n", temp->d_name);    
    }
    closedir(root);
    return 0;
}
