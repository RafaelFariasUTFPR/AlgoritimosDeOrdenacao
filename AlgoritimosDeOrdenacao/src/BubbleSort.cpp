#include "BubbleSort.h"


BubbleSort::BubbleSort()
{

}

void threadedSort(std::vector<int>* sortingVector)
{

	for (int i = 0; i < sortingVector->size() - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < sortingVector->size() - 1; j++)
		{
			if (sortingVector->at(j) > sortingVector->at(j + 1))
			{
				
				AlgorithmMaster().swap(sortingVector, j, j + 1);
				swapped = true;

			}
		}
		if (!swapped)
			break;
	}
}

void BubbleSort::solve(std::vector<int>* sortingVector)
{
	numberOfSteps = 0;

	for (int i = 0; i < sortingVector->size() - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < sortingVector->size() - 1; j++)
		{
			numberOfSteps++;
			if (sortingVector->at(j) > sortingVector->at(j + 1))
			{
				swap(sortingVector, j, j + 1);
				swapped = true;
				
			}
		}
		if (!swapped)
			break;
	}

}
bool BubbleSort::solveStep(std::vector<int>* sortingVector)
{
	std::thread(threadedSort, sortingVector).detach();
}
bool BubbleSort::solveStepa(std::vector<int>* sortingVector)
{
	if (firstIt)
	{
		i = 0;
		j = 0;
		numberOfSteps = 0;
		swapped = false;
		firstIt = false;
	}

	if (i < sortingVector->size() - 1)
	{
		
		if (j < sortingVector->size() - 1)
		{
			numberOfSteps++;
			if (sortingVector->at(j) > sortingVector->at(j + 1))
			{
				swap(sortingVector, j, j + 1);
				swapped = true;

			}
			j++;
			return false;
		}

		if (!swapped)
		{
			firstIt = true;
			return true;
		}
		j = 0;
		i++;
		swapped = false;
		return false;
	}
	firstIt = true;
	return true;
}