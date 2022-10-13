#include "AlgorithmMaster.h"


AlgorithmMaster::AlgorithmMaster(Global& _global)
{
	global = &_global;
}

bool bubbleSortStep(std::vector<int>* sortingVector)
{

	return true;
}

void AlgorithmMaster::bubbleSort(std::vector<int>* sortingVector)
{
	numberOfSteps = 0;

	for (int i = 0; i < sortingVector->size() - 1; i++)
	{
		for (int j = 0; j < sortingVector->size() - 1; j++)
		{
			if (sortingVector->at(j) > sortingVector->at(j + 1))
			{
				swap(sortingVector, j, j + 1);
				numberOfSteps++;
			}
		}
	}


}


void AlgorithmMaster::swap(std::vector<int>* sortingVector, unsigned int firstIndex, unsigned int secondIndex)
{
	int varAux = sortingVector->at(firstIndex);
	sortingVector->at(firstIndex) = sortingVector->at(secondIndex);
	sortingVector->at(secondIndex) = varAux;

}