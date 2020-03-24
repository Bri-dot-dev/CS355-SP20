#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

void mode_to_str(int mode, char str[]) {
    strcpy(str,"----------");
    if(S_ISDIR(mode)) str[0]='d';   // directory?
    if(S_ISCHR(mode)) str[0]='c';   // terminal?
    if(S_ISBLK(mode)) str[0]='b';   // disk?
    if(S_ISLNK(mode)) str[0]='l';   // link?

    if(mode & S_IRUSR) str[1]='r';  // bits for the user
    if(mode & S_IWUSR) str[2]='w';
    if(mode & S_IXUSR) str[3]='x';

    if(mode & S_IRGRP) str[4]='r';  // bits for the group
    if(mode & S_IWGRP) str[5]='w';
    if(mode & S_IXGRP) str[6]='x';

    if(mode & S_IROTH) str[7]='r';  // bits for the others
    if(mode & S_IWOTH) str[8]='w';
    if(mode & S_IXOTH) str[9]='x';
}

void show_file_info(char *filename, struct stat *info) {
    char modestr[11];
    mode_to_str(info->st_mode, modestr);
    printf("%s ", modestr);
    printf("%4d ", (int)info->st_nlink);
    printf("%8ld ", info->st_size);
    printf("%.20s", ctime(&info->st_mtim.tv_sec));
    printf("%s\n", filename);
}

void do_stat(char *filename) {
    struct stat info;
    if(stat(filename, &info)==-1)
        perror(filename);
    else 
        show_file_info(filename, &info);
}

void do_ls(char *dir_name) {
    DIR *dir_ptr;
    struct dirent *dirent_ptr;
    dir_ptr=opendir(dir_name);
    if(dir_ptr==0) {
        perror("Cannot open directory");
    }
    else {
        while((dirent_ptr=readdir(dir_ptr)) != 0)
            //printf("Directory entry: %s\n", dirent_ptr->d_name);
            do_stat(dirent_ptr->d_name);
        closedir(dir_ptr);
    }
}

int main(int ac, char *av[]) {
    do_ls(".");
    return 0;
}