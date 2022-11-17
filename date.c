#include<unistd.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
char* day(int);
char* month(int);
int main(int argc, char** args){
    if((strcmp(args[0], "date") == 0) && args[1] == NULL){
        time_t t;
        time(&t);
        printf("%s",ctime(&t));
    }
    else{
         if(strcmp(args[1], "-u") == 0){
            time_t t;
            struct tm* info;

            time(&t);

            info = gmtime(&t);

            printf("%s %s %d %d:%d:%d UTC %d\n",day(info->tm_wday), month(info->tm_mon), info->tm_mday, info->tm_hour,info->tm_min, info->tm_sec, (1900+info->tm_year));
        }
    }
}

char* day(int num){
    char* value;
    switch(num){
        case(0): value = "Sun"; break;
        case(1): value = "Mon"; break;
        case(2): value = "Tue"; break;
        case(3): value = "Wed"; break;
        case(4): value = "Thu"; break;
        case(5): value = "Fri"; break;
        case(6): value = "Sat"; break;    
    }
    return value;
}

char* month(int num){
    char* value;
    switch(num){
        case(0): value = "Jan"; break;
        case(1): value = "Feb"; break;
        case(2): value = "Mar"; break;
        case(3): value = "Apr"; break;
        case(4): value = "May"; break;
        case(5): value = "Jun"; break;
        case(6): value = "Jul"; break;
        case(7): value = "Aug"; break;
        case(8): value = "Sep"; break;
        case(9): value = "Oct"; break;
        case(10): value = "Nov"; break;
        case(11): value = "Dec"; break;
    }
    return value;
}