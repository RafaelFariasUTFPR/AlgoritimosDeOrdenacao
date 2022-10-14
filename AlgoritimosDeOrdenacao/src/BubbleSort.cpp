#include "BubbleSort.h"


BubbleSort::BubbleSort(std::vector<int>* _sortingVector) : AlgorithmMaster(_sortingVector)
{

}



void BubbleSort::solve()
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
	std::cout << u8"Organizacao Finalizada\n";

}
void BubbleSort::solveTrhead(int *sps)
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
			//std::cout << sps << std::endl;
			if(*sps > 0)
				spsDelay(sps);
		}
		if (!swapped)
			break;
	}

	std::cout << u8"Organizacao Finalizada\n";
}
