#!/bin/bash

if [ -z "$1" ]
then
	echo "Usage:"
	echo "MakeTest.sh <test-name> <text-equation> [optional utftex arguments]"
	echo I need a name
	exit 1
fi
name=$1
shift

if [ -z "$1" ]
then
	echo "Usage:"
	echo "MakeTest.sh <test-name> <text-equation> [optional utftex arguments]"
	echo I an equation
	exit 1
fi
eq=$1

shift
opt=(" " "-A" "-S" "-m")
refs=(0 0 0 0)
N=4;
while [ ! -z "$1" ]
do
	opt+=("$1")
	refs+=(0)
	let "N++"
	shift
done


# test various options
for ((i = 0; i < $N; i++))
do
	arg="${opt[$i]}"
	utftex $arg "$eq" > "$i.tmp"
done
echo "<input> $name"
echo "$eq"
i=0
for ((i = 0; i < $N; i++))
do
	arg="${opt[$i]}"
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
for ((i = 0; i < $N; i++))
do
	rm "$i.tmp"
done
