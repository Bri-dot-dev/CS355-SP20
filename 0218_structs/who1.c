#include <stdio.h>
#include <utmp.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    struct utmp currentRecord;
    int intUTMPfile;
    int UTMPlength = sizeof(currentRecord);
    printf("UTMP file is %s\n", UTMP_FILE);
    intUTMPfile = open(UTMP_FILE, O_RDONLY);
    if(intUTMPfile == -1) {
        perror(UTMP_FILE);
        return 1;
    }
    while(read(intUTMPfile, &currentRecord, UTMPlength) == UTMPlength) {
        printf("%s\n", currentRecord.ut_user); 
    }
    close(intUTMPfile);
    return 0;
}