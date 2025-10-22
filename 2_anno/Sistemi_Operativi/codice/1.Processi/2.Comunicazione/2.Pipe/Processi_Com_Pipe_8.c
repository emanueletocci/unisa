/*Scrivere un programma in linguaggio C chiamato time.c che determina la quantitá di tempo neces-
saria ad eseguire un comando da linea di comando. Il programma deve predenre in ingresso da linea
comando il comando da eseguire:
./time <command>
e deve stampare a video il tempo trascorso (in micro secondi) per l’esecuzione del comando passato
come argomento.
Scrivere una soluzione basata su pipe.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <string.h>

#define DIM 20

int main (int argc, char* argv[]){
    int fd[2];
    pid_t pid;

    struct timeval start;
    struct timeval end;

    if (argc < 2){
        puts("No arguments!");
        exit(1);
    } else 
        printf("Command: %s\n", argv[1]);
    
    if(pipe(fd) != 0){
        fprintf(stderr, "Pipe Error!");
        exit(1);
    }
    pid = fork();

    if (pid < 0){
        fprintf(stderr, "Fork Error!");
        exit(1);
    } else if (pid == 0){
        close(fd[0]);       //chiusura pipe in lettura
        gettimeofday(&start, NULL);
        int sent = (int) write(fd[1], &start, sizeof(struct timeval));
        if (sent < 0){
            fprintf(stderr, "Sending Error!");
            exit(1);
        }
        close(fd[1]);
        execlp(argv[1], argv[1], NULL);
    } else {
        close(fd[1]);       //chiusura pipe in scrittura
        int received = (int) read(fd[0], &start, sizeof(struct timeval));
        gettimeofday(&end, NULL);
        if (received < 0){
            fprintf(stderr, "Receiving Error!");
            exit(1);
        } else if (received < sizeof(struct timeval)){
            puts("Partial Message!");
        } else printf("Reading from pipe: \t %s \n", argv[1]);
        close(fd[0]);
        unsigned long time = ((end.tv_sec * 1000000) + end.tv_usec) - ((start.tv_sec * 1000000) + start.tv_usec);
        printf("Time elapsed: %f ms\n", time);
    }
    exit(0);
}
