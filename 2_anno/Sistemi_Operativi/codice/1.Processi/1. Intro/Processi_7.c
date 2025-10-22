//print_messages.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main (int argc, char *argv[]) {
    pid_t pid;

    printf("MAIN: PID=%d ; shell PID = %d \n", getpid(),getppid());
    printf("\n");

    if (argc > 1){
        for (int i = 1; i < argc ; i++)
            printf("Stringa %d: %s \n", i, argv[i]);
    }
    
    else printf("Non sono stati inseriti argomenti da riga di comando\n");
    
    printf("\n");

    for (int i = 1; i < argc ; i++){
        pid = fork();
            
        if (pid < 0){
            // fork error
            fprintf (stderr, "Fork Error!\n");
            exit(1);
        }

        else if (pid == 0){
            // child process
            srand((unsigned int) getpid());
            sleep (rand() % 10);
            printf("CHILD: PID returned = %d \t PID = %d \t My parent PID = %d \t Message = %s \n", pid, getpid(), getppid(), argv[i]);
            exit(0);
        }

        else{
            // parent process
            wait(NULL);
            printf("PARENT: PID returned = %d \t PID = %d \t My parent PID = %d \n\n", pid, getpid(), getppid());
        }
    }
}