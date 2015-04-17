#!/bin/bash

reverse() {
    for (( i; i>=0; i--)); do
	echo "${lst[i]}"
    done
}

main () {
    lst=($1*)
    i=${#lst[@]}
    let i=(i-1)
    reverse $i
}

main $1