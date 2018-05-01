/** \file gpoperators.h
 * GP operators.
 * A set of GP-specific operators
 */

#ifndef GPOPERATORS_H
#define GPOPERATORS_H

#include <vector>
#include "gppopulation.h"

/**
 * Perform tournament selection on the population. The tournament size is specified by a global value, set via the command line arguments
 * @param pop the population
 */
void tournamentSelection(GPPopulation &pop);

/**
 * Population-based mutation.
 * @pop the population
 */
void mutation(GPPopulation &pop);

/**
 * Population based crossover
 * @pop the population
 */
void crossover(GPPopulation &pop); 


/**
 * Tournament selection. Performs an n-way tournament on randomly selected competitors and returns the index of the winner.
 * @param pop the population
 */
int select(GPPopulation &pop);

/**
 * Performs crossover on 2 individuals.
 * @param mom the first parent
 * @param dad the second parent
 * @return the child created via crossover between the 2 parents
 */
GPProgram* xover(const GPProgram &mom, const GPProgram &dad);

/**
 * Performs branch mutation (random subtree insertion) on an individual.
 * @param indy the individual to branch-mutate
 */
void branchMutate(GPProgram &indy);

/**
 * Performs node mutation (random node insertion) on an individual.
 * @param indy the individual to node-mutate
 */
void nodeMutate(GPProgram &indy);

/**
 * Grow a valid subtree (like GPProgram initialisation).
 * @param size the size
 * @param startDepth the starting depth of the tree, note that the global MAXDEPTH value will be respected.
 * @return a legal subtree as a vector of GPNodes
 */
std::vector<GPNode*> growSubtree(int size, int startDepth);

/**
 * Find the start of a subtree in an individual
 * @param depths a vector of the depth values for each node in the GPProgram.
 * @param index the index to start from
 * @param gpprog the individual to operate on
 * @return the start index of the subtree
 */
int findStart(std::vector<int> depths, int index, const GPProgram &gpprog);

/**
 * Find and return the maximum depth of the individual.
 * @param depths a vector of depth values
 * @return the maximum depth value
 */
int getMaxDepth(std::vector<int> depths);

#endif
