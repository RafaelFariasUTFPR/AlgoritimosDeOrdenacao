#include "BubbleSort.h"


BubbleSort::BubbleSort(std::vector<int>* _sortingVector) : AlgorithmMaster(_sortingVector)
{

}



void BubbleSort::solve()
{
	startSort();
	
	if (sortingVector->size() <= 1)
	{
		finishSort();
		return;
	}

	for (int i = 0; i < sortingVector->size() - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < sortingVector->size() - i - 1; j++)
		{
			lastNumberOfSteps++;
			if (sortingVector->at(j) > sortingVector->at(j + 1))
			{
				swap(j, j + 1);
				swapped = true;
				
			}
		}
		if (!swapped)
			break;
	}
	finishSort();

}
void BubbleSort::solveTrhead()
{
	startSort();
	
	if (sortingVector->size() <= 1)
	{
		finishSort();
		return;
	}


	for (int i = 0; i < sortingVector->size() - 1; i++)
	{
		bool swapped = false;
		for (int j = 0; j < sortingVector->size() - i - 1; j++)
		{
			lastNumberOfSteps++;
			if (sortingVector->at(j) > sortingVector->at(j + 1))
			{
				swap(j, j + 1);
				swapped = true;
			}

			spsDelay();
		
			
				
		}
		if (!swapped)
			break;
	}
	
	finishSort();

}
