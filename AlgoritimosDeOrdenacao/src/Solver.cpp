#include "Solver.h"

Solver::Solver(Global &_global)
{
	global = &_global;
	
}

void Solver::generateVector()
{
	std::cout << "Gerando vetor...\n";



	sortingVector.resize(vectorSize);
	for (int i = 0; i < vectorSize; i++)
		sortingVector.at(i) = i + 1;
	
	

	for (long int i = 0; i < 5 * vectorSize; i++)
	{
		int firstIndex = global->randomInRange(0, vectorSize);
		int secondIndex = global->randomInRange(0, vectorSize);

		int auxValue = sortingVector[firstIndex];
		sortingVector[firstIndex] = sortingVector[secondIndex];
		sortingVector[secondIndex] = auxValue;
	}



	std::cout << "Vetor gerado!\n";

}

void Solver::process()
{
	if (deltaClock.getElapsedTime().asSeconds() >= 1/ (double)targetSps || targetSps == 0)
		step();
}

void Solver::solveBubbleSort()
{
	if (!sortingVector.size())
		return;

	if (!isVisual)
	{
		global->alert("Ordenando o vetor...");

		bubbleSort.solve(&sortingVector);
		std::cout << "Passos: " << bubbleSort.numberOfSteps << std::endl;
	}
	else
		stepAlgorithm = 1;
}


void Solver::printVector()
{
	for (int i = 0; i < sortingVector.size(); i++)
	{
		std::cout << sortingVector.at(i) << std::endl;
	}
}


void Solver::step()
{
	sps = ceil(1 / deltaClock.getElapsedTime().asSeconds());
	deltaClock.restart();

	switch (stepAlgorithm)
	{
	case 1:
		//global->alert("Ordenando o vetor...");

		if (bubbleSort.solveStep(&sortingVector))
		{
			stepAlgorithm = 0;
			std::cout << "Passos: " << bubbleSort.numberOfSteps << std::endl;

		}
		stepAlgorithm = 0;
		break;

	default:
		break;
	}

}

void Solver::showVector()
{

	long double vectorShowSize = screenWidth / sortingVector.size();
	std::vector<float> showVector;
	for (int i = 0; i < screenWidth; i++)
	{
		int mappedIndex = floor((i) / ((double)screenWidth) * (sortingVector.size() - 1));

		int value = sortingVector.at(mappedIndex);
		float mappedValue = ((double)value) / (sortingVector.size()) * (WINDOW_HEIGHT);
		showVector.push_back(mappedValue);
	}


	sf::VertexArray linesArray;
	linesArray.setPrimitiveType(sf::LinesStrip);
	for (int i = 0; i < showVector.size(); i++)
	{
		linesArray.append(sf::Vertex(sf::Vector2f(i, WINDOW_HEIGHT)));
		linesArray.append(sf::Vertex(sf::Vector2f(i, WINDOW_HEIGHT - showVector.at(i))));

	}
	global->window.draw(linesArray);
}