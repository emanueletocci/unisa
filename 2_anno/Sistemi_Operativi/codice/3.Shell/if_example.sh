#!/bin/bash
if [[ -d $1 ]]; then
    echo "$1 è una directory"
elif [[ -f $1 ]]; then
    echo "$1 è un file"
else
    echo "$1 non esiste"
fi