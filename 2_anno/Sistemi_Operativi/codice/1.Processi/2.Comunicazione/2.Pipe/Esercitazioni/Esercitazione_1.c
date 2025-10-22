/* 
Scrivere un programma in linguaggio C chiamato reverse.c che inverte una stringa.
Il programma deve prendere in ingresso da linea comando la stringa da invertire:
./reverse <string>
e deve stampare a video la stringa invertita. Si usi la struttura dati seguente per la
comunicazione:

typedef struct {
char str[SIZE];
} shared_data;

Scrivere una soluzione basata su pipe, nella quale il processo figlio effettua
l’inversione ed il processo padre provvede alla stampa a video.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SIZE 100

typedef struct{
  char str[SIZE];
} shared_data;

void reverse_str (char *str){
  int len = strlen (str);
  for (int i = 0; i < len / 2; i++){
	  char temp = str[i];
	  str[i] = str[len - i - 1];
	  str[len - i - 1] = temp;
	}
}

int main (int argc, char *argv[]){
    int fd[2];
    shared_data buffer;
    
    if (argc != 2){
        printf("Numero errato di argomenti... il programma necessita un unico argomento da cli\n");
        exit(1);
    }
    strcpy(buffer.str, argv[1]);
    printf("String : %s\n", buffer.str);
    
    if (pipe(fd) < 0){
        fprintf (stderr, "pipe error!\n");
        exit(1);
    }
    
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "fork error!\n");
        exit(1);
    } else if (pid == 0){
        close(fd[0]);
        reverse_str(buffer.str);
        int sent = (int) write(fd[1], &buffer, sizeof(shared_data));
        if (sent < 0){
            fprintf(stderr, "writing error!\n");
            exit(1);
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int received = (int) read(fd[0], &buffer, sizeof(shared_data));
        if (received < 0){
            fprintf(stderr, "reading error!\n");
            exit(1);
        } else if (received < sizeof(shared_data))
            printf("messaggio parziale!\n");
        else 
            printf("reversed : %s\n", buffer.str);
        close(fd[0]);
    }
    return 0;
}
