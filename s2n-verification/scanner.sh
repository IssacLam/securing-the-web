#!/bin/bash
filename="functions.txt"
regex="^(\w+ )+\*?\w+\(.*\)$"
for f in $(find ./s2n -name '*.c' -not -path '*bin*' -not -path '*test*');
do
        grep -E '^(\w+ )+\*?\w+\(.*\)' $f | cut -d "(" -f 1 | tr -d "*" | while read -r line; do
        echo -n "- [] " >> $filename;
        echo -n "$f : " >> $filename;
        echo "${line##* }" >> $filename;
done
done
