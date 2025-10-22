te

if (( $# != 4 )); then
    echo "wrong arg(s) number"
    exit 1
fi

maindir=$1
outdir=$2
outfile=$3
score=$4

if [[ ! -d $outdir ]]; then
    echo "La directory $outdir non esiste! La creo..."
    mkdir $outdir 
else 
    echo "La directory $outdir esiste..."
fi
find -H -name "*$score*" | awk '{print $3}' > $outdir/$outfile
echo "Score scritti in "$outdir/$outfile"..."

somma=0
count=0
for row in $(cat $outdir/$outfile); do
    somma=$((somma+row))
    count=$((count+1))
done
echo "Sono presenti \"$count\" files in cui compare lo score \"$score\""
if (($count != 0)); then
    media=$(echo "$somma/$count" | bc -l)
    echo "Media = $media"
else 
    echo "Media = division by 0"
fi