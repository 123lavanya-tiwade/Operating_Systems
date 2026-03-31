#!/bin/bash

echo "Enter first number:"
read a

echo "Enter second number:"
read b

if ((a > b))
then
    echo "Largest number is: $a"
else
    echo "Largest number is: $b"
fi
