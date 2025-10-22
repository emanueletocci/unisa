/*
Si modifichi il programma dell’esercizio 1 controllando se la stringa è
palindroma confrontando la stringa originale e quella invertita.
๏ Scrivere una soluzione basta su pipe nella quale il processo figlio crea un
ulteriore processo per il confronto delle stringhe originale e invertita.
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
int is_palindrome (char* str1, char* str2){
    if (strcmp(str1, str2) == 0)
        return 1;
    else
        return 0;
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
        pid_t pid2 = fork();
        if (pid2 < 0){
            fprintf(stderr, "fork error!\n");
            exit(1); 
        } else if (pid2 == 0){
            if (is_palindrome(buffer.str, argv[1]))
                printf("stringa palindroma\n");
            else    
                printf("stringa NON palindroma\n");
        } else {
            wait(NULL);
        }
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
