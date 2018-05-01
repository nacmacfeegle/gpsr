/** \file global.h
 * Type definitions, global variables constants.
 */
#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>
#include <valarray>
#include <stack>
#include <string>

#include "rng.h"
#include "gpnode.h"

/********
 *
 *
 * global declarations
 *
 *
 ********/

/* maximum depth of trees */
#define MAXDEPTH 17 // Koza standard 
#define BRANCHSIZE 10 
#define NSM_MAX_TRIES 10000


// create a type for the variables (could be 2d)
typedef std::valarray<double> ResultType;

extern std::vector<ResultType> valueStack;

// now define the variables
extern std::vector<ResultType> variables;

// targets
extern ResultType targets;

// testing stuff
extern std::vector<ResultType> test_variables;
extern ResultType test_targets;

extern std::vector<double> constants;

extern std::vector<GPNode> t_unaries;
extern std::vector<GPNode> t_binaries;
extern std::vector<GPNode> t_variables;
extern std::vector<GPNode> t_constants;

// run settings
extern int tournamentSize;
extern double crossover_prob;
extern double mutation_prob;
extern int genomeSize;
extern int popsize;
extern int numgens;
extern int currentgen;
extern int numConstants;
extern int numVariables;
extern double constRange;
extern bool no_same_mates;
extern bool linear_scaling;
extern bool loose_metric;
extern bool use_potency;
extern bool potency_increasing;
extern bool seed_specified;
extern double hitsCriterion;
extern bool train_with_noise;
extern double jitterFactor;
extern int jitterAmount;

extern std::string unaries;
extern std::string training_file;
extern std::string testing_file;
extern std::string best_file;
extern std::string logfile;

extern ulong seed;
extern RNG rng;

#endif
