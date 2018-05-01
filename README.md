
This codebase used to exist at sourceforge and was last touched more than 10 years ago. I'm migrating it to github

gpsr 
-----------

1) type 'make'
2) assuming it works, you should have a binary called 'gpsr' in the bin directory
3) cd bin;
4) ./gpsr

This will give you very short intro which describes how the program should be run.

Quick start:
------------

To get cracking with a batch of 30 runs of GP on a very well known symbolic regression problem
(quartic polynomial), copy the following into a bash script:

---- begin bash script ----
#!/bin/bash

GP=./bin/gpsr				
RESULTS=/path/to/results/directory	# edit as appropriate
NUMRUNS=30
TRAINFILE=./datasets/quartic_train.dat
TESTFILE=./datasets/quartic_test.dat

for i in `seq -w $NUMRUNS`
do
        $GP -d $TRAINFILE -f $TESTFILE -o $RESULTS/best$i -O $RESULTS/res$i
done
---- end bash script ----

Edit the "results=" line to point to a location where you'd like the results to reside

Make the script executable and launch away..

Use your favourite statistics package to analyse the reults. For now, I'd recommend octave (www.octave.org).


CREDITS:
-------
This code would not have been written had I not first been introduced to a much faster system called
FastSR, implemented by Maarten Keijzer. Maarten was kind enough to share his code with me and much of
the functionality that is implemented in gpsr (e.g. postfix, stack-based representation, Linear Scaling)
was first implemented in his code. Thanks for the help Maarten!

