#include "AlgorithmMaster.h"


AlgorithmMaster::AlgorithmMaster(std::vector<int>* _sortingVector)
{
	sortingVector = _sortingVector;
}


void AlgorithmMaster::swap(std::vector<int>* sortingVector, unsigned int firstIndex, unsigned int secondIndex)
{
	int varAux = sortingVector->at(firstIndex);
	sortingVector->at(firstIndex) = sortingVector->at(secondIndex);
	sortingVector->at(secondIndex) = varAux;

}

void AlgorithmMaster::spsDelay(int* sps)
{
	std::chrono::system_clock::time_point a = std::chrono::system_clock::now();

	while (true)
	{
		std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

        std::chrono::duration<double, std::deca> deltaTime = b-a;
		double delta = deltaTime.count();
		if (delta >= 1 / ((float)*sps * 10))
			return;
	}
}