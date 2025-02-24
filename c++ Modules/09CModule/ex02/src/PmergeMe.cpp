#include "PmergeMe.hpp"

// Input - Aux
PmergeMe::PmergeMe(char **argv){
	this->argv = argv;
	parseTabInput();
}

void PmergeMe::printVector(std::vector<int> & vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it ++)
	{
		std::cout << *it ;
		std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::parseTabInput(){
	int	n;
	char **args = argv;
	char *end;

	while (*args)
	{
        n = std::strtol(*args, &end, 10);
 		if (*end != '\0' || end == *args)
            throw InvalidCharacterException();
		if (n <= 0)
			throw NonpositiveInputException();
		if (std::find(input.begin(), input.end(), n) != input.end())
			throw RepeatedNumberException();
		input.push_back(n);
		args ++;
	}
}

// Check sort (Testing)
bool PmergeMe::checkListSort(){
	std::list<int>::iterator it = list.begin();
	int prev = *it;

	it ++;
	while (it != list.end()){
		if (prev > *it){
			return false;
		}
		it ++;
	}
	return true;
}

bool PmergeMe::checkVectorSort(){
	std::vector<int>::iterator it = vector.begin();
	int prev = *it;

	it ++;
	while (it != vector.end()){
		if (prev > *it){
			return false;
		}
		it ++;
	}
	return true;
}

// Results
void PmergeMe::printResults(){
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of " << vector.size() <<
	" elements with std::vector: " << vectorTime << " us" << std::endl;

	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Time to process a range of " << list.size() <<
	" elements with std::list: " << listTime << " us" << std::endl;
}


// Vector
void PmergeMe::buildVectorFromInput()
{
	int	n;
	char **args = argv;
	char *end;

	while (*args)
	{
        n = std::strtol(*args, &end, 10);
		vector.push_back(n);
		args ++;
	}
}

void PmergeMe::runVectorSort(){
	struct timespec start;
	struct timespec end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	buildVectorFromInput();
	recSortVector(vector, 1);
	clock_gettime(CLOCK_MONOTONIC, &end);
	
	vectorTime = (double) (end.tv_sec - start.tv_sec) * 1000000. + (double) (end.tv_nsec - start.tv_nsec) / 1000.;
}

// List
void PmergeMe::buildListFromInput()
{
	int	n;
	char **args = argv;
	char *end;

	while (*args)
	{
        n = std::strtol(*args, &end, 10);
		list.push_back(n);
		args ++;
	}
}


void PmergeMe::runListSort(){
	struct timespec start;
	struct timespec end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	buildListFromInput();
	recSortList(list, 1);
	clock_gettime(CLOCK_MONOTONIC, &end);
	
	listTime = (double) (end.tv_sec - start.tv_sec) * 1000000. + (double) (end.tv_nsec - start.tv_nsec) / 1000.;
}

// ----

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(PmergeMe const & src){(void) src;};
PmergeMe & PmergeMe::operator=(PmergeMe const & rhs){(void) rhs; return *this;};
