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

echo -n "inserire username: "
read username
times=0
times=$(who | grep $username | wc -l)
echo "L'utente $user ha effettuato $times login"
exit 0

