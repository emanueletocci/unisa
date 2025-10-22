#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/*Quanti processi vengono creati?*/

int main (int argc, char *argv[]) {
    
    pid_t pid;
    pid = fork();   //creazione figlio

    if (pid < 0) {  
        // fork error
        fprintf(stderr, "Fork Failed \n");
        exit(1);
    }
    if (pid == 0){
         // child process
        printf("CHILD1: PID returned = %d \t PID = %d \t My parent PID = %d \n", pid, getpid(), getppid());
        pid = fork(); //creo un altro figlio

        if (pid < 0){
            fprintf(stderr, "Child Fork Failed \n");
            exit(1);
        }

        if (pid == 0){
            printf("CHILD2: PID returned = %d \t PID = %d \t My parent PID = %d \n", pid, getpid(), getppid());
            exit(0);
        }

        else {
            printf("PARENT2: PID returned = %d \t PID = %d \t My parent PID = %d \n", pid, getpid(), getppid());
            exit(0);
        }

        exit(0);
    }

    else {
        printf("PARENT: PID returned = %d \t PID = %d \t My parent PID = %d \n", pid, getpid(), getppid());
        wait(NULL);
        exit(0);
    }  
    return(EXIT_SUCCESS);
}