#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define COPYMODE 0644
#define BUFFERSIZE 1024

int main(int ac, char *av[]) {
    int source, target;
    char buffer[BUFFERSIZE];
    int numBytes;

    if(ac!=3) {
        printf("Usage: %s source target\n", av[0]);
        return 1;
    }

    source=open(av[1], O_RDONLY);
    if(source==-1) {
        perror("Cannot open source file");
        return 1;
    }
    target=creat(av[2], COPYMODE);
    if(target==-1) {
        perror("Cannot create target file");
        return 1;
    }

    while((numBytes=read(source,buffer,BUFFERSIZE))>0) {
        if(write(target, buffer, numBytes) != numBytes) {
            perror("Write error");
            return 1;
        }
    }

    if(close(source)==-1 || close(target)==-1) {
        perror("Error closing files");
        return 1;
    }
    return 0;
}