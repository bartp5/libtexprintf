#!/bin/bash

if [ -z "$1" ]
then
	echo I need a name
	exit 1
fi
name=$1
shift

if [ -z "$1" ]
then
	echo I an equation
	exit 1
fi

eq=$1

# test various options
utftex "$eq" > 0.tmp
utftex -A "$eq" > 1.tmp
utftex -S "$eq" > 2.tmp
utftex -m "$eq" > 3.tmp
refs=(0 0 0 0)
opt=("" "-A" "-S" "-m")
echo "<input> $name"
echo "$eq"
for i in 0 1 2 3
do
	arg=${opt[$i]}
	if [ "${refs[$i]}" -eq 0 ]
	then
		let "j=i+1"
		while [ "$j" -lt 4 ]
		do
			if [ "${refs[$j]}" -eq 0 ]
			then
				if cmp -s $i.tmp $j.tmp
				then
					arg="$arg | ${opt[$j]}"
					refs[$j]=1
				fi
			fi		
			let "j=j+1"
		done
		echo "<ref> $arg"
		cat $i.tmp
		refs[$i]=1
	fi
done
echo "<end>"
