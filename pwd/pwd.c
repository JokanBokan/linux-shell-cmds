#include <stdio.h>
#include <unistd.h>

int main() {
    char cwd[1024];
    if(getcwd(cwd, 1024) == NULL) {
        perror("getcwd");
        return 1;
    }
    printf("%s\n", cwd);
    return 0;
}
