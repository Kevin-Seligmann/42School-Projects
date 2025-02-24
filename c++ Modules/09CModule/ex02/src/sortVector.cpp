#include "PmergeMe.hpp"

namespace
{
void getNextInd(int & ind, int & jacobsthalInd, int & prevJacobsthal, int & jacobsthal, int & exp)
{
	ind --;
	if (ind == prevJacobsthal)
	{
		jacobsthalInd ++;
		prevJacobsthal = jacobsthal;
		exp = 1 << jacobsthalInd;
		jacobsthal = exp - prevJacobsthal;
		ind = jacobsthal;
	}
}

/*
	Puts the block with the biggest reference ahead, since it's the reference needed for comparison
	on the recursive call on the partitions.
*/
void vectorSwapInsidePartition(std::vector<int> & vec, int sortSize, int partitionMaxInd)
{
	for (int partitionInd = 0; partitionInd < partitionMaxInd; partitionInd ++)
	{
		if (vec[partitionInd * 2 * sortSize] < vec[(partitionInd * 2 + 1) * sortSize])
		{
			for (int i = 0; i < sortSize; i ++)
			{
				std::swap(vec[partitionInd * 2 * sortSize + i], vec[(partitionInd * 2 + 1) * sortSize + i]);
			}
		}
	}
}

/*
	Moving the higher element of the pair to the "main-chain".
	And the lower element to a new second chain.

	(The list implementation of this might be better, creating a vector of vectors)
*/
void vectorSeparatePairs(std::vector<int> & vec, std::vector<int> & vecA, std::vector<int> & vecB, int sizeMaxInd, int sortSize)
{
	int i;
	vecA.reserve(vec.size());
	vecB.reserve((sizeMaxInd / 2) * sortSize);

	for (i = 0; i < sizeMaxInd; i ++)
	{
		if (i % 2 == 0)
		{
			if (i == sizeMaxInd - 1 && sizeMaxInd % 2 == 1)
			{
				vecB.insert(vecB.end(), vec.begin() + i * sortSize, vec.begin() + (i + 1) * sortSize);
			}
			else
			{
				vecA.insert(vecA.end(), vec.begin() + i * sortSize, vec.begin() + (i + 1) * sortSize);
			}
		}
		else
		{
			vecB.insert(vecB.end(), vec.begin() + i * sortSize, vec.begin() + (i + 1) * sortSize);
		}
	}
}

void vectorBinaryInsert(std::vector<int> & vecA, std::vector<int> & vecB, int ind, int sortSize, int exp)
{
	int upperBound = std::min(static_cast<int>(vecA.size() / sortSize), exp);
	int lowerBound = 0;
	int mid;

	ind --;
	while (upperBound > lowerBound)
	{	
		mid = (upperBound + lowerBound) / 2;
		if (vecB[ind * sortSize] > vecA[mid * sortSize])
		{
			lowerBound = mid + 1;
		}
		else 
		{
			upperBound = mid;
		}
	}

	vecA.insert(vecA.begin() + upperBound * sortSize, vecB.begin() + ind * sortSize, vecB.begin() + (ind + 1) * sortSize);
}

void vectorInsertion(std::vector<int> & vecA, std::vector<int> & vecB, int partitionMaxInd, int sizeMaxInd, int sortSize)
{
	int jacobsthalInd = 1;
	int jacobsthal = 1;
	int prevJacobsthal = 0;
	int ind = 1;
	int exp = 2;

	vectorBinaryInsert(vecA, vecB, 1, sortSize, exp);
	while (1)
	{
		getNextInd(ind, jacobsthalInd, prevJacobsthal, jacobsthal, exp);
		if (ind <= partitionMaxInd || (ind == partitionMaxInd + 1 && sizeMaxInd % 2 == 1))
		{
			vectorBinaryInsert(vecA, vecB, ind, sortSize, exp);
		}
		if (prevJacobsthal > partitionMaxInd)
		{
			break;
		}
	}
}
}

/*
	Performs merge-insertion.
	By sorting pair by pair.
	Then sorting the pairs by merge-insertion.
	Then inserting the smaller pair following a sequence defined by jacobshtal numbers.

	Since the recursive calls has to sort pairs, it needs to move the whole pair at once (x2 size).
	The size of the element is controled by sortSize. Which is treated as a singular unit. But 
	have to keep in mind to move the pointers/data.
*/
void PmergeMe::recSortVector(std::vector<int> & vec, int sortSize)
{
	int sizeMaxInd;
	int partitionMaxInd;
	std::vector<int> vecA;
	std::vector<int> vecB;

	sizeMaxInd = vec.size() / sortSize;
	partitionMaxInd = sizeMaxInd / 2;
	if (sizeMaxInd < 2)
	{
		return ;
	}
	vectorSwapInsidePartition(vec, sortSize, partitionMaxInd);
	PmergeMe::recSortVector(vec, sortSize * 2);
	vectorSeparatePairs(vec, vecA, vecB, sizeMaxInd, sortSize);
	vectorInsertion(vecA, vecB, partitionMaxInd, sizeMaxInd, sortSize);
	vec = vecA;
}
