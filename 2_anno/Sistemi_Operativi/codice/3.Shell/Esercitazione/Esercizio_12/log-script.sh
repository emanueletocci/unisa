#!/bin/bash

#  Per semplificare le operazioni di archiviazione e di gestione dei file contenenti le
#  informazioni di log sul funzionamento di un determinato servizio, spesso si fa in modo di
#  conservare su file distinti i log relativi a giorni differenti. In tal modo ogni file conterrà
#  solo le informazioni relative ad un periodo di tempo, che è possibile archiviare o gestire
#  con maggiore facilità rispetto ad un unico file di log molto ingombrante.

#  Se l'applicazione “myapp” produce un file di log in “/tmp/mylog”, allora applicare
#  l'operazione di log rotation a quel file, significa spostare ogni volta il log “mylog” nel file
#  “mylog.0” e creare un nuovo file vuoto denominato “mylog”. Per mantenere in archivio i
#  file relativi alle ultime n turnazioni, prima di rinominare il log corrente si provvederà a
#  rinominare/spostare “mylog.n−1” in “mylog.n”, “mylog.n−2” in “mylog.n−1” e così via,
#  fino a spostare “mylog.0” in “mylog.1”.

#  Si scriva uno script che esegua le operazioni descritte, avendo cura di comprimere i file
#  di log archiviati (non quello corrente) in modo da risparmiare spazio sul filesystem.

rm -Rf tmp
mkdir tmp
cat > tmp/mylog <<EOF
"count=0"
EOF

echo "Quanti log si vogliono mantenere? Inserire un numero >0..."
read n
if ((n<0));then
    echo "error! Il numero inserito e' <0!"
    exit 1
fi
count=0
while true; do
    count=$((count+1))
    if [[ -e tmp/mylog ]]; then
        mv tmp/mylog tmp/mylog.0
        cat > tmp/mylog <<EOF
"count=$count"
EOF
    fi

    for j in $(seq $count -1 0); do
        if [[ -e tmp/mylog.$((j-1)) ]]; then
            gzip tmp/mylog.$((j-1))
            mv tmp/mylog.$((j-1)).gz tmp/mylog.$((j))

        fi
    done

    if [[ -e tmp/mylog.$((n+1)) ]]; then
        rm tmp/mylog.$((n+1))
    fi

    sleep 3
done
exit 0