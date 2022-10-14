#include "AlgorithmMaster.h"


AlgorithmMaster::AlgorithmMaster()
{

}


void AlgorithmMaster::swap(std::vector<int>* sortingVector, unsigned int firstIndex, unsigned int secondIndex)
{
	int varAux = sortingVector->at(firstIndex);
	sortingVector->at(firstIndex) = sortingVector->at(secondIndex);
	sortingVector->at(secondIndex) = varAux;

}