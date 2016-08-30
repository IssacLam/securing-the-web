#!/bin/bash
filename="externalFunctions.txt"
result=""
for f in $(find ./s2n -name '*.c' -not -path '*bin*' -not -path '*test*' -not -path '*libcrypto-build*' -not -path '*libcrypto-root*');
do	
   	result="$result $(grep -Eo '(\w+)\(' $f | grep -v -E '(s2n|S2N|CPROVER|GUARD|if|while|switch|_check|defined)' | cut -d '(' -f 1)"
done
echo $result | tr " " "\n" | sort | uniq > $filename;
