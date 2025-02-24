#!bin/bash

testsQty=5
maxTabSize=100
errLog="err.txt"
log="results.txt"

echo "-----------------------" >> "$log"

for ((i = 1; i <= testsQty; i++)); do
    #size=$((RANDOM % maxTabSize + 1))
    size=5000

    array=$(shuf -i 1-200000 -n "$size" | tr '\n' ' ')

    ./merger $array >> "$log" 2>> "$errLog"

	exitCode=$?

    echo >> "$log"


    if [[ $exitCode -eq 10 ]]; then
        echo "List unsorted, $array" >> "$errLog"
    fi
	if [[ $exitCode -eq 11 ]]; then
        echo "Vector unsorted, $array" >> "$errLog"
    fi

done

