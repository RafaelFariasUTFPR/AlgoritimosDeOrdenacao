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
		if (*sps <= 0)
			return;
		std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

        std::chrono::duration<long float, std::deca> deltaTime = b-a;
		deltaDecaSps = deltaTime.count();

		if (deltaDecaSps + 1 >= 1 / ((float)*sps * 10)+1)
			return;
	}
}

void AlgorithmMaster::startSort()
{
	isRunning = true;
	lastNumberOfSteps = 0;
	initialTime = std::chrono::system_clock::now();

}

void AlgorithmMaster::finishSort()
{
	endTime = std::chrono::system_clock::now();

	std::chrono::duration<double, std::milli> deltaTime = endTime - initialTime;

	lastExecutionTime = deltaTime.count();

	isRunning = false;
	std::cout << u8"Organizacao Finalizada\n";
}