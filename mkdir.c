#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
int main(int argc, char** args){
    if(strcmp(args[1], "-v") == 0){
        int i = 2;
        while(args[i] != NULL){
            DIR* dir = opendir(args[i]);

            if(dir){
                printf("mkdir: %s: File exists\n", args[i]);
                closedir(dir);
            }
            else{
                int status = mkdir(args[i], 0666);
                if(status){
                    printf("mkdir: %s: No such file or directory\n", args[i]);
                }
                else{
                    printf("mkdir: created directory '%s'\n",args[i]);
                }
            }
            i++;    
        }
    }
    else if(strcmp(args[1], "-m") == 0){
        int i = 3;
        if(args[2][1] != '='){
            printf("usage: mkdir [-pv] [-m mode] directory ...\n");
        }
        else{
            while(args[i] != NULL){
                DIR* dir = opendir(args[i]);
                if(dir){
                    printf("mkdir: %s: File exists\n", args[i]);
                    closedir(dir);
                }
                else{
                    if(strcmp(args[2], "a=rwx") == 0){
                        int status = mkdir(args[i], 0777);
                        if(status){
                            printf("mkdir: %s: No such file or directory\n", args[1]);
                        }
                    }
                    else if(strcmp(args[2], "a=r")){
                        int status = mkdir(args[i], 0444);
                        if(status) printf("mkdir: %s: No such file or directory\n", args[1]);
                    }
                    else if(strcmp(args[2], "a=w")){
                        int status = mkdir(args[i], 0222);
                        if(status) printf("mkdir: %s: No such file or directory\n", args[1]);
                    }
                    else if(strcmp(args[2], "a=x")){
                        int status = mkdir(args[i], 0111);
                        if(status) printf("mkdir: %s: No such file or directory\n", args[1]);
                    }
                    else if(strcmp(args[2], "a=rw")){
                        int status = mkdir(args[i], 0666);
                        if(status) printf("mkdir: %s: No such file or directory\n", args[1]);
                    }
                    else if(strcmp(args[2], "a=rx")){
                        int status = mkdir(args[i], 0555);
                        if(status) printf("mkdir: %s: No such file or directory\n", args[1]);
                    }
                    else if(strcmp(args[2], "a=wx")){
                        int status = mkdir(args[i], 0333);
                        if(status) printf("mkdir: %s: No such file or directory\n", args[1]);
                    }
                    else{
                        
                    }
                }
                i++;
            }
        }
    }
    else{
        int i = 1;
        while(args[i] != NULL){
            char* path;
            if(args[i][0] == '~'){
                path = getenv("HOME");
                strncat(path, args[i] + 1, sizeof(path) + sizeof(args[i]));
                printf("%s\n",path);
            }
            DIR* dir = opendir(path);
            // if directory exists
            if(dir){
                printf("mkdir: %s: File exists\n", args[i]);
                closedir(dir);
            }
            // if directory doesn't exist
            else{
                int status = mkdir(args[i], 0666);
                if(status){
                    printf("mkdir: %s: No such file or directory\n", args[i]);
                }
            }
            i++;
        }
    }
}