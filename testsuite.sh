#!/bin/bash
cd test
awk -f test.awk -v exe="$utftex" testsuite.txt
R=$(awk -f test.awk -v exe="$utftex" testsuite.txt |tail -n 1|awk '{print $2}')

if [ "$R" -gt 0 ]
then
	exit  1
else
	exit 0
fi
