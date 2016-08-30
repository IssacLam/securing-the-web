#!/bin/bash
filename="all_functions.txt"
result=""
for f in $(find ./s2n -name '*.c' -not -path '*bin*' -not -path '*tests*' -not -path '*libcrypto-build*' -not -path '*libcrypto-root'); 
do
       result="$result$(grep -Eo '^(\w+ )+\*?\w+\(.*\)' $f | cut -d '(' -f 1 | tr '\n' ';')"; 
done

echo $result | tr -d '*' | tr ';' '\n' | sort | uniq | while read -r line; do
	 echo "- [ ] ${line##* }" >> $filename;
done