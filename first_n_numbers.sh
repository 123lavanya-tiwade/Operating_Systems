#!/bin/bash

echo "Enter a number (n):"
read n

i=1
sum=0

while [ $i -le $n ]
do
    sum=$((sum + i))  
    i=$((i + 1))      
done

echo "The sum of the first $n numbers is: $sum"

