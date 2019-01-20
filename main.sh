#!/bin/bash

output=$(cat /dev/stdin | grep -o -E '^.*#include\s[<"].+\.h[>"]$' | sort | uniq | sed -n '$=')

echo "The amount of unique C++ header files is $output."