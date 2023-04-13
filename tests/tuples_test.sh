#!/bin/bash

echo ""
echo "Test 1 - testing tuples"

gcc ./tuples/test_01.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_01 -lm
./tuples/bin/test_01
