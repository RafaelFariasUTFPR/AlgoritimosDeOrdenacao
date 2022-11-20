#include "Global.h"

bool isRunning = false;
bool isGenerating = false;
bool isRandomizing = false;


float lastExecutionTime = 0.0;
unsigned long long lastNumberOfSteps = 0;
double deltaDecaSps = 0;

void Global::alert(std::string text)
{
    message.setString(text);
    window.draw(message);
    window.display();
}

int Global::randomInRange(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(*generator);
}


std::vector <int> Global::shuffleVector(std::vector <int> sortingVector)
{
    auto rng = std::default_random_engine{ (unsigned int)deltaClock.getElapsedTime().asMicroseconds()};
    std::shuffle(std::begin(sortingVector), std::end(sortingVector), rng);
    return sortingVector;
}