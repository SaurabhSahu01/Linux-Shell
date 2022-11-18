#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<dirent.h>
char** split_the_line(char*);
int stringlength(char*);
int findlastposition(char, char*);
char* getDirName(char* , char*);

int main(){
	// getting the current working directory and saving its path for future reference
	char path[256];
	getcwd(path, 256);
    // first thing is to take the input 
    // second thing is to split the line into words and store in a char**
    // third thing is to use the execvp()
    printf("\033[1;35m"); //purple
    printf("\n\n\n\n\n\t\t*** WELCOME TO MY SHELL ***\n\n");
    printf("\t\tCopyright @ Saurabh Sahu\n\n"
        "\t\tUse the shell at your own risk :)\n\n\n\n\n");
    char command[100];
    char cwd[100];
    do{
    	char* finaldirectory = (char *)malloc(50);
    	getcwd(cwd, 100);
        printf("\033[1;32m%s-virtualterminal: ",getenv("USER"));
        printf("\033[1;34m%s ", getDirName(cwd, finaldirectory));
        printf("\033[0;0m");
        printf("$ ");
        free(finaldirectory);
        fflush(stdin);
        scanf("%[^\n]%*c", command);

        /* splitting the line into words */
        char** args  = split_the_line(command);
        /* end */

        if(strcmp(command, "help") == 0){
            printf("\n\n\n\n\n\t\t*** WELCOME TO MY SHELL ***\n\n");
            printf("\t\tCopyright @ Saurabh Sahu\n\n"
                    "\t\tUse the shell at your own risk :)\n\n\n\n\n");
        }

        else if(strcmp(command, "pwd") == 0){
            char cwd[256];
            printf("%s\n",getcwd(cwd, sizeof(cwd)));
        }

        else if(strcmp(args[0], "echo") == 0){
            for(int i=1; args[i]!= NULL;i++){
                printf("%s ",args[i]);
            }
            printf("\n");
        }

        else if(strcmp(args[0],"cd") == 0){
            int status;
            if(strcmp(args[1],"~") == 0){
                status = chdir(getenv("HOME"));
            }
            else{
                status = chdir(args[1]);
            }
            if(status != 0){
                printf("no such file or directory\n");
            }
        }

        else if(strcmp(command, "exit") == 0) break;

        else if(strcmp(args[0], "ls") == 0){
            if(fork() == 0){
            
            	char* finalpath = path;
            	char* command = "/ls";
            	strcat(finalpath, command);
            	
                execvp(finalpath, args);
                exit(0);
            }  
            else{
                wait(NULL);
            } 
        }

        else if(strcmp(args[0], "rm") == 0){
            if(fork() == 0){
            	char* finalpath = path;
            	char* command = "/rm";
            	strcat(finalpath, command);
                execvp(finalpath, args);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }

        else if(strcmp(args[0], "mkdir") == 0){
            if(fork() == 0){
            	char* finalpath = path;
            	char* command = "/mkdir";
            	strcat(finalpath, command);
                execvp(finalpath, args);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }

        else if(strcmp(args[0], "date") == 0){
            if(fork() == 0){
            	char* finalpath = path;
            	char* command = "/date";
            	strcat(finalpath, command);
                execvp(finalpath, args);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }

        else if(strcmp(args[0], "cat") == 0){
            if(fork() == 0){
            	char* finalpath = path;
            	char* command = "/cat";
            	strcat(finalpath, command);
                execvp(finalpath, args);
                exit(0);
            }
            else{
                wait(NULL);
            }
        }

        // for rest of the commands
        else{
            if(fork() == 0){
                int status = execvp(args[0], args);
                if(status == -1){
                    printf("command not found: %s\n",args[0]);
                }
                exit(0);
            }
            else{
                wait(NULL);
            }
        }
    }while (1);
    
    return 0;
}

/* function to split the line into the words */
char** split_the_line(char* line){
    int length = 0;
    int capacity = 16;
    char** token = (char**)malloc(capacity * sizeof(char *));
    char* myline = strtok(line, " - ");
    while(myline != NULL){
        token[length] = myline;
        length++;
        if(length >= capacity){
            token = (char**)realloc(token, length);
        }
        myline = strtok(NULL, " ");
    }
    token[length] = NULL;
    return token;
}
/* end */

// function to get the length of the string
int stringlength(char* string){
    int i= 0;
    while(string[i] != '\0'){
        i++;
    }
    return i;
}

// function to find the last position of the character provided by the user
int findlastposition(char ch, char* string){
    int i=0,j=0;
    int count = 0;
    while(string[i] != '\0'){
        if(string[i] == ch){
            count++;
            j = i;
        }
        i++;
    }
    int returnvalue;
    if(count > 1 ){
    	returnvalue = j;
    }
    else{
    	returnvalue = -1;
    }
    return returnvalue;
}

// function to get the directory name of the current working directory
char* getDirName(char* path, char dirname[]){
    int length = stringlength(path);
    int position = findlastposition('/', path);
    if(position == 0 ) dirname = "/";
    strncpy(dirname, path + position + 1, length - position);
    return dirname;
}