#!/bin/bash

#Creare uno script che abbia la sintassi
#./safe_remove.sh pathname
#๏ Lo script deve gli eliminare i file specificati nella riga comando salvandoli
#preventivamente in una directory di nome “recycle” (se non esiste la deve
#creare, poi salvare i file nella directory)

if [[ $# != 1 ]]; then
    echo "E' accettato solo un argomento"
    exit 1
fi
if [[ ! -d ~/Desktop/recycle ]]; then
    mkdir ~/Desktop/recycle
else
    echo "Cartella già esistente!"
fi
cp "$1" ~/Desktop/recycle/
rm "$1"