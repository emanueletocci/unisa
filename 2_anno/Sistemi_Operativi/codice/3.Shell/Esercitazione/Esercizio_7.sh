#!/bin/bash
#  Si scriva uno script shell che controlla
#  se il file passato come unico
#  argomento esiste.

#  Se il file esiste, lo script stampa a video
#  il messaggio «Il file <path/file> esiste!»

#  Successivamente, se il file esiste, lo
#  script controlla se l’utente ha i
#  permessi di esecuzione su quel file; in
#  caso affermativo lo script stampa a
#  video il messaggio «Hai i permessi di
#  esecuzione», altrimenti «Non hai i
#  permessi di esecuzione».

if (($# != 1)); then
    echo "Wrong arg number!"
    exit 1;
fi
if [[ -f $1 ]]; then
    echo "File $1 exists!"
    if [[ -x $1 ]]; then
        echo "You have exec permission"
    else 
        echo "You do not have exec permission"
    fi
else 
    echo "File $1 exists!"
fi
exit 1