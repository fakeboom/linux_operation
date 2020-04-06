#include <unistd.h>  
#include <stdio.h>   
#include <stdlib.h>
#include <string.h>
int main ()   
{   
    size_t sizel = 700000000;
    char * begin = (char *)malloc(sizel);
    if(begin == NULL){
        printf("error : malloc failed");
    }
    pid_t fpid; //fpid表示fork函数返回的值  
    int count=0,i = 0;  
    fpid=fork();   
    printf("father %d----chlid %d\n",getpid(),fpid);
    if (fpid < 0)   
        printf("error in fork!");   
    else if (fpid == 0) {  
        sleep(60);
        printf("i am the child process, my process id is %d\n",getpid()); 
        memset(begin,'a',sizel);
        printf("\ntest ------%c----",begin[10000000]);
        sleep(60);
        count++;  
    }  
    else {  
        sleep(70);
        printf("i am the parent process, my process id is %d\n",getpid());   
        count++;  
    }  
    printf("统计结果是: %d\n",count);  
    return 0;  
}  