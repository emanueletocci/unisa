/*****************************************************************
Il candidato completi il programma fornito, implementando
il main. Il programma ottiene un numero intero N dai parametri
della linea di comando, e crea un processo figlio che, utilizzando
la funzione fornita 'genera_array', genera un array contenente i
primi N numeri di Fibonacci. Questo array deve essere 
passato al processo padre utilizzando la memoria condivisa.
Il processo padre attende la terminazione del processo figlio,
e stampa a video l'array ricevuto.

Esempio: Specificando sulla linea di comando il parametro 10
l'output del programma sara':

Array ricevuto: 1 1 2 3 5 8 13 21 34 55

The candidate should complete the program provided, implementing
the main. The program obtains an integer number N
from the command line parameters, and creates a child process which,
using the provided function 'genera_array', generates an array
containing the first N Fibonacci numbers. This array must be
passed to the parent process using shared memory.
The parent process waits for the termination of the child process,
and prints the received array on the screen.

Example: If you specify the parameter 10 on the command line
the output of the program will be:

Received array: 1 1 2 3 5 8 13 21 34 55

******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define size 100

// Calcola un numero di Fibonacci (n parte da 0)
int fibo(int n) {
    if (n<=1)
        return 1;
    else
        return fibo(n-1)+fibo(n-2);
}

// Genera i primi k numeri di Fibonacci e li inserisce in un array
void genera_array(int array[], int k) {
    int i;
    for(i=0; i<k; i++)
        array[i]=fibo(i);
}

int main(int argc, char *argv[]) {
    int segment_id, n;
    
    if(argc != 2){
        printf("Numero errato di argomenti... il programma richiede 1 argoment0 da cli\n");
        exit(1);
    }  
    
    n = atoi(argv[1]);
    
    segment_id = shmget (IPC_PRIVATE, n * sizeof(int), S_IRUSR | S_IWUSR);
    
    if (segment_id == -1){
        fprintf(stderr, "shmget error!\n");
        exit(1);
    }
    
    pid_t pid = fork();
    
    if (pid < 0){
        fprintf(stderr, "fork error!\n");
        if(shmctl(segment_id, IPC_RMID, NULL) == -1){
            fprintf(stderr, "shared memory clear error!\n");
            exit(1);
        }
        exit(1);
        
    } else if (pid == 0){
        //child process
        
        int *ptr = (int *) shmat(segment_id, NULL, 0);
        if (*ptr < 0){
            fprintf(stderr, "attach error!\n");
            exit(1);
        }
        genera_array(ptr, n);
        if (shmdt(ptr) == -1){
            fprintf(stderr, "detach error!\n");
            exit(1);
        }
        
    } else {
        int *ptr = (int *) shmat(segment_id, NULL, 0);
        if (*ptr < 0){
            fprintf(stderr, "attach error!\n");
            exit(1);
        }        
        wait(NULL);
        printf("Stampo i primi %d numeri di fibonacci:\n", n);
        for (int i = 0 ; i<n ; i++){
            printf("%d\t", ptr[i]);
        }
        if (shmdt(ptr) == -1){
            fprintf(stderr, "detach error!\n");
            exit(1);
        }

    }
    return 0;
}
