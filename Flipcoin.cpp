#include <iostream>
#include <random>
std::random_device seed;

struct Coinflip
{
	int Coin;
	std::uniform_int_distribution<int> Coin(1, 2);
};

enum class guess
{
	Coinheads,
	CoinTails
};

void WinConditionCoinFlip()
{
	if (guess = CoinHeads)
	{
		if (guess = CoinHeads)
		{
			std::cout << "du vann!";
		}
		else if (guess = CoinTails)
		{
			std::cout << "du f\x94lorade";
		}
	}
	else if (guess = CoinTails)
	{
		if (guess = CoinHeads)
		{
			std::cout << "du f\x94lorade";
		}
		else if (guess = CoinTails)
		{
			std::cout << "du vann!";
		}
	}
}