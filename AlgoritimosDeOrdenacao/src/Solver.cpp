#include "Solver.h"

Solver::Solver()
{

}

void Solver::generateVector()
{
	std::cout << "Gerando vetor...\n";
	sortingVector.resize(vectorSize);
	for (int i = 0; i < vectorSize; i++)
		sortingVector.at(i) = i;

	for (int i = 0; i < random::randomIntInRange(vectorSize, vectorSize * 5); i++)
	{
		int firstIndex = random::randomIntInRange(0, vectorSize - 1);
		int secondIndex = random::randomIntInRange(0, vectorSize - 1);

		int auxValue = sortingVector[firstIndex];
		sortingVector[firstIndex] = sortingVector[secondIndex];
		sortingVector[secondIndex] = auxValue;

	}

	for (int i = 0; i < vectorSize; i++)
	{
		//std::cout << sortingVector.at(i) << std::endl;

	}

	std::cout << "Vetor gerado!\n";

}