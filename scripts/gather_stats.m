% octave function to do some statistical stuff. 
% 
% example use:
%
% suppose you have 50 results files from 50 runs each with two columns (generation fitness) eg:
%
% 1	2.4
% 2	1.9
% 3	1.5
% 4	1.0
% 5	0.5
%
% with the 50 results files (log01.dat .. log50.dat) we contatenate them all into one big file:
%
% cat log*.dat > all_results.dat
%
% which is then loaded by this octave function to compute the statistics.

function gather_stats(numruns, numgens, confidence_level)

	% get everything into one big matrix	
	load all_results.dat;

	% in this example, the fitness values are in the second column:
	traincolumns = all_results(:,2);
	testcolumns = all_results(:,3);

	% access the values from the first run
	trainmatrix = traincolumns(1:numgens);
	testmatrix = testcolumns(1:numgens);

	% now, gather each run into a matrix
	for i = 1:numruns-1
		% adding a column to it each time
		trainmatrix = [trainmatrix traincolumns((i*numgens)+1:(i*numgens)+numgens)];
		testmatrix = [testmatrix testcolumns((i*numgens)+1:(i*numgens)+numgens)];
	endfor

	% save the matrix (not necessary, but handy to verify)
	% save big_matrix.dat testmatrix;

	% get test_means, test_medians and test_stdvals
	% this time, we're accessing the rows of the matrix, getting the mean, median, stddev
	% values for each generation, across all runs

	% get the first set
	train_means = trainmatrix(1,:);
	train_meanvals = mean(train_means);
	test_means = testmatrix(1,:);
	test_meanvals = mean(test_means);

	train_medians = trainmatrix(1,:);
	train_medianvals = median(train_medians);
	test_medians = testmatrix(1,:);
	test_medianvals = median(test_medians);

	train_stds = trainmatrix(1,:);
	train_stdvals = std(train_stds);
	test_stds = testmatrix(1,:);
	test_stdvals = std(test_stds);

	% now add to the first set
	for i = 2:numgens
		% do the test_means for the current row
		train_means = trainmatrix(i,:);
		train_meanvals = [train_meanvals mean(train_means)];
		test_means = testmatrix(i,:);
		test_meanvals = [test_meanvals mean(test_means)];

		% now the test_medians for the current row
		train_medians = trainmatrix(i,:);
		train_medianvals = [train_medianvals median(train_medians)];
		test_medians = testmatrix(i,:);
		test_medianvals = [test_medianvals median(test_medians)];

		% do the test_stdvals for the current row
		train_stds = trainmatrix(i,:);
		train_stdvals = [train_stdvals std(test_stds)];
		test_stds = testmatrix(i,:);
		test_stdvals = [test_stdvals std(test_stds)];
	endfor

	% rotate each row vector of results into a column vector (not necessary, but I find it helps
	% to view the results in a top to bottom format rather than left to right)
	test_meanvals = rot90(test_meanvals, 3);
	test_medianvals = rot90(test_medianvals, 3);
	test_stdvals = rot90(test_stdvals, 3);

	train_meanvals = rot90(train_meanvals, 3);
	train_medianvals = rot90(train_medianvals, 3);
	train_stdvals = rot90(train_stdvals, 3);

	% now just save the buggers 
	% save results_train_meanvals.dat train_meanvals;
	% save results_test_meanvals.dat test_meanvals;

	%save results_test_medianvals.dat test_medianvals;
	%save results_test_stdvals.dat test_stdvals;

	% calculate the upper and lower errorbars
	train_upbar=train_meanvals .+ (confidence_level .* (train_stdvals ./ sqrt(numruns)));
	train_lobar=train_meanvals .- (confidence_level .* (train_stdvals ./ sqrt(numruns)));
	train_the_error= train_upbar .- train_lobar ./ 2;

	test_upbar=test_meanvals .+ (confidence_level .* (test_stdvals ./ sqrt(numruns)));
	test_lobar=test_meanvals .- (confidence_level .* (test_stdvals ./ sqrt(numruns)));
	test_the_error= (test_upbar .- test_lobar) ./ 2;

	% save results_test_errors.dat test_the_error;
	% save results_train_errors.dat train_the_error;

	gens_list=rot90([0:numgens-1],3);
	%results_trn=[gens_list train_meanvals train_the_error train_upbar train_lobar];
	%results_tst=[gens_list test_meanvals test_the_error test_upbar test_lobar];
	results_trn=[gens_list train_meanvals train_the_error];
	results_tst=[gens_list test_meanvals test_the_error];
	
	save results_test.dat results_tst;
	save results_train.dat results_trn;

endfunction
