#include <fcntl.h>
#include <io.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if(argc <= 1) {
        fprintf(stderr, "You must provide a valid file! Usage: %s (file_name)", argv[0]);
        return 1;
    }
    char buf[2048];
    int f = _open(argv[1], _O_RDONLY );
    if(f == -1) {
        fprintf(stderr, "Invalid file name!\n");
        return 1;
    }
    read(f, buf, 2048);
    printf("%s", buf);
    return 0;
}
