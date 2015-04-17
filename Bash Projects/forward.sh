#!/bin/bash

reverse() {
    for (( idx=0; idx<i; idx++)); do
	echo "${lst[idx]}"
    done
}

main() {
    lst=($1*)
    i=${#lst[@]}

    reverse $i
}

main $1