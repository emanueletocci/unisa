#!/bin/bash

#  ๏ Scrivere uno script bash in grado di
#  ๏ Ricevere due interi n1 e n2 sulla riga di
#    commando oppure di leggerli da
#    tastiera se non sono presenti sulla riga di commando
#    Visualizzare una matrice di n1 righe e
#    n2 colonne di valori interi crescenti a
#    partire dal valore 0

#    ๏ Esempio:
#    > ./myScript 3 4
#    0 1 2 3
#    4 5 6 7
#    8 9 10 11

if (($# != 2)); then
    echo "No arguments or wrong number... manual reading"
    echo "Enter first number"
    read n1
    echo "Enter second number"
    read n2
else
    echo "Entered numbers: $1, $2"
fi
count=0
echo "Matrix writing..."
for (( i=0; i<$1; i++ )) do
    for (( j=0; j<$2; j++)) do
        echo -n "$count "
        count=$((count+1))
    done
    echo 
done
exit 0