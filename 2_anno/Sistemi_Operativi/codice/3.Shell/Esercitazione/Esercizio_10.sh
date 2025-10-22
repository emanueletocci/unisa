#!/bin/bash

#  Si scriva uno script bash che prende una directory come parametro.
#  Lo script deve cambiare il nome di tutti i file regolari (ovvero, non sottodirectory) che
#  contengono nel loro nome caratteri maiuscoli rendendoli minuscoli.

#  Si controlli che sulla linea di comando ci sia uno ed un solo parametro, stampando un
#  messaggio di errore in caso contrario.

#  NOTA: è possibile utilizzare il comando tr
#  A-Z a-z per trasformare i caratteri da minuscoli a maiuscoli di una stringa ed il
#  comando *[[:upper:]]* per il confronto con il nome del file e verificare se il nome del
#  file confine almeno un carattere maiuscolo.

if (($# != 1)); then
    echo "Wrong arg(s) number!"
    exit 1
fi

if [[ ! -d $1 ]]; then
    echo "$1 is not a directory or does not exist!"
    exit 1
fi

for file in "$1/*"; do
    if [[ -f $file ]]; then
        if [[ $file == *[[:upper:]]* ]]; then
            newname=$(echo $file | tr A-Z a-z)
            echo "$file to $newname"
            mv $file $newname
        fi
    fi
done
exit 0