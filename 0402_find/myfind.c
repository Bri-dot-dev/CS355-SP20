#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void do_find(char*);

void process_entry(char *filename) {
    struct stat info;
    if(stat(filename, &info)==-1)
        perror(filename);
    else 
        if(S_ISDIR(info.st_mode)) {
            printf("%s is a directory\n", filename);
            //do_find(filename);
        }
        if(1){
            /*strstr() should be used in the condition above*/
            printf("Directory entry: %s\n", filename);
        }
}

void do_find(char *dir_name) {
    DIR *dir_ptr;
    struct dirent *dirent_ptr;
    dir_ptr=opendir(dir_name);
    if(dir_ptr==0) {
        perror("Cannot open directory");
    }
    else {
        while((dirent_ptr=readdir(dir_ptr)) != 0)
            process_entry(dirent_ptr->d_name);
        closedir(dir_ptr);
    }
}

int main(int ac, char *av[]) {
    do_find(".");
    return 0;
}