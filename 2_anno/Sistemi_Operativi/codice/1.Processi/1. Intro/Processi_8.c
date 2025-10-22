//command.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main (int argc, char *argv[]) {
    pid_t pid;
    char path[50] = "/bin/";

    printf("MAIN: PID = %d ; shell PID = %d \n", getpid(),getppid());
    printf("\n");
    
    if (argc > 1){
        for (int i = 1; i < argc ; i++)
            printf("Comando passato come argomento: %s \n", argv[i]);
    }
    else printf("Non sono stati inseriti argomenti da riga di comando\n");
    
    printf("Command path: %s \n\n", strcat(path , argv[1]));
    
    pid = fork();
            
    if (pid < 0){
        // fork error
        fprintf (stderr, "Fork Error!\n");
        exit(1);
    }

    else if (pid == 0){
        // child process
        printf("CHILD: PID returned = %d \t PID = %d \t My parent PID = %d \n", pid, getpid(), getppid());
        printf("Eseguo il comando %s", argv[1]);
        execlp(path, argv[1], NULL);
        exit(0);
    }

    else{
        // parent process
        wait(NULL);
        printf("PARENT: PID returned = %d \t PID = %d \t My parent PID = %d \n\n", pid, getpid(), getppid());
        puts("Comando eseguito!");
    }
}