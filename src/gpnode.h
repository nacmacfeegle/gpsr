/**
 * GPNode class. 
 *
 * A GP individual consists of an array of GP nodes. Each GPNode is either a terminal 
 * (leaf) or a non-terminal node. Terminal nodes are variables or constants 
 * while non-terminals are functions. A GPNode has 3 fundamental properties: the data
 * it contains, its type and its arity. The data field is in index to a global array; 
 * at startup, a number of global arrays are created containing information about the 
 * number of constants, variables and functions. Depending on the type of the GPNode, 
 * this data field will index the global array corresponding to that type. The notion 
 * of arity is important for a GPNode as it is the means by which GPProgram objects 
 * (individuals) are created. In this implementation, a GPNode that represents a 
 * variable or a constant will have an arityMin1 = -1. Unary functions have 
 * arityMin1 = 0, binary functions have arityMin1 = 1 and so on. Finally, the type property
 * of a GPNode specifies which type of node is is (be it variable, constant or function).
 *
 */
#ifndef GPNODE_H
#define GPNODE_H

#include <string>

class GPNode {

	public:
		/**
		 * Default constuctor.
		 * If called with no params, this will create a constant value which
		 * indexes the first element of the created constants array (global var)
		 */
		GPNode();

		/**
		 * Constructor. 
		 * Creates a specific type of GPNode object.
		 * @param data 		index to the content (depends on the type)
		 * @param nodetype	node type
		 * @param arityMin1	arity (minus 1) of the node
		 */
		GPNode(int data, std::string nodetype, int arityMin1);

		/**
		 * Copy constructor. 
		 * Copies a GPNode.
		 * @param other 	the node we wish to copy
		 * 
		 */
		GPNode(const GPNode &other);

		/**
		 * Destructor.
		 */
		~GPNode();

		/**
		 * Assignment operator.
		 */
		void operator=(const GPNode &rhs);

		/**
		 * Gets the data.
		 * @return the index of the content of the GPNode
		 */
		int getData() const;

		/**
		 * Gets the GPNode type.
		 * @return the type of the GPNope
		 */
		std::string getType() const;

		/**
		 * Gets the GPNode arity (minus 1).
		 * @return the arity (minus 1)
		 */
		int getArity() const ;

		/**
		 * Set the data value of the GPNode.
		 * @param data 	the index value to set the data to
		 */
		void setData(int data);

		/**
		 * Set the type of the GPNode.
		 * @param nodetype	the type
		 */
		void setType(std::string nodetype);

		/**
		 * Set the arity (minus 1) of the GPNode.
		 * @param arity 	the arity (minus 1)
		 */
		void setArity(int arity);

	private:
		int data;
		std::string nodetype;
		int arityMin1;

		friend std::ostream& operator<<(std::ostream& os, GPNode& gpnode);

};
#endif
