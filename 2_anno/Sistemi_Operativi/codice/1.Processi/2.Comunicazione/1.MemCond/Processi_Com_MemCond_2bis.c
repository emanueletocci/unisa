#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#define SIZE 100


void child_process(int segment_id, int index){
    float *array = shmat (segment_id , NULL, 0);
    int first = index * SIZE/2;
    int end = first + SIZE/2;

    for (int i = index ; i < end ; i++)
        *(array + i) = 1.0/(i+1);
    shmdt (array);
}

int main() {
    pid_t pid;
    int segment_id = shmget (IPC_PRIVATE , SIZE * sizeof(float), S_IRUSR | S_IWUSR);

    printf("MAIN: PID = %d ; shell PID = %d \n", getpid(),getppid());
    printf("\n");

    if (segment_id < 0){
        fprintf(stderr, "SHMGET Error\n");
        return 1;
    }
    for (int i = 0; i < 2; i++){
        pid = fork();
        if (pid < 0){
            fprintf(stderr, "Fork Error\n");
            if(i == 1)
                wait(NULL); /*Aspetto la terminazione del 2 figlio prima di deallocare*/
            shmctl(segment_id, IPC_RMID, NULL);
            return 1;
        }

        else if (pid == 0){
            // first child
            printf("CHILD: PID returned = %d \t PID = %d \t My parent PID = %d \n\n", pid, getpid(), getppid());
            child_process(segment_id, i);
            return 0;
        }
    }

    for (int i = 0; i < 2 ; i++)
        wait(NULL);

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




