#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
    pid_t pid;
    unsigned int tP = 2;
    unsigned int tC = 5;

    printf ("Main: ");
    printf("PID=%d \t ; My parent PID=%d\n",getpid(), getppid());

    pid = fork();

    if (pid < 0) {  
        // fork error
        fprintf(stderr, "Fork Failed \n");
        return 1;
    }
    else {
        if (pid == 0){
            // child process
            sleep(tC);
            printf("Child: PID returned = %d", pid);
            printf("Child PID=%d; \t My parent PID = %d \n", getpid(), getppid());
        }
        else {
            sleep(tP);
            printf("Parent: PID returned = %d", pid);
            printf("Parent PID=%d; \t My parent PID = %d \n", getpid(), getppid());
        }
    }   
    return(EXIT_SUCCESS);
}