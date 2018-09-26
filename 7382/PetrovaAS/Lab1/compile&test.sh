#!/bin/bash
g++ ./Source/main.cpp -o lab1
echo -e 'Test 1:\n'
./lab < ./Test/test1.txt
echo -e '________________________\n'
echo -e 'Test 2:\n'
./lab < ./Test/test2.txt
echo -e '________________________\n'
echo -e 'Test 3:\n'
./lab < ./Test/test3.txt
echo -e '________________________\n'
echo -e 'Test 4:\n'
./lab < ./Test/test4.txt
echo -e '________________________\n'
echo -e 'Test 5:\n'
./lab < ./Test/test5.txt
echo -e '________________________\n'
echo -e 'Test 6:\n'
./lab < ./Test/test6.txt
echo -e '________________________\n'
