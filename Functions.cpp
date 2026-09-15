#include "Functions.h"
#include <random>

std::random_device seed;
std::mt19937 rndEngine(seed());

int GetRndInt()
{
	std::uniform_int_distribution<int> rndDist(1, 6);
	return rndDist(rndEngine);
}