#!/bin/bash

echo "Enter a number:"
read n

if ((n % 2 == 0))
then
    echo "Number is Even"
else
    echo "Number is Odd"
fi
