#!/bin/bash
cd test
f=0;
if [ "$1" == "ref" ]
then
	for i in *.tex
	do
		echo "$i" -- ${i%%tex}"ref"
		cat "$i"|grep -E '^[^%]' | utftex > ${i%%tex}"ref"
	done
else
	for i in *.tex
	do
		cat "$i"|grep -E '^[^%]' | utftex > tmp
		if ! cmp -s ${i%%tex}"ref" tmp
		then
			echo FAIL: "$i"
			mv tmp ${i%%tex}"new"
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
