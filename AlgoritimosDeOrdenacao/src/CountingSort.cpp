#include "CountingSort.h"
CountingSort::CountingSort(std::vector<int>* _sortingVector) : AlgorithmMaster(_sortingVector)
{

}

void CountingSort::solve()
{
    startSort();
    
    std::vector <int> count(sortingVector->size(), 0);

    for (int i = 0; i < sortingVector->size(); i++)
    {
        count.at(sortingVector->at(i))++;
        lastNumberOfSteps++;
    }
    for (int i = 2; i < sortingVector->size(); i++)
    {
        count[i] = count[i] + count[i - 1];
        lastNumberOfSteps++;
    }

    std::vector <int> output(sortingVector->size());

    for (int i = count.size()-1; i >= 0; i--)
    {
        output[count[sortingVector->at(i)]] = sortingVector->at(i);
        count[sortingVector->at(i)]--;
        lastNumberOfSteps++;
    }

    for (int i = 0; i < sortingVector->size(); i++)
    {
        sortingVector->at(i) = output.at(i);
        lastNumberOfSteps++;
    }
    finishSort();
}

void CountingSort::solveTrhead()
{
    startSort();

    std::vector <int> count(sortingVector->size(), 0);

    for (int i = 0; i < sortingVector->size(); i++)
    {
        count.at(sortingVector->at(i))++;
        spsDelay();
        lastNumberOfSteps++;
    }
    for (int i = 2; i < sortingVector->size(); i++)
    {
        count[i] = count[i] + count[i - 1];
        spsDelay();
        lastNumberOfSteps++;
    }

    std::vector <int> output(sortingVector->size());

    for (int i = count.size() - 1; i >= 0; i--)
    {
        output[count[sortingVector->at(i)]] = sortingVector->at(i);
        count[sortingVector->at(i)]--;
        spsDelay();
        lastNumberOfSteps++;
    }

    for (int i = 0; i < sortingVector->size(); i++)
    {
        sortingVector->at(i) = output.at(i);
        spsDelay();
        lastNumberOfSteps++;
    }
    finishSort();
}