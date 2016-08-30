#!/bin/bash
buildInChecks="--bounds-check --div-by-zero-check --pointer-check --memory-leak-check --signed-overflow-check --unsigned-overflow-check --float-overflow-check"

filename="$1"

prefix="s2n-verification-result/module-based/"
dir="$prefix"
mkdir $dir;
shift

if [ "$1" != "cbmc" ] 
then
    echo "ERROR: missing output file name";
    exit 1
fi

start_ns=$(gdate +%s%N);
result=$(gtimeout 5h $@ $buildInChecks);
end_ns=$(gdate +%s%N);
elapsed_ms=$(((end_ns - start_ns) / 1000000));
echo $elapsed_ms;

echo "> gtimeout 1h $@ $buildInChecks" > $dir/$filename.txt;
echo "$result" >> $dir/$filename.txt;
echo "Time taken: $elapsed_ms" >> $dir/$filename.txt

