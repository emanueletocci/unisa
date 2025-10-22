#!/bin/bash

#  Si supponga di avere in una directory i risultati di varie
#  computazioni salvati in un numero di files situati in varie
#  sottodirectory. Il formato dei file è identico per tutti. Ad es.:

#  F1 score 67
#  Accuracy score 61

# Scrivere uno script bash che effettui una ricerca di uno specifico score (ad es. F1)
# in ciascuno dei file salvando i singoli valori in file di uscita e ne calcoli la
# media, mostrandola a video. Lo script deve ricevere in ingresso il path della
# directory principale dove risiedono i file, il path della directory di uscita (se non
# esiste la crea), il nome del file di uscita e lo score su cui calcolare la media.

# Si usi il comando

# awk '{print $i}’
# che consente di stampare l’i-ma stringa di ogni riga di un file.

# ./Esercizio_11.sh test_file outdir out.txt Ghiaccio
rm -Rf test_file
rm -Rf outdir

if [[ ! -e test_file ]];then
    mkdir test_file
fi

if [[ ! -e outdir ]];then
    mkdir outdir
fi

if [[ ! -e test_file/others ]];then
    mkdir test_file/others
fi

for i in {0..5};do
    touch test_file/"Aria score $((i+13))"
done

for i in {10..17};do
    touch test_file/"Fuoco score $((i+3))"
done

for i in {25..30};do
    touch test_file/"Ghiaccio score $((i+3))"
done

for i in $(seq 5 -1 0);do
    touch test_file/others/"Terra score $((i+3))"
done

for i in $(seq 11 +3 21);do
    touch test_file/others/"Fuoco score $i"
done

echo "Su quale score vuoi calcolare la media?"
read score
echo "Ricerco lo score $score"

find -name ${score}* | awk '{print $3}' > outdir/out.txt
somma=0
count=0
for row in $(cat outdir/out.txt); do 
    somma=$((somma+row))
    count=$((count+1))
done
echo "Somma = $somma; count = $count"
media=$(echo "$somma/$count" | bc -l)
echo "$media"