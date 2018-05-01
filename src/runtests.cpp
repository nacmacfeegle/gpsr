#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

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


	cout << "MAXDEPTH = " << MAXDEPTH << endl;
	cout << "genomeSize = " << genomeSize << endl;

	if (!seed_specified) {
		seed = time(0) ^ (getpid() << 16);
	}
	rng.reseed(seed);

	for (unsigned i=0; i<constants.size(); i++) {
		cout << "const[" << i << "]: " << constants[i] << endl;
	}

	printSettings();

	GPProgram *prog1;
	GPProgram *prog2;
	prog1 = new GPProgram(32, 6);
	prog2 = new GPProgram(32, 6);

	if (! prog1->sanityCheck()) {
		cout << "FUCK! Invalid individual:" << endl << prog1->printPostfix() << endl;;
	}
	if (! prog2->sanityCheck()) {
		cout << "FUCK! Invalid individual:" << endl << prog2->printPostfix() << endl;;
	}

	cout << prog1->printPostfix() << endl;
	cout << prog2->printPostfix() << endl;

	cout << "performing crossover:" << endl;
	GPProgram *child = xover(*prog1, *prog2);
	cout <<  *child << endl;
	if (! child->sanityCheck()) {
		cout << "FUCK! Invalid individual:" << endl << child->printPostfix() << endl;;
	}
	//prog1->calcFitness(true);
	//cout << "Training score:\t" << prog1->getFitness() << endl;
	//cout << "Testing score:\t" << prog1->getTestFitness() << endl;

	
	delete prog1;
	cleanup();

	return EXIT_SUCCESS;
}
