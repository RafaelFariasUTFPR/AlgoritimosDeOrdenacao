#include "Global.h"

bool isRunning = false;
float lastExecutionTime = 0.0;
unsigned long int lastNumberOfSteps = 0;
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