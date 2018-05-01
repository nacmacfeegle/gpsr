#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h> 

#include "global.h"
#include "gppopulation.h"
#include "gpoperators.h"
#include "usefulfunctions.h"
#include "rng.h"

using namespace std;

int main( int argc, char* argv[] ) {

	setupGlobals(argc, argv);
	loadFiles(training_file, testing_file);
	setupNodeLists();


	if (!seed_specified) {
		seed = time(0) ^ (getpid() << 16);
	}
	rng.reseed(seed);

	printSettings();

	int best1 = 0;
	int best2 = 0;
	int worst = 0;
	double fit1 = 0.0;
	double fit2 = 0.0;

	int trainHits = 0;
	int testHits = 0;

	// create population
	GPPopulation *pop = new GPPopulation(popsize, genomeSize);
	pop->calculatePopulationFitness();

	best1 = pop->getIndexOfBest();

	double trainPerf = pop->getIndividual(best1)->getFitness();
	double testPerf = pop->getIndividual(best1)->getTestFitness();

	trainHits = pop->getIndividual(best1)->getNumberOfHits(hitsCriterion, true);
	testHits = pop->getIndividual(best1)->getNumberOfHits(hitsCriterion, false);

	std::ofstream logger(logfile.c_str());
	logger << "0\t" << 1.0 / (1.0 + trainPerf) << "\t" << 1.0 / (1.0 + testPerf) << "\t" << ( (double) (trainHits) / (double) targets.size() ) << "\t" << ( (double) testHits / (double) test_targets.size() )<< "\t" << trainPerf << "\t" << testPerf << endl;
	logger.flush();

	GPProgram* elite;

	for (int i=1; i<=numgens; i++) {

		// update global current gen counter
		currentgen = i;

		best1 = pop->getIndexOfBest();
		elite = new GPProgram(*(pop->getIndividual(best1)));
		fit1 = elite->getFitness();

		// do operators
		tournamentSelection(*pop);
		crossover(*pop);
		mutation(*pop);

		// calculate fitness
		pop->calculatePopulationFitness();
		best2 = pop->getIndexOfBest();
		fit2 = pop->getIndividualFitness(best2);

		if (fit1 < fit2) {
			
			// selection and operators did not produce a beter
			// individual, so we should keep the previous best. 
			// We do this by replacing the current worst with
			// the old best
		
			// find current worst
			worst = pop->getIndexOfWorst();
			
			// update that individual with the previous best
			pop->setIndividual(worst, elite);

			// training and testing performance should  therefore 
			// be taken from the previous best
			trainPerf = fit1;
			testPerf = elite->getTestFitness();

			// the previous best overwrites the old worst, so we update the indexes
			pop->setIndexOfBest(worst);
			
			// get the hits
			trainHits = pop->getIndividual(worst)->getNumberOfHits(hitsCriterion, true);
			testHits = pop->getIndividual(worst)->getNumberOfHits(hitsCriterion, false);
		}
		else {
			trainPerf = fit2;
			testPerf = pop->getIndividual(best2)->getTestFitness();
	
			// get the hits
			trainHits = pop->getIndividual(best2)->getNumberOfHits(hitsCriterion, true);
			testHits = pop->getIndividual(best2)->getNumberOfHits(hitsCriterion, false);

		}

		logger << i << "\t" << 1.0 / (1.0 + trainPerf) << "\t" << 1.0 / (1.0 + testPerf) << "\t" << ( (double) (trainHits) / (double) targets.size() ) << "\t" << ( (double) testHits / (double) test_targets.size() ) << "\t" << trainPerf << "\t" << testPerf << endl;
	}

	// save best indy
	std::ofstream the_best(best_file.c_str());
	elite = new GPProgram(*(pop->getBestIndividual()));
	the_best << "# seed: " << seed << endl;
	the_best << *elite << endl;
	the_best.flush();
	the_best.close();
	logger.flush();
	logger.close();

	delete elite;
	delete pop;
	cleanup();

	return EXIT_SUCCESS;
}
