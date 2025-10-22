/*
Scrivere un programma C che realizzi una comunicazione bidirezionale tra il processo padre ed il processo figlio 
mediante la creazione di due pipe distinte "pipe1", "pipe2" .
Il programma dovrà creare le due pipe ed il processo figlio. Il processo padre, scriverà sulla pipel (pdf1) 
un messaggio immesso da tastiera, il processo figlio leggerà tale messaggio dalla pipe1 (pdf1), lo stamperà 
a video e scriverà la notifica di lettura sulla pipe2 (pdf2) che verrà poi letta dal padre e stampata a video. 
(Utilizzare la funzione fgets per leggere un messaggio con spazi inserito da tastiera)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define size 200

int main (int argc, char *argv[]){
    int fd_1[2],fd_2[2], notify;
    char buffer[size];

    if ((pipe(fd_1) || pipe(fd_2)< 0)){
        fprintf(stderr, "pipe cretion error!\n");
        exit(1);
    } 

    pid_t pid = fork();

    if(pid < 0){
        fprintf(stderr, "pipe cretion error!\n");
        exit(1);       
    } else if (pid == 0){
        //child process
        close(fd_1[1]);
        close(fd_2[0]);
        int received_1 = (int) read (fd_1[0], buffer, size);
        if (received_1 < 0){
            fprintf(stderr, "pipe reading error!\n");
            notify = -1;
            exit(1);   
        } else if (received_1 < size){
            printf("CHILD: partial message!\n");
        }
        printf("CHILD: String is: %s\n", buffer);
        notify = 0;
        close(fd_1[0]);

        int sent_2 = (int) write (fd_2[1], &notify, sizeof(int));
        close(fd_2[1]);

    } else {
        close(fd_1[0]);
        close(fd_2[1]);
        printf("FATHER: Enter message... \t");
        fgets(buffer, size, stdin); //lettura stringa con spazi
        printf("\n");
        int sent_1 = (int) write(fd_1[1], buffer, size);
        if (sent_1 < 0){
            fprintf(stderr, "pipe writing error!\n");
            exit(1);   
        }

        int received_2 = (int) read(fd_2[0], &notify, sizeof(int));
        if (received_2 < 0){
            fprintf(stderr, "pipe reading error!\n");
            exit(1);   
        }   
        if (notify == 0)
            printf("FATHER: message delivered correctly\n");
        else if (notify == 1)
            printf("FATHER: partial message delivered\n");
    }
}