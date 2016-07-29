#!/bin/bash
filename="./opensslFunctions.txt"
regex="^(\w+ )+\*?\w+\(.*\)$"
src="./s2n-harness/unit"
result=""
for f in $(find $src -name '*.c');
do
	echo $f >> $filename;
	result+=$(cbmc -I ./s2n -I ./s2n/api -I ./s2n/libcrypto-build/openssl -I ./s2n/libcrypto-build/openssl/crypto -I ./s2n/libcrypto-build/openssl/crypto/engine -I ./s2n/libcrypto-build/openssl/include -I ./s2n/tests $f --unwind 1 2>&1 >/dev/null | grep -E '\*{4} WARNING:' | cut -d ' ' -f 7)
	echo $result | tr " " "\n" | sort | uniq >> $filename;
	echo >> $filename;
done 
