#include "Functions.h"
#include <iostream>
#include <random>

void MainMenu()
{
	int choose;

	Introduction();
	std::cin >> choose;
	system("cls");
	if (std::cin.fail() || choose < 1 || choose > 5 || std::cin.rdbuf()->in_avail() > 1)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "anv\x84nd bara 1-5\ntryck p\x86 enter f\x94r att forts\x84tta";
		Enter();
		system("cls");
		MainMenu();
	}
	switch (choose)
	{
	case 1:
		MoneyDice();
		CheckTooMuchDice();
		Money();
		DiceGuide();
		GuessDice();
		Dice();
		WinConditionDice();
		CheckMoney();
		Continue();
		break;
	case 2:
		MoneyOddEven();
		CheckTooMuchOddEven();
		Money();
		OddEvenGuide();
		GuessOddEven();
		Dice();
		WinConditionOddEven();
		CheckMoney();
		Continue();
		break;
	case 3:
		MoneyDiceBaccarat();
		CheckTooMuchDiceBaccarat();
		Money();
		DiceBaccaratGuide();
		GuessDiceBaccarat();
		PlayerDice();
		DiceTwo();
		WinConditionDiceBaccarat();
		CheckMoney();
		Continue();
		break;
	case 4:
		Stats();
		break;
	case 5:
		std::cout << "spelet st\x84ngs ner";
		std::cout << "\n\nKontobalans " << globalMoney << "kr\n\n";
		exit(0);
		return;
	}
}