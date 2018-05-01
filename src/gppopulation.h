
/**
 * GPPopulation class.
 *
 * This class represents a population of GP individuals. 
 * 
 */


#ifndef GPPOPULATION_H
#define GPPOPULATION_H

#include "gpprogram.h"
#include <vector>
#include <string>

class GPPopulation {

	public:
		/**
		 * Constructor.
		 * @param size the populatiln size
		 */
		GPPopulation(int size);
		/**
		 * Copy Constructor.
		 * @param other population to be copied
		 */
		GPPopulation(const GPPopulation &other);
		/**
		 * Constructor.
		 * @param size the population size
		 * @param indySize the maximum size of an individual in the population
		 */
		GPPopulation(int size, int indySize);
		
		/**
		 * Destructor.
		 */
		~GPPopulation();
		
		/**
		 * Assignment operator
		 */
		void operator=(const GPPopulation &rhs);

		/**
		 * Get the index of the best individual
		 * @return the index of the best individual
		 */
		int getIndexOfBest() const;
		
		/**
		 * Get the population
		 * @return the population
		 */
		std::vector<GPProgram*> getPopulation() const;
		
		/**
		 * Get the population size.
		 * @return the population size
		 */
		int getSize() const;

		/**
		 * Set the index of the best individual
		 * @param index the index of the best individual
		 */
		void setIndexOfBest(int index);
		
		/**
		 * Set the population
		 * @param pop the new population
		 */
		void setPopulation(const std::vector<GPProgram*> &pop);

		/**
		 * Get an individual
		 * @param index the population vector index
		 * @return the individal at the index specified
		 */
		GPProgram* getIndividual(int index) const;
		
		/**
		 * Get the fitness of an individual within the population
		 * @param index the index of the population
		 * @return the fitness of the individual at the specified index
		 */
		double getIndividualFitness(int index);

		/**
		 * Set the individual at a specific value in the population to a given individual.
		 * @param index the index of the individual to set
		 * @param indy the new individual
		 */
		void setIndividual(int index, GPProgram* indy);
		
		/**
		 * Get the best indidivual
		 * @return the best individual
		 */
		GPProgram* getBestIndividual();
		
		/**
		 * Update the member value that holds the current index of the best individual
		 */
		void updateBestIndividual();
		
		/**
		 * Get the index of the worst individual (used for replacement)
		 * @return the index of the least fit individual
		 */
		int getIndexOfWorst();
		
		/**
		 * Calculate the fitness of the population
		 */
		void calculatePopulationFitness();

	private:
		int indexOfBest;
		std::vector<GPProgram*> population;
		
		friend std::ostream& operator<<(std::ostream& os, const GPPopulation& pop);
};

#endif
