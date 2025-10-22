#!/bin/bash
#  Si scriva uno script bash che prende una stringa come parametro.
#  Lo script deve stampare il nome di tutti i file regolari (ovvero, non sottodirectory)
#  che contengono nel loro nome la stringa passata come parametro e il numero
#  totale di file trovati.

#  Si controlli che sulla linea di comando ci sia uno ed un solo parametro, stampando
#  un messaggio di errore in caso contrario.
 
#  NOTA: e' possibile utilizzare il comando
#  find con l’opzione - name “*$string*" per trovare tutti i file nel
#  cui nome è contenuta la stringa string.

if (( $# != 1 )); then
    echo "Wrong arg(s) number!"
    exit 1
fi
counter=0
for file in $(find . -name "*$1*" ); do
    if [[ -f $file ]]; then
        counter=$((counter+1))
        echo "$file"
    fi 
done
echo "$counter file(s) found"
exit 0