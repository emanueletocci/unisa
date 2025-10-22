#!/bin/bash
#Si scriva uno script che
#visualizzi il messaggio “Enter
#password: “, legga una stringa
#e la confronti con la stringa
#“secret” sino all’introduzione
#della stringa corretta

echo "Enter Password"
read -s pass
count=1
while [[ "$pass" != "secret"  ]] && [[ $count -lt 3 ]]; do
    echo "Le stringhe non coincidono, riprova. Tentativo $count fallito!"
    read -s pass
    count=$((count+1))
done 
    echo "Hai finito i tentativi"
exit 0
