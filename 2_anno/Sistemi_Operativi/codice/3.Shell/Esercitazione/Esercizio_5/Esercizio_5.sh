#!/bin/bash
# ./Esercizio_5.sh < in.txt >> out.txt 
#
#  Si scriva uno script che legga
#  da un file con nome in.txt
#  tutte le linee di testo e per ogni
#  linea determini il numero della
#  linea letta e stampi su un file
#  con nome out.txt il numero
#  di linea e la linea letta

n=1
while read row; do  
    echo "Row $n: $row"
    n=$((n+1))
done
exit 0
