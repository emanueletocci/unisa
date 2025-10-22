#!/bin/bash

num=10
while ((num > 0)); do
    echo ”Mancano $num secondi al lancio.”
    sleep 1
    num=$((num-1))
done
echo ”Accensione!”