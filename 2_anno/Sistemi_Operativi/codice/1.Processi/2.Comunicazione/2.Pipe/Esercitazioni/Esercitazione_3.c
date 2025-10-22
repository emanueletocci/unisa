/*****************************************************************
Il candidato completi il programma fornito, implementando
il main.
Il programma crea un processo figlio; il processo figlio legge
da tastiera un numero intero N >= 0, e trasmette al processo padre
mediante una pipe i valori N, N-1, N-2, N-3, ..., 0 (incluso).
Il processo padre legge dalla pipe i valori trasmessi dal processo figlio
e li stampa, finche' non riceve il valore 0; dopodiche' il processo
padre attende la terminazione del processo figlio e termina.

Esempio:
Sono il processo figlio. Inserisci un numero >=0: 4
Sono il processo padre. Ho ricevuto: 4
Sono il processo padre. Ho ricevuto: 3
Sono il processo padre. Ho ricevuto: 2
Sono il processo padre. Ho ricevuto: 1
Sono il processo padre. Ho ricevuto: 0
Sono il processo padre. Il figlio ha terminato.

Per testare il programma cliccare sul seguente link:

https://onlinegdb.com/_ArIC2MPu

Una volta collegati, premere il pulsante FORK THIS di fianco al
pulsante RUN in alto a sinistra. Inserire nella finestra principale
il codice sorgente completo, inserire i parametri da passare sulla
linea comando nella casella CommandLine Arguments e cliccare sul
pulsante RUN per visualizzare il risultato dell'esecuzione.
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int fd[2], n;
    if (pipe(fd) < 0){
        fprintf(stderr, "pipe error\n");
        exit(1);
    }
    pid_t pid = fork();

    if (pid < 0){
        fprintf(stderr, "fork error\n");
        exit(1);
    } else if (pid == 0){
        // child process
        close(fd[0]);
        do{
            printf("Sono il processo figlio, inserire un numero >= 0\n");
            scanf("%d",&n);
        } while(n < 0);
        do {
            int sent = write (fd[1], &n, sizeof(n));
            if (sent < 0){
                fprintf(stderr, "sending error!\n");
                exit(1);
            }
            n -- ;
        } while (n >= 0);
        close(fd[1]);
        return 0;
    } else {
        // parent process
        close(fd[1]);
        do {
            int received = read(fd[0], &n, sizeof(n));
            if (received < 0){
                fprintf(stderr, "reading error!\n");
                exit(1);
            } else if (received < sizeof(n))
                printf("Partial Message!\n");
            else
                printf("Sono il processo padre. Ho ricevuto: %d\n", n);
        } while (n > 0);
        close(fd[1]);
        return 0;
    }
     return EXIT_SUCCESS;
}

