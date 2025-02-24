 #include "PmergeMe.hpp"

namespace
{
// Aux (Console debuging)
// void printListofLists(std::list<std::list<int> > & lists)
// {
//     for (std::list<std::list<int> >::iterator listIt = lists.begin(); listIt != lists.end(); listIt++)
//     {
//         std::cout << "{";
//         printList(*listIt);
//         std::cout << "} ";
//     }
// }


// void printList(std::list<int> & lst)
// {
// 	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it ++)
// 	{
// 		std::cout << *it ;
// 		std::cout << " ";
// 	}
// }

// Push a sublist into place
void pushSublistBack(std::list<std::list<int> > & listOfLists, std::list<int> & source, int size){
    std::list<int> subList;
    std::list<int>::iterator itEnd;

    itEnd = source.begin();
    std::advance(itEnd, size);
    listOfLists.push_back(subList);
    listOfLists.back().splice(listOfLists.back().begin(), source, source.begin(), itEnd);
}

void pushSublistFront(std::list<std::list<int> > & listOfLists, std::list<int> & source, int size){
    std::list<int> subList;
    std::list<int>::iterator itEnd;

    itEnd = source.begin();
    std::advance(itEnd, size);
    listOfLists.push_front(subList);
    listOfLists.front().splice(listOfLists.front().begin(), source, source.begin(), itEnd);
}

// Jacobshtal 
int getJacobsthalByInd(int jInd){
    return (std::pow(2, jInd + 1) + std::pow(-1, jInd)) / 3;
}

// Get reference value
int getSublistReferenceValue(std::list<int> & lst, int sortSize){
    if ((int) lst.size() == sortSize){
        return lst.front();
    }

    std::list<int>::iterator it = lst.begin();

    std::advance(it, sortSize);
    return *it;
}

// Inserts the nodeToSplit node in the listOfLists container behind insertPos
void splitAndInsertNode(std::list<std::list<int > > & listOfLists, std::list<std::list<int> >::iterator & insertPos, std::list<std::list<int> >::iterator & nodeToSplit, int sortSize){
    std::list<int>::iterator mainSublistIt = (*nodeToSplit).begin();
    std::list<std::list<int> >::iterator newSublistIt;

    if ((int) (*nodeToSplit).size() != sortSize){
        std::advance(mainSublistIt, sortSize);
        newSublistIt = listOfLists.insert(insertPos, std::list<int>());
        (*newSublistIt).splice((*newSublistIt).begin(), *nodeToSplit, mainSublistIt, (*nodeToSplit).end());
    } else {
        listOfLists.splice(insertPos, listOfLists, nodeToSplit);
    }
}

// Binary search 
void binaryInsertList(std::list<std::list<int > > & listOfLists, std::list<std::list<int> >::iterator & nodeToSplit, int sortSize){
    int sublistReferenceValue = getSublistReferenceValue(*nodeToSplit, sortSize);
    std::list<std::list<int> >::iterator lowerBoundIt = listOfLists.begin();
    std::list<std::list<int> >::iterator upperBoundIt = nodeToSplit;
    std::list<std::list<int> >::iterator midIt;

	while (lowerBoundIt != upperBoundIt)
	{	
		midIt = lowerBoundIt;
        std::advance(midIt, std::distance(lowerBoundIt, upperBoundIt) / 2);
        if (sublistReferenceValue > (*midIt).front()) {
            lowerBoundIt = midIt;
            lowerBoundIt ++;
        } else {
            upperBoundIt = midIt;
        }
	}

    splitAndInsertNode(listOfLists, lowerBoundIt, nodeToSplit, sortSize);
}

// Walks the listsoflists searching for nodes to split based on a sequence defined by jacobshtal numbers
void mergeInsertListOfLists(std::list<std::list<int> > & listOfLists, std::list<int> & remainingElement, int sortSize){
    int jacobshtalIteration = 2;
    int nodesToSeparateCount;
    int nodesSeparatedCount = 1;
    int originalSize = listOfLists.size() - 1;

    std::list<std::list<int> >::iterator itToLastNodeOfIteration = listOfLists.begin();
    std::list<std::list<int> >::iterator lastNodeSeparated;
    
    itToLastNodeOfIteration ++;
    while (nodesSeparatedCount != originalSize){
        nodesToSeparateCount = std::min(getJacobsthalByInd(jacobshtalIteration ++), originalSize);
        std::advance(itToLastNodeOfIteration, nodesToSeparateCount - nodesSeparatedCount);
        lastNodeSeparated = itToLastNodeOfIteration;

        while (nodesSeparatedCount < nodesToSeparateCount){
            while ((int) (*lastNodeSeparated).size() == sortSize){
                lastNodeSeparated --;
            }
            binaryInsertList(listOfLists, lastNodeSeparated, sortSize);
            nodesSeparatedCount ++;
        }
    }
    if (!remainingElement.empty()){
        pushSublistBack(listOfLists, remainingElement, sortSize);
        std::list<std::list<int> >::iterator back = listOfLists.end();
        back --;
        binaryInsertList(listOfLists, back, sortSize);
    }
}

void buildListOfLists(std::list<std::list<int> > & listOfLists, std::list<int> & list, int sortSize, int elementCount){
    int ind;
    int pairsToMerge;

    ind = 0;
    pairsToMerge = elementCount / 2 - 1;
    pushSublistFront(listOfLists, list, sortSize);
    pushSublistFront(listOfLists, list, sortSize);
    while (ind < pairsToMerge){
        pushSublistBack(listOfLists, list, sortSize * 2);
        ind ++;
    }
}

void sortListPairs(std::list<int> & lst, std::list<int> & remainingElement, int sortSize, int elementCount){
    std::list<int>::iterator itBehind;
    std::list<int>::iterator itAhead;
    std::list<int>::iterator itNextElement = lst.begin();
    int pairsSorted = 0;
    int pairsToSort = elementCount / 2;

    while (pairsSorted < pairsToSort){
        itBehind = itNextElement;
        std::advance(itNextElement, sortSize);
        itAhead = itNextElement;
        std::advance(itNextElement, sortSize);
        if (*itBehind < *itAhead){
            lst.splice(itNextElement, lst, itBehind, itAhead);
        }
        pairsSorted ++;
    }

    if (elementCount % 2 != 0){
        std::list<int>::iterator auxIt;

        auxIt = lst.end();
        std::advance(auxIt, -sortSize);
        remainingElement.splice(remainingElement.begin(), lst, auxIt, lst.end());
    }
}

void rebuildList(std::list<std::list<int> > & listOfLists, std::list<int> & list){
    std::list<std::list<int> >::iterator tailIt;

    tailIt = listOfLists.end();
    while (tailIt != listOfLists.begin()){
        tailIt --;
        list.splice(list.begin(), *tailIt);
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
void PmergeMe::recSortList(std::list<int> & lst, int sortSize)
{
    std::list<std::list<int> > listOfLists;
    std::list<int> remainingElement;
    int elementCount;

    elementCount = lst.size() / sortSize;
    if (elementCount == 1){
        return ;
    }

    sortListPairs(lst, remainingElement, sortSize, elementCount);
    recSortList(lst, sortSize * 2);
    buildListOfLists(listOfLists, list, sortSize, elementCount); 
    mergeInsertListOfLists(listOfLists, remainingElement, sortSize);
    rebuildList(listOfLists, lst);
}
