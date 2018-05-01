/** \file usefulfunctions.h
 *   A set of useful functions that are used by many aspects of the GP system. 
 */

#ifndef USEFULFUNCTIONS_H
#define USEFULFUNCTIONS_H

//
// ~~~~~~~~ GP-specific functions ~~~~~~~~~~
// 

/**
 * Random Integer function.
 * Gets a random integer between low and high parameters specified (inclusive)
 * @param low the lower limit
 * @param high the higher limit
 * @return a random number between the limits
 */
int intRandom(const int &low, const int &high);


/**
 * Jitter a value.
 * Applies a numeric mutation to a value.
 * @param val the value to be mutated
 * @param factor the factor to mutate the value by
 * @return the mutated value
 */
double jitter(const double &val, const double &factor);

/**
 * Protected Division.
 * Performs protected division on 2 operands. Note that the value 0
 * is returned when the denominator is 0.
 * @param a the numerator
 * @param b the denominator
 * @return a/b if b != 0, 0 otherwise.
 */
double protectedDivision(const double &a, const double &b);

/**
 * Protected Division (vectorized evaluation).
 * Performs protected division on 2 operands. Note that the value 0
 * is returned when the denominator is 0. This function operates on vectors.
 * @param a the numerator
 * @param b the denominator
 * @return a/b if b != 0, 0 otherwise.
 */
ResultType protectedDivision(const ResultType &a, const ResultType &b);

/**
 * Protected Log.
 * Performs protected log on 1 operand. Note that the value 0
 * is returned when the operand is less than or equal to 0. 
 * @param a the operand
 * @return log(a) if a > 0, 0 otherwise.
 */
double protectedLog(const double &a);

/**
 * Apply random noise to the input set.
 */
void applyJitter();


/**
 * Protected Log (vectorized evaluation).
 * Performs protected log on 1 operand. Note that the value 0
 * is returned when the operand is less than or equal to 0. 
 * @param a the operand
 * @return log(a) if a > 0, 0 otherwise.
 */
ResultType protectedLog(const ResultType &a);

/**
 * Count the number of hits -- this is the number of times that
 * an array of guesses is "close enough" to an array of targets. The 
 * specification of "close enough" is done via a distance criterion value.
 * @param targets the target values
 * @param guesses the individual
 * @param criterion the distance criterion
 * @return the number of times the guesses come within the range of the targets.
 */
int countHits(const ResultType &targets, const ResultType &guesses, double criterion);

/**
 * Get a random variable.
 * @return a random variable from the variables list.
 */
GPNode* getRandomVariable();

/**
 * Get a random constant.
 * @return a random constant from the constants list.
 */
GPNode* getRandomConstant();

/**
 * Get a random unary function.
 * @return a random unary from the unaries list.
 */
GPNode* getRandomUnary();

/**
 * Get a random binary function.
 * @return a random binary from the binaries list.
 */
GPNode* getRandomBinary();



//
// ~~~~~~~~ System functions and utils ~~~~~~~~~~
// 

/**
 * Loads the inputs to the system.
 * @param training_file the location of the training data
 * @param testing_file the location of the testing data
 */
void loadFiles(const std::string &training_file, const std::string& testing_file);

/**
 * Converts a double value to a string.
 * @param x the double value to be converted
 * @return a string representation of the double value
 */
std::string doubleToString(const double &x);

/**
 * Converts an int value to a string.
 * @param x the int value to be converted
 * @return a string representation of the int value
 */
std::string intToString(const int &x);

/**
 * Gets the minimum of 2 values.
 * @param a the first value
 * @param b the second value
 * @return the minimum of the 2 values or the first if they are equal.
 */
int min (const int &a, const int &b);

/**
 * Clears the global value stack.
 */
void clearStack();

/**
 * Creates a vector of values.
 * @param value the value to be placed into the vector repeatedly
 * @param res the vector to be created
 */
void createResultType(double value, ResultType & res);

/**
 * Set up the global variables from the arguments.
 * @param argc the number of arguments
 * @param argv the arguments
 */
void setupGlobals(int argc, char* argv[]);

/**
 * Set up the (global) constants list
 */
void setupConstants();

/**
 * Set up the (global) variables list
 */
void setupVariables();

/**
 * Set up the (global) binaries list
 */
void setupBinaries();

/**
 * Set up the (global) unaries list
 */
void setupUnaries();

/**
 * Set up all of the node lists (unaries, binaries, variables, constants)
 */
void setupNodeLists();

/**
 * Print a help message.
 */
void printHelp();

/**
 * Print the system settings.
 */
void printSettings();

/**
 * Clean up lists, deallocate memory etc
 */
void cleanup();

std::string printArray(std::vector<int> data) ;
#endif
