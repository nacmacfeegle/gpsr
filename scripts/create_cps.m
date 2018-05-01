% octave function to compute cumulative probability of success

function create_cps(numruns, numgens)

	% get everything into one big matrix	
	load all_results.dat;

	% in this example, the hits values are in the fourth column:
	traincolumns = all_results(:,4);

	% access the values from the first run
	trainmatrix = traincolumns(1:numgens);

	% now, gather each run into a matrix
	for i = 1:numruns-1
		% adding a column to it each time
		trainmatrix = [trainmatrix traincolumns((i*numgens)+1:(i*numgens)+numgens)];
	endfor

	% get the first set
	train_means = trainmatrix(1,:);
	train_meanvals = count_successful(train_means, numruns);

	% now add to the first set
	for i = 2:numgens
		train_means = trainmatrix(i,:);
		train_meanvals = [train_meanvals count_successful(train_means, numruns)];
	endfor

	% rotate each row vector of results into a column vector (not necessary, but I find it helps
	% to view the results in a top to bottom format rather than left to right)
	train_meanvals = rot90(train_meanvals, 3);

	gens_list=rot90([0:numgens-1],3);
	results_trn=[gens_list train_meanvals];
	
	save cps.dat results_trn;

endfunction

function result = count_successful(gen, numruns)
	result = 0;

	for i = 1:length(gen)
		if ( gen(i) == 1.0 ) 
			result = result+1;
		endif
	endfor

	result = result / numruns;
endfunction
