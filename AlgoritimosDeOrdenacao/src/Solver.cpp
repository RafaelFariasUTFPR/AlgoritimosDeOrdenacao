#include "Solver.h"

Solver::Solver(Global &_global) : bubbleSort(&sortingVector) , quickSort(&sortingVector), countingSort(&sortingVector)
{
	global = &_global;

	bubbleSort.sps = &targetSps;
	quickSort.sps = &targetSps;
	countingSort.sps = &targetSps;
	
}

void Solver::generateVector()
{
	isGenerating = true;
	std::thread(threadGenerate, &sortingVector, global, vectorSize).detach();
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

void Solver::solveCountingSort()
{
	if (!sortingVector.size())
		return;

	if (!isVisual)
	{
		global->alert("Ordenando o vetor...");

		countingSort.solve();
	}
	else
	{
		std::thread(threadSolve, &countingSort).detach();
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
	if (isGenerating)
		return;
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

void threadGenerate(std::vector<int>* sortingVector, Global* global, int vectorSize)
{
	std::cout << "Gerando vetor...\n";

	isRandomizing = true;

	sortingVector->resize(0);
	for (int i = 0; i < vectorSize; i++)
		sortingVector->push_back(i);

	isGenerating = false;

	for (unsigned int i = 0; i < 5 * vectorSize; i++)
	{
		unsigned int firstIndex = global->randomInRange(0, vectorSize - 1);
		unsigned int secondIndex = global->randomInRange(0, vectorSize - 1);

		unsigned int auxValue = sortingVector->at(firstIndex);
		sortingVector->at(firstIndex) = sortingVector->at(secondIndex);
		sortingVector->at(secondIndex) = auxValue;
	}

	isRandomizing = false;


	std::cout << "Vetor gerado!\n";
}
