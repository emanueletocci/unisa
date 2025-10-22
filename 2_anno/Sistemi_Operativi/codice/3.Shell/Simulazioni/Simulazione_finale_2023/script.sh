#  Progettare uno script che prenda 3 parametri di cui il primo è il pathname di una directory, il
#  secondo è una stringa e il terzo è il pathname di una directory.
#  Lo script deve cercare i files presenti nella directory specificata nel primo parametro che
#  contengono nel loro nome la stringa passata come secondo parametro e spostarli nella directory
#  specificata nel terzo parametro. Inoltre, lo script deve stampare a video il numero totale di file
#  spostati.

#  Si controlli che sulla linea di comando ci siano i 3 parametri e che il primo sia una directory
#  stampando un messaggio di errore e terminando l'esecuzione in caso contrario. Se il terzo
#  parametro non corrisponde al nome di un file o di una directory (quindi, non "esiste"), lo script
#  deve creare una directory con quel pathname; altrimenti, se il terzo parametro esiste ma non e'
#  una directory, lo script deve stampare un messaggio di errore e terminare l'esecuzione.

#  NOTA BENE: lo script deve esaminare i files contenuti direttamente nella directory specificata nel
#  primo parametro, NON nelle sue sottodirectory.

rm -Rf folder
rm -Rf bak 

mkdir folder
cat > folder/first.txt <<EOF
Text Text Text Text Text
Text Text Text Text Text
Text Text Text Text Text
Text Text Text Text Text
EOF

cat > folder/second.dat <<EOF
Text Text Text Text Text
Text Text Text Text Text
Text Text Text Text Text
Text Text Text Text Text
EOF

cat > folder/third.txt <<EOF
Text Text Text Text Text
Text Text Text Text Text
EOF

mkdir folder/sub
cat > folder/sub/irrelevant.txt <<EOF
Text Text Text Text Text
Text Text Text Text Text
EOF

if (( $# != 3 )); then
    echo "Wrong usage. Syntax: ./script.sh <dir> <string> <dir>."
    exit 1
fi

maindir=$1
string=$2
outdir=$3

if [[ ! -d $maindir ]];then
    echo "arg1 ($maindir) must be a directory!"
    exit 1
fi

if [[ -e $outdir ]]; then
    if [[ ! -d $outdir ]]; then
        echo "error, $outdir is not a directory!"
        exit 1
    fi
else 
    echo "$outdir folder does not exist! Executing mkdir..."
    mkdir $outdir
fi

mv $(find $maindir -maxdepth 1 -type f -name "*$string*") $outdir
echo "Moved $(ls $outdir | wc -l) files from $maindir to $outdir"
