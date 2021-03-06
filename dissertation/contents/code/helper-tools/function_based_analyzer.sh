#!/bin/bash
if [ ! -z "$1" ]; then 
        src="$1"
else 
        src="."
fi

timestamp=$(date +%Y%m%d%H%M%S)
dir=./s2n-analysis/$timestamp
mkdir $dir 
filename="$dir/results.csv"
regex="^(\w+ )+\*?\w+\(.*\)$"
buildInChecks=(--bounds-check --div-by-zero-check --pointer-check --memory-leak-check --signed-overflow-check --unsigned-overflow-check --float-overflow-check)
echo "filenName, functionName, --bounds-check, --div-by-zero-check, --pointer-check, --memory-leak-check, --signed-overflow-check, --unsigned-overflow-check, --float-overflow-check," >> $filename;
for f in $(find $src -name '*.c' -not -path '*bin*' -not -path '*test*');
do
        grep -E '^(\w+ )+\*?\w+\(.*\)$' $f | cut -d "(" -f 1 | tr -d "*" | while read -r line; do
        echo -n "$f," >> $filename;
        echo -n "${line##* }," >> $filename;
        for check in "${buildInChecks[@]}"
        do
                result=$(cbmc -I ./s2n -I ./s2n/api -I ./s2n/libcrypto-root/include $check $f --function ${line##* } --unwind 10 --no-assertions --no-assumptions)
                if echo $result | grep -q "VERIFICATION SUCCESSFUL"; then
                        echo -n "1," >> $filename;
                else
                        echo -n "0," >> $filename;
                        echo "$result" >> $dir/${line##* }$check.txt;
                fi
        done
        echo >> $filename;
done
#echo -e " " >> $filename;
done
