/**
 * GPProgram class.
 *
 * This class represents a GP individual. A GPProgram is a (postfix-ordered)
 * array of GPNode objects.
 *
 */

#ifndef GPPROGRAM_H
#define GPPROGRAM_H

#include <stack>

#include "gpnode.h"
#include "global.h"

class GPProgram {

	public:
		/**
		 * Default constructor.
		 * If called with no params, this will create an empty GPProgram
		 */
		GPProgram();

		/**
		 * Copy constructor.
		 * Copies a GPProgram.
		 * @param other 	the GPProgram to be copied.
		 */
		GPProgram(const GPProgram& other);

		/**
		 * Constructor.
		 * Creates a GPProgram with the specified size and maximum tree depth.
		 * @param size 		the size 
		 * @param maxDepth	the maximum tree depth 
		 */
		GPProgram(int size, int maxDepth);

		/**
		 * Destructor.
		 */
		~GPProgram();

		/**
		 * Assignment operator.
		 */
		void operator=(const GPProgram &rhs);

		//
		// accessors
		//

		/**
		 * Gets the genome (the postfix array)
		 * @return the postfix-ordered array of GPNodes
		 */
		std::vector<GPNode*> getGenome() const;

		/**
		 * Gets the size of the GPProgram.
		 * @return the size
		 */
		int getSize() const;

		/**
		 * Gets the fitness of the GPProgram.
		 */
		double getFitness() const;

		/**
		 * Gets the linear scaling coefficient A (if used)
		 * @return the LS A coefficient
		 */
		double getLSCoeffA() const;

		/**
		 * Gets the linear scaling coefficient B (if used)
		 * @return the LS B coefficient
		 */
		double getLSCoeffB() const;

		/**
		 * Gets the type of a node in the GPProgram, indexed by the parameter specified.
		 * @param i the index of the GPProgram
		 * @return the type of the node at position i.
		 */
		std::string getType(int i) const;

		//
		// mutators
		// 
		
		/**
		 * Set the genome.
		 * @param genome the genome to set.
		 */
		void setGenome(const std::vector<GPNode*> &genome);
	
		/**
		 * Set the size.
		 * @param s the size
		 */
		void setSize(int s);

		/**
		 * Set the fitness.
		 * @param fit the fitness
		 */
		void setFitness(double fit);

		/**
		 * Set the LS A coefficient
		 * @param a the LS A coefficient
		 */
		void setLSCoeffA(double a);

		/**
		 * Set the LS B coefficient
		 * @param b the LS B coefficient.
		 */
		void setLSCoeffB(double b);

		//
		// other member functions
		// 
	
		/**
		 * Get the test performance
		 * @return the test performance
		 */
		double getTestFitness();

		/**
		 * Add a GPNode to the end of the genome
		 * @param gpnode the node to add
		 */
		void addNode(GPNode *gpnode);

		/**
		 * Remove a node from a specified index.
		 * @param index the index to remove the node from
		 */
		void removeNode(int index);

		/**
		 * Set a node at a specific index to a particular value.
		 * @param index the index of the value to set
		 * @param gpnode the new value to set at that index
		 */
		void setNode(unsigned index, GPNode *gpnode);

		/**
		 * Inserts a node at a specified location.
		 * @param index the index of the genome to insert the value into
		 * @param gpnode the GPNode to be inserted.
		 */
		void insertNode(int index, GPNode *gpnode);

		/**
		 * Inserts a subtree at a specified location.
		 * @param index the index of the genome to start the insertion from.
		 * @param subtree the list of GPNodes to be inserted
		 */
		void insertSubtree(int index, const std::vector<GPNode*> &subtree);

		/**
		 * Remove a subtree from a GPProgram.
		 * @param start the starting index to remove nodes from
		 * @param end the end index to remove nodes from
		 */
		void removeSubtree(int start, int end);

		/**
		 * Get a subtree between the specified indices.
		 * @param start the start index
		 * @param end the end index
		 * @return the subtree between start and end
		 */
		std::vector<GPNode*> getSubtree(int start, int end) const;

		/**
		 * Get a node at a specific index
		 * @param index the index of the node to get
		 * @return the GPNode at that index.
		 */
		GPNode* getNode(int index) const;

		/**
		 * Resets the member field size to the genome array size
		 */
		void resetSize();

		/**
		 * Gets an array of the depth values of each node in the genome
		 * @return the depth array
		 */
		std::vector<int> getDepths() const;

		/**
		 * Initialise a GPProgram
		 * @param size the size of the genome
		 * @param maxDepth the maximum depth
		 */
		void initialise(int size, int maxDepth);

		/**
		 * Evaluate a GPProgram.
		 * @param training a flag that specifies training (1) or testing (0). 
		 * @return an array of guesses based on the input data.
		 */
		ResultType evaluate(bool training);

		/**
		 * Calculate the fitness (Mean-squared error).
		 * @param training a flag that specifies training (1) or testing (0). 
		 * @return the fitness
		 */
		double calcFitness(bool training);

		/**
		 * Performs Linear Scaling to produce 2 coefficients that act on the
		 * GPProgram to improve its training performance.
		 */
		void linearScaling(const ResultType &evolved, const ResultType &target);

		/**
		 * Gets the (training) guesses
		 * @return the training guesses
		 */
		ResultType getEvolvedGuesses();


		/**
		 * outputs the raw, postfix representation
		 * @return a string in postfix notation that represents the program
		 */
		std::string printPostfix();

		/**
		 * Count the number of hits that an individual receives
		 * @param hitsCriterion the "closeness-factor" between the guesses and targets.
		 * @param training a flag that specifies training (1) or testing (0). 
		 * @return the number of times that the guesses come close enough to the targets.
		 */
		int getNumberOfHits(double hitsCriterion, bool training);

		/**
		 * Sanity check that an individual maps okay using the stack
		 * @return true if the indy is valid, false otherwise
		 */
		bool sanityCheck();

	private:
		std::vector<GPNode*> genome;
		int size;
		double fitness;
		
		// linear scaling stuff
		double lsCoeffA;
		double lsCoeffB;
	
		friend std::ostream& operator<<(std::ostream& os, const GPProgram& gpprog);
};
#endif
