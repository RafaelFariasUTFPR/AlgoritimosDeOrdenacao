#pragma once

#include <vector>

#include "Global.h"

class AlgorithmMaster
{
public:
	AlgorithmMaster();

	virtual void solve(std::vector<int>* sortingVector){}
	virtual bool solveStep(std::vector<int>* sortingVector) { return true; }


	unsigned long int numberOfSteps = 0;

	void swap(std::vector<int>* sortingVector, unsigned int firstIndex, unsigned int secondIndex);

protected:

	bool firstIt = true;


};

