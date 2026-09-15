#pragma once
#include <string>
#include <iostream>

enum class Games
{
	DiceGame,
	OddEven,
	DiceBaccarat,
	None
};

struct Statistics
{
	int GameStatsBet[5]{ 0 };
	int GameStatsWinning[5]{ 0 };
	Games GameId[5]{ Games::None, Games::None, Games::None, Games::None, Games::None };
};