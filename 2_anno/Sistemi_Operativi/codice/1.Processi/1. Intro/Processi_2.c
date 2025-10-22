#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main (int argc, char *argv[]) {
    pid_t pid;
    int i;

    printf("Main: ");
    printf("PID=%d ; bash-shell PID = %d\n", getpid(),getppid());
    
    for (i = 0; i < 2; i++){
        pid = fork();   //creazione figlio
        if (pid < 0) {  
            // fork error
            fprintf(stderr, "Fork Failed \n");
            exit(1);
        }
        else
            if (pid == 0){
                // child process
                printf("CHILD: PID returned %d; PID = %d; My parent PID %d\n", pid, getpid(), getppid());
            }
            else {
                //parent process
                wait(NULL);
                printf("PARENT: PID returned %d; PID = %d; My parent PID %d\n", pid, getpid(), getppid());
            } 
    }
    return(EXIT_SUCCESS);
}