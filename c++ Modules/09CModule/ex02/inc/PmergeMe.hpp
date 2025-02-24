#ifndef PMERGEME_HPP

#define PMERGEME_HPP

#include <sstream>
#include <vector>
#include <list>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <limits>
#include <math.h>

class PmergeMe 
{
public:
	PmergeMe(char **argv);
	~PmergeMe();

	void runVectorSort();
	void runListSort();
	void printResults();
	bool checkListSort();
	bool checkVectorSort();

private:
	PmergeMe();
	PmergeMe(PmergeMe const & src);
	PmergeMe & operator=(PmergeMe const & rhs);

	char **argv;
	double listTime;
	double vectorTime;
	std::vector<int> input;
	std::vector<int> vector;
	std::list<int> list;

	// Vector
	void buildVectorFromInput();
	void recSortVector(std::vector<int> & vec, int sortSize);
	void checkListOrder();

	// List
	void buildListFromInput();
	void recSortList(std::list<int> & lst, int sortSize);
	void checkVectorOrder();

	// Aux
	void parseTabInput();
	void printVector(std::vector<int> & vec);
	
	// void printList(std::list<int> & lst);

	class NonpositiveInputException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Non positive number found on sequence");
		}
	};
	class InvalidCharacterException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("An invalid character may be present in the sequence");
		}
	};
	class RepeatedNumberException : public std::exception 
	{
		public:
		virtual const char * what() const throw()
		{
			return ("Repeated number found in sequence");
		}
	};
};

#endif
