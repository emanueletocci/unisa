/*Esercizio 4: Pipe Unix
๏ Scrivere un programma che crea una pipe anonima, dopodiché crea un
processo figlio
๏ Il processo figlio legge una stringa da riga comando e la invia al processo
padre tramite la pipe
๏ Il processo padre legge dalla pipe la stringa inviata dal figlio e la stampa.
๏ Nella lettura dalla pipe, gestire il fatto che il messaggio sia incompleto
segnalandolo come situazione di errore*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char* argv[]){
    int fd[2];
    pid_t pid;

    if (pipe(fd) < 0 ){
        fprintf(stderr, "Pipe Error!");
        exit(1);
    }

    pid = fork();

    if (pid < 0){
        fprintf(stderr, "Fork Error!");
        exit(1);
    }
    else if (pid == 0){
        close(fd[0]); 
        if (argc <= 1){
            puts("No arguments");
        } else if (argc > 2)
            puts ("Too much arguments. I'll use the first one");
        int sent = (int)write(fd[1], &argv[1], sizeof(char) * strlen(argv[1]) + 1);
        if (sent < strlen(argv[1])){
            fprintf(stderr, "Send Error!");
            exit(1);            
        }
        close(fd[1]);
        exit(0);

    } else {
        close(fd[1]);
        int received = (int)read(fd[0], &argv[1], sizeof(char)*strlen(argv[1]) + 1);

        if (received < 0){
            fprintf(stderr, "Reading Error!");
            exit(1);
        } else if (received < strlen(argv[1]))
            puts("Partial Message!");
        else {
            printf("Reading: \t %s\n ", argv[1]);
        }
        close(fd[1]);
        exit(0);
    }

}
