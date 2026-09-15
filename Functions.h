#pragma once
#include <string>
#include <iostream>

enum Games
{
	DiceGame,
	OddEven,
	DiceBaccarat,
	None
};

inline int globalGuess, globalNumberA, globalNumberB, globalNumberC, globalNumberD, globalMoney, globalBet, globalDiceTracker, globalOddEvenTracker, globalDiceBaccaratTracker;
inline int GameStatsBets[5]{ 0 };
inline int GameStatsWinning[5]{ 0 };
inline Games globalGameId[5]{ None, None, None, None, None };

inline char choice, loop;
inline std::string globalBacaratbet;
inline std::string TranslateGameId(Games aGame);

int GetRndInt();

void Introduction();
void AddStats(Games aGame, int aBet, int aWinnings);
void CheckTooMuchDice();
void CheckTooMuchOddEven();
void CheckTooMuchDiceBaccarat();
void DiceGuide();
void OddEvenGuide();
void DiceBaccaratGuide();
void GuessDice();
void GuessOddEven();
void GuessDiceBaccarat();
void Dice();
void PlayerDice();
void DiceTwo();
void Money();
void CheckMoney();
void Win();
void Win10x();
void Lose();
void MoneyDice();
void MoneyOddEven();
void MoneyDiceBaccarat();
void WinConditionDice();
void WinConditionOddEven();
void WinConditionDiceBaccarat();
void Enter();
void Stats();
void Continue();
void MainMenu();

struct Currency
{
	int balance{};
	int currentbet{};
};