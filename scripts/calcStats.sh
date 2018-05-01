#!/bin/bash

cl=1.96
nr=$1
ng=$2

# check args
if [ $# -eq 3 ]
then
	cl=$3
fi

./dostats.sh $nr $ng $cl

# remove comments from file
cat results_test.dat | grep -v "#" |  awk '{print $2"	"$3}' > test.csv;
