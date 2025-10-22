#!/bin/bash
#Si scriva uno script di shell che
#a seguito di due messaggi
#legga da tastiera due valori
#interi e ne visualizzi la somma e
#il prodotto
#๏ Si faccia uso del comando
#read <var> per la lettura deivalori

echo "Reading var1"
read var1
echo "Reading var2"
read var2
sum=$((var1+var2))
echo "Sum = $((sum))"
prod=$((var1*var2))
echo "Prod = $((prod))"
exit 0