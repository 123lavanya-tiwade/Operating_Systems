#!/bin/bash

echo "Enter first number:"
read a

echo "Enter second number:"
read b

if ((b == 0))
then
    echo "Division by zero not possible"
else
    div=$((a / b))
    echo "Division is: $div"
fi
