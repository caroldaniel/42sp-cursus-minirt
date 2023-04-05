#!/bin/bash

echo ""
echo "Test 1 - testing for point creation"

gcc ./tuples/test_01.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/test_01
./tuples/test_01

echo ""
echo "Test 2 - testing for vector creation"

gcc ./tuples/test_02.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/test_02
./tuples/test_02

echo ""
echo "Test 3 - testing for vector addition"
echo "Adding a point and a vector"

gcc ./tuples/test_03.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/test_03
./tuples/test03

echo ""
echo "Test 4 - testing for vector addition"
echo "Adding two vectors"

gcc ./tuples/test_04.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/test_04
./tuples/test_04

echo ""
echo "Test 5 - testing for vector addition"
echo "Adding two points"

gcc ./tuples/test_05.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/test_05
./tuples/test_05

echo ""
echo "Test 6 - testing for vector subtraction"
echo "Subtracting a point from a point"

gcc ./tuples/test_06.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/test_06
./tuples/test_06

echo ""
echo "Test 7 - testing for vector subtraction"
echo "Subtracting a vector from a point"

gcc ./tuples/test_07.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/test_07
./tuples/test_07

echo ""
echo "Test 8 - testing for vector subtraction"
echo "Subtracting a vector from a vector"

gcc ./tuples/test_08.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/test_08
./tuples/test_08

echo ""
echo "Test 9 - testing for vector subtraction"
echo "Subtracting a point from a vector"

gcc ./tuples/test_09.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/test_09
./tuples/test_09

echo ""
echo "Test 10 - testing for tuple negation"
echo "Negate a vector"

gcc ./tuples/test_10.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/test_10
./tuples/test_10

echo ""
echo "Test 10 - testing for tuple negation"
echo "Negate a point"

gcc ./tuples/test_11.c ../lib/libft/*.c ../src/*/*.c -I ../inc/ -o ./tuples/test_11
./tuples/test_11
