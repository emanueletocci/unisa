#!/bin/bash
#  Creare uno script che abbia la sintassi
#  ./line_counter.sh nome_directory direzione
#  Lo script deve elencare i file contenuti nella directory con relativo numero
#  di linee, ordinati in senso crescente (rispetto al numero di linee) se
#  direzione è up e in senso decrescente se direzione è down
#  Esempio: ./line_counter.sh mia_dir up

#  potrebbe produrre come output:
#  27 mia_dir/prova.c
#  33 mia_dir/pippo.txt
#  142 mia_dir/programma.c

#  NOTA: lo script deve controllare:
#  che il primo argomento sia effettivamente una directory
#  che il secondo argomento sia la stringa up o down
#  Suggerimento: si usi il comando wc per ottenere i nomi dei file preceduti dal
#  numero di linea e il comando sort per l’ordinamento
#  wc -l file1 file2 ... stampa in output i nomi dei file preceduti dal num. di linee
#  sort -n legge le linee del suo standard input, le ordina in base al primo campo
#  (interpretato come valore numerico) e le stampa in output in ordine crescente
#  sort -nr fa la stessa cosa, ma in ordine decrescente

#arg(s) check
if (( $# != 2 )); then
    echo "Wrong arg number!"
    exit 1
fi

#arg1 (path) check
if [[ ! -d $1 ]]; then
    echo "$1 is not a directory!"
    exit 1
fi

#arg2 check
if [[ $2 == "up" ]]; then 
    echo "ascending sort listing"
    wc -l $1/* |  sort -n
elif [[ $2 == "down" ]]; then
    echo "descending sort listing"
    wc -l $1/* | sort -nr
else 
    echo "arg2 error! It must be up or down!"
    exit 1
fi
exit 0