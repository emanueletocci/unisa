#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (int argc, char *argv[]) {

    printf("MAIN: PID=%d ; shell PID = %d\n", getpid(),getppid());

    pid_t pid1, pid2;

    pid1 = fork();   
    pid2 = fork();

    if (pid1 < 0) {  
        // fork 1 error
        fprintf(stderr, "Fork 1 Failed \n");
        exit(1);
    }
    else
        if (pid1 == 0){
            // child process 1
            printf("CHILD: PID returned = %d \t PID = %d \t My parent PID = %d \n", pid1, getpid(), getppid());
            exit(0);
        }
        else {
            //parent process 1
            wait(NULL);
            printf("PARENT: PID returned = %d \t PID = %d \t My parent PID = %d \n", pid1, getpid(), getppid());
        }  

    if (pid2 < 0){
        // fork 2 error
        fprintf(stderr, "Fork 2 Failed \n");
        exit(1);                
    }
    else
        if (pid2 == 0 ){
            // child process 2
            printf("CHILD: PID returned = %d \t PID = %d \t My parent PID = %d \n", pid2, getpid(), getppid());
            exit(0);
        }
        else {
            // parent process 2
            wait(NULL);
            printf("PARENT: PID returned = %d \t PID = %d \t My parent PID = %d \n", pid2, getpid(), getppid());
        }    
}