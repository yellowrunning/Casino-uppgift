#include <iostream>
#include <random>
#include "Functions.h"


void Continue()
{
	while (true)
	{
		std::cin >> loop;
		system("cls");

		if (std::cin.fail() || std::cin.rdbuf()->in_avail() > 1 || (choice != 'y' && choice != 'n'))
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Anv\x84nd bara y(Ja)/n(Nej)";
			std::cout << "\n\nKontobalans " << globalMoney << "kr\n\n";
		}
		else if (loop == 'y')
		{
			MainMenu();
			break;
		}
		else if (loop == 'n')
		{
			std::cout << "spelet st\x84ngs ner";
			std::cout << "\n\nKontobalans " << globalMoney << "kr\n\n";
			break;
		}
	}
}

void CheckMoney()
{
	if (globalMoney < 1)
	{
		system("cls");
		std::cout << "Kontobalans " << globalMoney << "kr\n";
		std::cout << "Inga pengar kvar du blir utskickad\ntryck p\x86 enter f\x94r att forts\x84tta ";
		Enter();
		exit(0);
	}
}

void Money()
{
	while (true)
	{
		system("cls");
		std::cout << "Hur mycket pengar vill du satsa\n";
		std::cout << "Kontobalans " << globalMoney << "kr\n";
		std::cin >> globalBet;

		if (std::cin.fail() || globalBet > globalMoney || globalBet <= 0)
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "\nSatsa ett giltigt v\x84rde\n";
			std::cout << "tryck p\x86 enter f\x94r att forts\x84tta ";
			Enter();
			continue;
		}
		else if (globalBet == globalMoney)
		{
			std::cout << "ALL IN!!!!";
			return;
		}
		else
		{
			return;
		}
	}
}

void AddStats(Games aGame, int aBet, int AWinnings)
{
	for (int i = 4; i > 0; i--)
	{
		globalGameId[i] = globalGameId[i - 1];
		GameStatsBets[i] = GameStatsBets[i - 1];
		GameStatsWinning[i] = GameStatsWinning[i - 1];
	}
	globalGameId[0] = aGame;
	GameStatsBets[0] = aBet;
	GameStatsWinning[0] = AWinnings;
}

std::string TranslateGameId(Games aGame)
{
	switch (aGame)
	{
		case DiceGame:
		{
			return "DiceGame    ";
		}
		case OddEven:
		{
			return "OddEven     ";
		}
		case DiceBaccarat:
		{
			return "DiceBaccarat";
		}
		default:
			return "none";
	}
}

void Stats()
{
	std::cout << "H\x84r \x84r statistiken p\x86 dina fem senaste spel\n\n   Namn | Satsning | Resultat\n\n";
	for (int i = 0; i < 5; ++i)
	{
		if (globalGameId[i] != 3)
		{
			std::cout << TranslateGameId(globalGameId[i]) << " | " << GameStatsBets[i] << " | " << GameStatsWinning[i];
			std::cout << '\n';
		}
	}
	std::cout << "\nKontobalans " << globalMoney << "kr\n\n";
	std::cout << "\nTryck p\x86 enter f\x94r att forts\x84tta\n\n";
	Enter();
	system("cls");
	MainMenu();
}

void Win()
{
	globalMoney += globalBet;
}

void Win10x()
{
	globalMoney += globalBet * 9;
}

void Lose()
{
	globalMoney -= globalBet;
}

void Enter()
{
	if (std::cin.rdbuf()->in_avail() > 0)
	{
		std::cin.ignore(10000,'\n');
	}
	std::cin.get();
}

void PlayerDice()
{
	globalNumberA = GetRndInt();
	std::cout << "tryck p\x86 enter f\x94r att sl\x86 t\x84rning ";

	Enter();
	system("cls");

	std::cout << "Player fick " << globalNumberA << '\n' << "tryck p\x86 p\x86 enter f\x94r sl\x86 players andra t\x84rning ";

	Enter();
	system("cls");

	globalNumberB = GetRndInt();
	std::cout << "Player fick " << globalNumberB << '\n' << "tryck p\x86 p\x86 enter f\x94r resultat ";
	Enter();
	system("cls");
}

void DiceTwo()
{
	globalNumberC = GetRndInt();
	std::cout << "tryck p\x86 enter f\x94r att sl\x86 t\x84rning ";

	Enter();
	system("cls");

	std::cout << "Banken fick " << globalNumberC << '\n' << "tryck p\x86 p\x86 enter f\x94r sl\x86 den andra t\x84rningen ";

	Enter();
	system("cls");

	globalNumberD = GetRndInt();
	std::cout << "Banken fick " << globalNumberD << '\n' << "tryck p\x86 p\x86 enter f\x94r resultat ";

	Enter();
	system("cls");
}

int main()
{
	globalMoney = 1000;
	MainMenu();
}