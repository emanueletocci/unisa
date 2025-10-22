#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int global_val;

int main (int argc, char *argv[]) {
    pid_t pid;
    global_val = 0;
    int* local_val = (int*)malloc(sizeof(int));
    *local_val = 1;

    pid = fork();   //creazione figlio

    if (pid < 0) {  
        // fork error
        fprintf(stderr, "Fork Failed \n");
        exit(1);
    }
    if (pid == 0){
         // child process
         printf("Im the child with PID = %d\n", pid);
         global_val = 100;
        (*local_val)++;
        printf("CHILD: global_val = %d; \t local_val = %d\n", global_val, *local_val);
        exit(0);
    }
    else {
        printf("Im the Parent with PID = %d\n", pid);
        wait(NULL);
        printf("PARENT: global_val = %d; \t local_val = %d\n", global_val, *local_val);
        free(local_val);
        exit(0);
    }  
    return(EXIT_SUCCESS);
}