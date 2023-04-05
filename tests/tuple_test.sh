#!/bin/bash

echo ""
echo "Test 1 - testing for point creation"

gcc ./tuples/test_01.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_01 -lm
./tuples/bin/test_01

echo ""
echo "Test 2 - testing for vector creation"

gcc ./tuples/test_02.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_02 -lm
./tuples/bin/test_02

echo ""
echo "Test 3 - testing for vector addition"
echo "Adding a point and a vector"

gcc ./tuples/test_03.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_03 -lm
./tuples/bin/test03

echo ""
echo "Test 4 - testing for vector addition"
echo "Adding two vectors"

gcc ./tuples/test_04.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_04 -lm
./tuples/bin/test_04

echo ""
echo "Test 5 - testing for vector addition"
echo "Adding two points"

gcc ./tuples/test_05.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_05 -lm
./tuples/bin/test_05

echo ""
echo "Test 6 - testing for vector subtraction"
echo "Subtracting a point from a point"

gcc ./tuples/test_06.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_06 -lm
./tuples/bin/test_06

echo ""
echo "Test 7 - testing for vector subtraction"
echo "Subtracting a vector from a point"

gcc ./tuples/test_07.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_07 -lm
./tuples/bin/test_07

echo ""
echo "Test 8 - testing for vector subtraction"
echo "Subtracting a vector from a vector"

gcc ./tuples/test_08.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_08 -lm
./tuples/bin/test_08

echo ""
echo "Test 9 - testing for vector subtraction"
echo "Subtracting a point from a vector"

gcc ./tuples/test_09.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_09 -lm
./tuples/bin/test_09

echo ""
echo "Test 10 - testing for tuple negation"
echo "Negate a vector"

gcc ./tuples/test_10.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_10 -lm
./tuples/bin/test_10

echo ""
echo "Test 11 - testing for tuple negation"
echo "Negate a point"

gcc ./tuples/test_11.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_11 -lm
./tuples/bin/test_11

echo ""
echo "Test 12 - testing for tuples magnitude"
echo "Magnitude of a vector"

gcc ./tuples/test_12.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_12 -lm
./tuples/bin/test_12

echo ""
echo "Test 13 - testing for tuples magnitude"
echo "Magnitude of a vector"

gcc ./tuples/test_13.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_13 -lm
./tuples/bin/test_13

echo ""
echo "Test 14 - testing for tuples magnitude"
echo "Magnitude of a vector"

gcc ./tuples/test_14.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_14 -lm
./tuples/bin/test_14

echo ""
echo "Test 15 - testing for tuples magnitude"
echo "Magnitude of a vector"

gcc ./tuples/test_15.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_15 -lm
./tuples/bin/test_15

echo ""
echo "Test 16 - testing for tuples magnitude"
echo "Magnitude of a vector"

gcc ./tuples/test_16.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_16 -lm
./tuples/bin/test_16

echo ""
echo "Test 17 - testing for tuples magnitude"
echo "Magnitude of a point"

gcc ./tuples/test_17.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_17 -lm
./tuples/bin/test_17

echo ""
echo "Test 18 - testing for tuple normalization"
echo "Normalize a vector"

gcc ./tuples/test_18.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_18 -lm
./tuples/bin/test_18

echo ""
echo "Test 19 - testing for tuple normalization"
echo "Normalize a vector"

gcc ./tuples/test_19.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_19 -lm
./tuples/bin/test_19

echo ""
echo "Test 20 - testing for tuple dot product"
echo "Get a dot product of two vectors"

gcc ./tuples/test_20.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_20 -lm
./tuples/bin/test_20

echo ""
echo "Test 21 - testing for tuple dot product"
echo "Get a cross product of two vectors"

gcc ./tuples/test_21.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/bin/test_21 -lm
./tuples/bin/test_21
