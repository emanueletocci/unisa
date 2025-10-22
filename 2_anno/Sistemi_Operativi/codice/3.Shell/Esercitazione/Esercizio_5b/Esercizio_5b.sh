#!/bin/bash
# ./Esercizio_5b.sh in.txt out.txt 
#
#  Si scriva uno script che legga
#  da un file con nome in.txt
#  tutte le linee di testo e per ogni
#  linea determini il numero della
#  linea letta e stampi su un file
#  con nome out.txt il numero
#  di linea e la linea letta.

#  I NOMI DEI FILE DEVONO ESSERE PASSATI COME ARGOMENTO!!

if (($# != 2)); then
    echo "Sono necessari 2 argomenti!"
    exit 1
fi

n=1
while read row; do  
    echo "Row $n: $row"
    n=$((n+1))
done < $1 > $2
exit 0