#!/bin/bash
cd test
f=0;
if [ "$1" == "ASCII" ]
then
	opt="-A"
	shift
else
	opt=""
fi

if [ "$1" == "ref" ]
then
	for i in *.tex
	do
		echo "$i" -- ${i%%.tex}$opt".ref"
		cat "$i"|grep -E '^[^%]' | $utftex $opt > ${i%%.tex}$opt".ref"
	done
else
	for i in *.tex
	do
		cat "$i"|grep -E '^[^%]' | $utftex $opt > tmp
		if ! cmp -s ${i%%.tex}$opt".ref" tmp
		then
			echo FAIL: "$i"
			mv tmp ${i%%.tex}$opt".new"
			let "f++";
		else
			echo PASS: "$i"
		fi
	done
	rm tmp

fi
if [ "$f" -gt 0 ]
then
	exit  1
else
	exit 0
fi
