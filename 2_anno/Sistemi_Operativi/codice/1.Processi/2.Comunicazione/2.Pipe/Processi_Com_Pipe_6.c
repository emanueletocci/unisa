/*Scrivere un programma che crea una pipe anonima, dopodiché crea un
processo figlio
Il processo figlio legge 5 numeri interi da tastiera e li invia al processo
padre tramite la pipe, mandando i primi 2, aspettando 1 secondo e quindi
mandando gli ultimi 3
Il processo padre legge dalla pipe i 5 numeri inviati dal
glio e li stampa
Nella lettura, gestire il fatto che il messaggio sia incompleto ripetendo
l’operazione di lettura nché il messaggio non viene completato,
oppure si veri ca un errore che impedisce il completamento

๏ Nota: in questo caso può essere d’aiuto de
 nire una funzione ausiliaria
che effettua la lettura dalla pipe, gestendo il completamento del
messaggio. Ad esempio: leggi_messaggio(int fd, void *msg, int size)
๏ Nota bene: anche se il messaggio in questo caso è formato da interi, dal
punto di vista della pipe il messaggio è una sequenza di byte; la funzione
di lettura deve tenerne conto per gestire correttamente il completamento
del messaggio
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define DIM 5

void pipe_writing (int fd[], int vet[], int size){
    for (unsigned int i = 0 ; i < DIM; i++){
        if (i == 2)
            sleep(1);
        printf("Writing : %d\n", vet[i]);
        int sent = (int)write(fd[1], &vet[i], sizeof(int)); 
        if (sent != sizeof(int)) {
            fprintf(stderr, "Sending error!\n");
            exit(1);
        }
    }
}

void pipe_reading (int fd[], int vet[], int size){
    for (unsigned int i = 0 ; i < DIM ; i++){
        int received = (int)read(fd[0], &vet[i], sizeof(int));
        if (received < 0) {
            fprintf(stderr, "Receiving error!\n");
            exit(1);
        } else if (received < sizeof(int)) 
            puts("Message Incomplete");
        printf("Reading : %d \n", vet[i] );         
    }
}

int main() {
    int fd[2], vet[DIM];

    if (pipe(fd) < 0) {
        fprintf(stderr, "Pipe creation error");
        exit(1);
    }

    pid_t pid = fork();

    if (pid<0) {
        fprintf(stderr, "fork error");
        exit (1);

    } else if (pid == 0) {
        close(fd[0]); // Close read pipe
        puts("Inserire 5 numeri:");

        for (unsigned int i = 0 ; i < DIM; i++){
            printf("Inserire numero %d: ", i);
            scanf("%d", &vet[i]);
        }

        pipe_writing(fd, vet, sizeof(vet));

        close(fd[1]);
        exit (0);
    } 
    else {
        // Father process
        close(fd[1]); // Close write pipe
        pipe_reading(fd, vet, sizeof(vet));
        close(fd[0]);
        exit (0);
    }
}


