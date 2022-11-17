#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
void printReg(char *);
void printDir(char *);
void printExec(char *);
int main(int argc, char **args)
{
    if ((strcmp(args[0], "ls") == 0) && args[1] == NULL)
    {
        DIR *dir;
        struct dirent *en;
        dir = opendir(".");
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
                    char path[256];
                    getcwd(path, 256); // pwd
                    strcat(path, "/");
                    strcat(path, en->d_name); // path to the file/directory
                    if (stat(path, &fs) == -1)
                    { // file not exist
                        printf("ls: %s: No such file or directory\n", args[1]);
                    }
                    if (S_ISDIR(fs.st_mode))
                    {
                        printDir(en->d_name);
                    }
                    else if (fs.st_mode & S_IXUSR)
                    {
                        printExec(en->d_name);
                    }
                    else if (S_ISREG(fs.st_mode))
                    {
                        printReg(en->d_name);
                    }
                }
            }
            printf("\n");
        }
    }
    else if ((strcmp(args[0], "ls") == 0) && (args[1] != NULL) && (args[1][0] != '-'))
    {
        DIR *dir;
        struct dirent *en;
        char* path;
        if(args[1][0] == '~'){
            path = getenv("HOME");
            strncat(path, args[1] + 1, sizeof(args[1]) + sizeof(path));
        }
        else{
            path = args[1];
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
                    if (S_ISDIR(fs.st_mode))
                    {
                        printDir(en->d_name);
                    }
                    else if (fs.st_mode & S_IXUSR)
                    {
                        printExec(en->d_name);
                    }
                    else if (S_ISREG(fs.st_mode))
                    {
                        printReg(en->d_name);
                    }
                }
            }
            printf("\n");
        }
    }

    else if ((strcmp(args[0], "ls") == 0) && (strcmp(args[1], "-a") == 0) && (args[2] == NULL))
    {
        DIR *dir;

        struct dirent *en;

        dir = opendir(".");

        if (dir)
        {
            while ((en = readdir(dir)) != NULL)
            {
                struct stat fs;
                char path[256];
                getcwd(path, 256); // pwd
                strcat(path, "/");
                strcat(path, en->d_name); // path to the file/directory
                if (stat(path, &fs) == -1)
                { // file not exist
                    printf("ls: %s: No such file or directory\n", args[2]);
                }
                if (S_ISDIR(fs.st_mode))
                {
                    printDir(en->d_name);
                }
                else if (fs.st_mode & S_IXUSR)
                {
                    printExec(en->d_name);
                }
                else if (S_ISREG(fs.st_mode))
                {
                    printReg(en->d_name);
                }
            }
            printf("\n");
        }
    }
    else if ((strcmp(args[0], "ls") == 0) && (strcmp(args[1], "-a") == 0) && (args[2] != NULL))
    {
        DIR *dir;

        struct dirent *en;
        char* path;
        if(args[2][0] == '~'){
            path = getenv("HOME");
            strncat(path, args[2] + 1, sizeof(args[2]) + sizeof(path));
        }
        else{
            path = args[2];
        }
        dir = opendir(path);

        if (dir)
        {
            while ((en = readdir(dir)) != NULL)
            {
                struct stat fs;
                char finalpath[256];
                strcpy(finalpath, path);
                strcat(finalpath, "/");
                strcat(finalpath, en->d_name);
                if (stat(finalpath, &fs) == -1)
                { // file not exist
                    printf("ls: %s: No such file or directory\n", args[2]);
                }
                else{
                        if (S_ISDIR(fs.st_mode))
                    {
                        printDir(en->d_name);
                    }
                    else if (fs.st_mode & S_IXUSR)
                    {
                        printExec(en->d_name);
                    }
                    else if (S_ISREG(fs.st_mode))
                    {
                        printReg(en->d_name);
                    }
                }
            }
            printf("\n");
        }
    }
    else if ((strcmp(args[0], "ls") == 0) && (strcmp(args[1], "-1") == 0) && (args[2] == NULL))
    {
        DIR *dir;

        struct dirent *en;

        dir = opendir(".");

        if (dir)
        {
            while ((en = readdir(dir)) != NULL)
            {
                struct stat fs;
                char path[256];
                getcwd(path, 256); // pwd
                strcat(path, "/");
                strcat(path, en->d_name); // path to the file/directory
                if (stat(path, &fs) == -1)
                { // file not exist
                    printf("ls: %s: No such file or directory\n", args[2]);
                }
                if (S_ISDIR(fs.st_mode))
                {
                    printDir(en->d_name);
                    printf("\n");
                }
                else if (fs.st_mode & S_IXUSR)
                {
                    printExec(en->d_name);
                    printf("\n");
                }
                else if (S_ISREG(fs.st_mode))
                {
                    printReg(en->d_name);
                    printf("\n");
                }
            }
            printf("\n");
        }
    }
    else if ((strcmp(args[0], "ls") == 0) && (strcmp(args[1], "-1") == 0) && (args[2] != NULL))
    {
        DIR *dir;

        struct dirent *en;
        char* path;
        if(args[2][0] == '~'){
            path = getenv("HOME");
            strncat(path, args[2] + 1, sizeof(args[2]) + sizeof(path));
        }
        else{
            path = args[2];
        }
        dir = opendir(path);

        if (dir)
        {
            while ((en = readdir(dir)) != NULL)
            {
                struct stat fs;
                char finalpath[256];
                strcpy(finalpath, path);
                strcat(finalpath, "/");
                strcat(finalpath, en->d_name);
                if (stat(finalpath, &fs) == -1)
                { // file not exist
                    printf("ls: %s: No such file or directory\n", args[2]);
                }
                if (S_ISDIR(fs.st_mode))
                {
                    printDir(en->d_name);
                    printf("\n");
                }
                else if (fs.st_mode & S_IXUSR)
                {
                    printExec(en->d_name);
                    printf("\n");
                }
                else if (S_ISREG(fs.st_mode))
                {
                    printReg(en->d_name);
                    printf("\n");
                }
            }
            printf("\n");
        }
    }
}

void printReg(char *file)
{
    printf("\033[0;37m%s   ", file);
}
void printDir(char *file)
{
    printf("\033[0;34m%s   ", file);
}
void printExec(char *file)
{
    printf("\033[1;32m%s   ", file);
}