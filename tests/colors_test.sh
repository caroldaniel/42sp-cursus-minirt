#!/bin/bash

echo ""
echo "Test 1 - testing colors"

gcc ./colors/test_01.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./colors/bin/test_01 -lm
./colors/bin/test_01
