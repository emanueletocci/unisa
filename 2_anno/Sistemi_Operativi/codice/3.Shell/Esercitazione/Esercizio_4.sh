#!/bin/bash
#Si scriva uno script che
#visualizzi il messaggio “Enter
#password: “, legga una stringa
#e la confronti con la stringa
#“secret” sino all’introduzione
#della stringa corretta

echo "Enter Password"
read -s pass
while [[ "$pass" != "secret" ]]; do
    echo "Le stringhe non coincidono, riprova"
    read -s pass
done 
exit 0
