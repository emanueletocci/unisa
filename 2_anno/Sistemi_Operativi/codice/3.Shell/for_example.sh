#!/bin/bash
num=0
for nome in $1/*; do
        if [[ -d $nome ]]; then
            num=$((num+1))
        fi
done
echo ”Ci sono $num sottodirectory in $1”