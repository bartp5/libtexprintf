#!/bin/bash
cd test
if [ "$1" == "ref" ]
then
	for i in *.tex
	do
		echo "$i" -- ${i%%tex}"ref"
		cat "$i"|grep -E '^[^%]' | utftex > ${i%%tex}"ref"
	done
	f=0;
else
	p=0;
	f=0;
	for i in *.tex
	do
		cat "$i"|grep -E '^[^%]' | utftex > tmp
		cmp  ${i%%tex}"ref" tmp
		if ! cmp -s ${i%%tex}"ref" tmp
		then
			echo FAIL: "$i"
			mv tmp ${i%%tex}"new"
			let "f++";
		else
			echo PASS: "$i"
			let "p++";
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
