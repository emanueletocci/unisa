/******************************************************************************

Scrivere un programma che crea un’area di memoria condivisa in grado di contenere un 
array di 100 float. Il programma deve creare 1 processo figlio, il primo dei quali 
scrive nei primi 50 elementi dell’array i valori 1.0, 1.0/2, 1.0/3, ..., 1.0/50 e 
il secondo scrive nei secondi 50 elementi dell’array i valori 1.0/51, 1.0/52, ..., 1.0/100. 
Il processo padre attende la terminazione dei due processi figli, dopodiché calcola e stampa 
la somma di tutti i 100 elementi dell’array.

*******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#define SIZE 100


void child_process(int segment_id){
    float *array = shmat (segment_id , NULL, 0);
    
    for (int i=0 ; i < SIZE ; i++)
        *(array + i) = 1.0/(i+1);
    shmdt(array);
}

int main() {
    
    printf("MAIN: PID = %d ; shell PID = %d \n", getpid(),getppid());
    printf("\n");

    int segment_id = shmget(IPC_PRIVATE, SIZE * sizeof(float), S_IRUSR | S_IWUSR);

    if (segment_id < 0) {
        printf("Errore in shmget\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        printf("Errore nella fork\n");
        /* Importante! Dealloco l'area */
        shmctl(segment_id, IPC_RMID, NULL);
        return 1;

    } else if (pid == 0) {
        /* Processo figlio */
        printf("CHILD: PID returned = %d \t PID = %d \t My parent PID = %d \n\n", pid, getpid(), getppid());
        child_process(segment_id);
        return 0;

    } else {
        /* Processo padre */
        /* Aspetto che il figlio sia terminato prima di accedere alla memoria
         * (sincronizzazione)! */
        printf("PARENT: PID returned = %d \t PID = %d \t My parent PID = %d \n\n", pid, getpid(), getppid());

        wait(NULL);

        float *array = shmat(segment_id, NULL, 0);
        float somma = 0;
        puts("Calcolo la somma degli elementi dell'array:\t");
        for (int i = 0; i < SIZE ; i++)
            somma += array[i];
    
        printf("SOMMA = %f \n", somma);
        shmdt(array);

        /* Importante! Dealloco l'area */
        shmctl(segment_id, IPC_RMID, NULL);
        return 0;
    }
}