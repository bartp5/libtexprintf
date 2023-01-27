#!/bin/bash
cd test
f=0
if [ "$1" == "ref" ]
then
	utftex -t > font.ref
else
	utftex -t > tmp
	if ! cmp -s font.ref tmp
	then
		echo FAIL: fonts
		f=1;
	else
		echo PASS: fonts
	fi
	rm tmp
fi
if [ "$f" -gt 0 ]
then
	exit  1
else
	exit 0
fi
