#!/bin/bash
#๏ Si scriva uno script che legga
#da tastiera il nome di un utente
#e visualizzi quanti login ha
#effettuato

#๏ Si usi il comando who per
#ottenere la lista degli utenti ed
#il comando grep <stringa>
#per cercare stringa in un
#testo e wc -l per contare le
#linee.

if [[ $# != 1 ]]; then
    echo "E' accettato solo un argomento"
    exit 1
fi
who | grep $1 | wc -l
echo "L'utente $1 ha effettuato $times login"
exit 0

