#!/bin/bash
filename="public_functions.txt"
result=""
for f in $(find ./s2n -type f -name "*.h" -not -path '*bin*' -not -path '*tests*' -not -path '*libcrypto-build*' -not -path '*libcrypto-root*'); do
	result="$result$(grep -Eo '\w+\(.+\);$' $f)";
done

echo $result | tr ";" "\n" | sort | uniq | while read -r line; do
        echo "- [ ] ${line%%(*}" >> $filename;
done
