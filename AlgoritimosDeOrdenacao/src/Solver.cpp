#include "Solver.h"

Solver::Solver(Global &_global) : algorithm(*global)
{
	global = &_global;
	
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

	for (int i = 0; i < vectorSize; i++)
	{
		//std::cout << sortingVector.at(i) << std::endl;
	}

	std::cout << "Vetor gerado!\n";

}

void Solver::process()
{
	if (deltaClock.getElapsedTime().asSeconds() >= 1/ (double)targetSps || targetSps == 0)
		step();
}

void Solver::bubbleSortWhole()
{
	if (!sortingVector.size())
		return;

	algorithm.bubbleSort(&sortingVector);
	for (int i = 0; i < vectorSize; i++)
	{
		//std::cout << sortingVector.at(i) << std::endl;
	}
	std::cout << "Passos: " << algorithm.numberOfSteps;

}


void Solver::step()
{
	sps = ceil(1 / deltaClock.getElapsedTime().asSeconds());
	deltaClock.restart();





}