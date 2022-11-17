#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char** args){

    FILE* fp;

    if(strcmp(args[1], "-n") == 0){
        int i = 2;
        int count = 1;
        while(args[i] != NULL){
            fp = fopen(args[i], "r");
            if(fp != NULL){
                char ch;
                printf("1.)");
                do{
                    ch = fgetc(fp);
                    if(ch == '\n'){
                        printf("%c",ch);
                        printf("%d.)",count);
                        count++;
                    }
                    else{
                        printf("%c", ch);
                    }
                }while(ch != EOF);
            }
            i++;
            fclose(fp);
        }
    
    }

    else if(strcmp(args[1], "-s") == 0){
        int i = 2;
        while(args[i] != NULL){
            fp = fopen(args[i], "r");
            if(fp != NULL){
                char ch;
                int count = 0;
                do{
                    ch = fgetc(fp);
                    if(ch == '\n'){
                        count++;
                        if(count > 1){
                            continue;
                        }
                        else{
                            printf("%c", ch);
                        }
                    }
                    else{
                        count = 0;
                        printf("%c",ch);
                    }
                }while(ch != EOF);
            }
            i++;

            fclose(fp);
        }
    }

    else{
        int i = 1;
        while(args[i] != NULL){
            fp = fopen(args[i], "r");
            if(fp != NULL){
                char ch;
                do{
                    ch = fgetc(fp);
                    printf("%c",ch);
                }while(ch != EOF);
            }
            fclose(fp);

            i++;
        }
    }
}