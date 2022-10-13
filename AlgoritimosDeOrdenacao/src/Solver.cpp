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
	
	for (int i = 0; i < random::randomInt(5) * vectorSize; i++)
	{
		int firstIndex = random::randomIndex(vectorSize);
		int secondIndex = random::randomIndex(vectorSize);

		int auxValue = sortingVector[firstIndex];
		sortingVector[firstIndex] = sortingVector[secondIndex];
		sortingVector[secondIndex] = auxValue;

	}
	//for (int i = 0; i < vectorSize; i++)
	{
		//std::cout << sortingVector.at(i) << std::endl;

	}

	std::cout << "Vetor gerado!\n";

}