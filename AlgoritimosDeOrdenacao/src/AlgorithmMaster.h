#pragma once

#include <vector>

#include "Global.h"

class AlgorithmMaster
{
public:
	AlgorithmMaster(Global &_global);

	// Retorna true se tiver organaizado
	bool bubbleSortStep(std::vector<int>* _sortingVector);


	void bubbleSort(std::vector<int>* _sortingVector);

	unsigned long int numberOfSteps = 0;

	Global* global;

private:
	void swap(std::vector<int>* sortingVector, unsigned int firstIndex, unsigned int secondIndex);




};

