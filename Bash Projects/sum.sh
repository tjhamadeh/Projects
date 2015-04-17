#!/bin/bash

lst=(1 2 3 4 5)
i=${#lst[@]}

for (( idx=0; idx<i; idx++ )); do
    let sum=($sum+${lst[idx]})
done

echo "$sum"