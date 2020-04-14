#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 1024

int main(int ac, char *av[]){
    if(ac!=2)
        /* You may need to add /dev before ttyname, e.g. /dev/pts/1 */
        fprintf(stderr, "usage: %s ttyname\n", av[0]);
    else {
        int fd=open(av[1], O_WRONLY);
        if(fd==-1)
            perror(av[1]);
        else {
            char buf[BUFSIZE];
            while(fgets(buf, BUFSIZE, stdin)!=0) {
                if(write(fd, buf, strlen(buf))==-1)
                    break;
            }
            close(fd);
        }
    }
}