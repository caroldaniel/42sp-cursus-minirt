#!/bin/bash

echo ""
echo "Test 1 - testing rays"

gcc ./rays/test_01.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./rays/bin/test_01 -lm
./rays/bin/test_01
