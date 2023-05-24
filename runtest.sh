#!/bin/bash
cd test
f=0;
opt=""
fopt=""
if [ "$1" == "ASCII" ]
then
	opt="-A"
	fopt="-A"
	shift
elif [ "$1" == "SPRINTF" ]
then
	opt="-S"
	shift
fi

if [ "$1" == "ref" ]
then
	for i in *.tex
	do
		echo "$i" -- ${i%%.tex}$fopt".ref"
		cat "$i"|grep -E '^[^%]' | utftex $opt > ${i%%.tex}$fopt".ref"
	done
else
	for i in *.tex
	do
		cat "$i"|grep -E '^[^%]' | utftex $opt > tmp
		if ! cmp -s ${i%%.tex}$fopt".ref" tmp
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
