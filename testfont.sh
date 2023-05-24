#!/bin/bash
cd test
f=0
fonts="mathsfbfit mathsfbf mathfrak mathbfit mathsfit mathcal mathscr mathbf mathbb mathsf mathtt mathnormal text"
if [ "$1" == "ref" ]
then
	for i in $fonts
	do
		echo "$i" -- "font"$i".ref"
		cat font.tex |grep -E '^[^%]' | $utftex -F "$i" > "font"$i".ref"
	done
else
	for i in $fonts
	do
		cat font.tex |grep -E '^[^%]' | $utftex -F "$i" > tmp
		if ! cmp  "font"$i".ref" tmp
		then
			echo FAIL: "$i"
			mv tmp "font"$i".new"
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
