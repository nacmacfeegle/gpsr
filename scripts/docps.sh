#! /usr/bin/octave -qf

numruns = str2num (nth (argv, 1));
numgens = str2num (nth (argv, 2));

create_cps(numruns, numgens);
