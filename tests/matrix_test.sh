#!/bin/bash

echo ""
echo "Test 1 - testing matrix"

gcc ./matrix/test_01.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./matrix/bin/test_01 -lm
./matrix/bin/test_01
