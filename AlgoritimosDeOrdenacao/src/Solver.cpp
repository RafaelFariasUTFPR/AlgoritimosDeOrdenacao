#include "Solver.h"

Solver::Solver(Global &_global) : bubbleSort(&sortingVector) , quickSort(&sortingVector)
{
	global = &_global;

	bubbleSort.sps = &targetSps;
	quickSort.sps = &targetSps;
	
}

void Solver::generateVector()
{
	std::cout << "Gerando vetor...\n";



	sortingVector.resize(vectorSize);
	for (int i = 0; i < vectorSize; i++)
		sortingVector.at(i) = i + 1;
	
	

	for (long int i = 0; i < 5 * vectorSize; i++)
	{
		int firstIndex = global->randomInRange(0, vectorSize-1);
		int secondIndex = global->randomInRange(0, vectorSize-1);

		int auxValue = sortingVector[firstIndex];
		sortingVector[firstIndex] = sortingVector[secondIndex];
		sortingVector[secondIndex] = auxValue;
	}



	std::cout << "Vetor gerado!\n";

}

void Solver::process()
{
	if (deltaClock.getElapsedTime().asSeconds() >= 0.1)
		step();


}

void Solver::solveBubbleSort()
{
	if (!sortingVector.size())
		return;

	if (!isVisual)
	{
		global->alert("Ordenando o vetor...");

		bubbleSort.solve();
	}
	else
	{
		std::thread(threadSolve, &bubbleSort).detach();
	}
}

void Solver::solveQuickSort()
{
	if (!sortingVector.size())
		return;

	if (!isVisual)
	{
		global->alert("Ordenando o vetor...");

		quickSort.solve();
	}
	else
	{
		std::thread(threadSolve, &quickSort).detach();
	}
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
	if(deltaDecaSps != 0)
		sps = (int)(1 / (deltaDecaSps * 10));
	deltaClock.restart();


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




void threadSolve(AlgorithmMaster* algorithm)
{
	algorithm->solveTrhead();
}