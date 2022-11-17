#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
int main(int argc, char** args){
    if(args[1] == NULL){
        printf("rm: missing operand\n");
    }
    else if((strcmp(args[1], ".") == 0) || (strcmp(args[1], "..") == 0)){
        printf("rm: refusing to remove '.' or '..' directory: skipping '%s'\n", args[1]);
    }
    else if(args[1][0] != '-'){
        char* path;
        if(args[1][0] == '~'){
            path = getenv("HOME");
            strncat(path, args[1] + 1, sizeof(args[1]) + sizeof(path));
        }
        else{
            path = args[1];
        }
        struct stat fs;
        if(stat(path, &fs) == -1){ // file doesn't exist
            printf("rm: cannot remove '%s': No such file or directory\n",path);
        }
        else{
            if(S_ISDIR(fs.st_mode)){
                printf("rm: cannot remove '%s': Is a directory\n", path);
            }
            else{
                remove(path);
            }
        }
    }
    else if((strcmp(args[1], "-r") == 0) && args[2] != NULL){
        DIR *dir;
        struct dirent *en;
        char* path;
        if(args[2][0] == '~'){
            path = getenv("HOME");
            strncat(path, args[1] + 1, sizeof(args[2]) + sizeof(path));
        }
        else{
            path = args[2];
        }
        dir = opendir(path);
        if (dir)
        {
            while ((en = readdir(dir)) != NULL)
            {
                if (en->d_name[0] == '.')
                {
                    continue;
                }
                else
                {
                    struct stat fs;
                    char finalpath[256];
                    strcpy(finalpath, path);
                    strcat(finalpath, "/");
                    strcat(finalpath, en->d_name);
                    if (stat(finalpath, &fs) == -1)
                    { // file not exist
                        printf("ls: %s: No such file or directory\n", path);
                    }
                    printf("%s\n",finalpath);
                    remove(finalpath);
                }
            }
        }
        remove(path);
    }
}