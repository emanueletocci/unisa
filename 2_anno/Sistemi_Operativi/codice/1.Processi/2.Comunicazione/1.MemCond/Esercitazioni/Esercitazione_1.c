/*
Scrivere un programma in linguaggio C chiamato reverse.c che inverte una stringa.
Il programma deve prendere in ingresso da linea comando la stringa da invertire:
./reverse <string>
e deve stampare a video la stringa invertita. Si usi la struttura dati seguente per la
comunicazione:
typedef struct {
char str[SIZE];
} shared_data;
Scrivere una soluzione basata su shared memory, nella quale il processo figlio
effettua l’inversione ed il processo padre provvede alla stampa a video.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/stat.h>

#define SIZE 100

typedef struct{
    char str[SIZE];
} shared_data;

void reverse_str(char* str){
    int len = strlen(str);
    for (int i = 0; i < len/2; i++){
        char temp = str[i];
        str[i] = str[len - i -1];
        str[len - i - 1] = temp;
    }
}

int main (int argc, char* argv[]){
    char* string;
    if (argc != 2){
        printf("Numero errato di argomenti... il programma necessita un unico argomento da cli\n");
        exit(1);
    }
    string = argv[1];
    printf("String : %s\n", string);
    int segment_id = shmget(IPC_PRIVATE, sizeof(shared_data), S_IRUSR | S_IWUSR);
    if (segment_id < 0){
        fprintf(stderr, "shmget error!\n");
        exit(1);
    }
    
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork error!\n");
        shmctl(segment_id, IPC_RMID, NULL);
        exit(1);
    } else if (pid == 0){
        shared_data *ptr = (shared_data*) shmat(segment_id, NULL, 0);
        strcpy(ptr->str , string);
        reverse_str(ptr->str);
        shmdt(ptr);
    } else {
        shared_data *ptr = (shared_data*) shmat(segment_id, NULL, 0);
        wait(NULL);
        printf("Reversed: %s\n", ptr->str);
        shmdt(ptr);
    }
    shmctl(segment_id, IPC_RMID, NULL);
    return 0;

}