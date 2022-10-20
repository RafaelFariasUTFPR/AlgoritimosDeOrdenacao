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
    std::vector <int> sortingVectorCopy = *sortingVector;

    std::vector <int> count(sortingVectorCopy.size(), 0);

    std::fill(sortingVector->begin(), sortingVector->end(), 0);

    for (int i = 0; i < sortingVectorCopy.size(); i++)
    {
        sortingVector->at(sortingVectorCopy.at(i))+= (WINDOW_HEIGHT / 2);
        count.at(sortingVectorCopy.at(i))++;
        spsDelay();
        lastNumberOfSteps++;
    }
    for (int i = 2; i < sortingVectorCopy.size(); i++)
    {
        sortingVector->at(i) = (sortingVector->at(i)/(WINDOW_HEIGHT/2)) + (sortingVector->at(i - 1) / (WINDOW_HEIGHT / 2));
        count[i] = count[i] + count[i - 1];
        spsDelay();
        lastNumberOfSteps++;
    }

    std::vector <int> output(sortingVectorCopy.size());

    for (int i = count.size() - 1; i >= 0; i--)
    {
        sortingVector->at(count[sortingVectorCopy.at(i)]) = sortingVectorCopy.at(i);
        output[count[sortingVectorCopy.at(i)]] = sortingVectorCopy.at(i);
        count[sortingVectorCopy.at(i)]--;
        spsDelay();
        lastNumberOfSteps++;
    }

    for (int i = 0; i < sortingVector->size(); i++)
    {
        sortingVector->at(i) = output.at(i);
    }
    finishSort();
}