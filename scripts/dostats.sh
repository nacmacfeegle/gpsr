#! /usr/bin/octave -qf

numruns = str2num (nth (argv, 1));
numgens = str2num (nth (argv, 2));
cl = str2num (nth (argv, 3));

gather_stats(numruns, numgens, cl);
