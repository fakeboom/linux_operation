#include <unistd.h>  
#include <stdio.h>   
int main ()   
{   
    char * begin = (char *)malloc(1000000000);
    pid_t fpid; //fpid表示fork函数返回的值  
    int count=0,i = 0;  
    fpid=fork();   
    if (fpid < 0)   
        printf("error in fork!");   
    else if (fpid == 0) {  
        sleep(60);
        printf("i am the child process, my process id is %d\n",getpid()); 
        for(i =0;i<1000000000;i++){
            begin[i] = 'a';
        }  
        printf("\ntest ------%c----",begin[10000000])
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