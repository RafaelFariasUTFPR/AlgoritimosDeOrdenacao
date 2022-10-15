#include "BubbleSort.h"


BubbleSort::BubbleSort(std::vector<int>* _sortingVector) : AlgorithmMaster(_sortingVector)
{

}



void BubbleSort::solve()
{
	startSort();

	for (int i = 0; i < sortingVector->size() - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < sortingVector->size() - 1; j++)
		{
			lastNumberOfSteps++;
			if (sortingVector->at(j) > sortingVector->at(j + 1))
			{
				swap(sortingVector, j, j + 1);
				swapped = true;
				
			}
		}
		if (!swapped)
			break;
	}
	finishSort();

}
void BubbleSort::solveTrhead(int *sps)
{
	startSort();
	for (int i = 0; i < sortingVector->size() - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < sortingVector->size() - 1; j++)
		{
			lastNumberOfSteps++;
			if (sortingVector->at(j) > sortingVector->at(j + 1))
			{
				swap(sortingVector, j, j + 1);
				swapped = true;
			}
			if (*sps > 0)
			{
				spsDelay(sps);
			}
			
				
		}
		if (!swapped)
			break;
	}
	
	finishSort();

}
