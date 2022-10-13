#pragma once
#include <random>
#include <stdlib.h>
#include <time.h>

namespace random
{
	// Lento
	int randomIntInRange(int min, int max);

	// Gera um numero inteiro entre 1 e o max
	int randomInt(int max);

	// Gera um numero inteiro entre 0 e max-1
	int randomIndex(int max);
}

