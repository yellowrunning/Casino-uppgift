#include "Functions.h"
#include <iostream>
#include <random>

void DiceBaccaratGuide()
{
	std::cout << "\nbeh\x94ver du instruktioner?\ny(Ja)/n(Nej)\n\n\n\n\nL (G\x86 tillbaka till huvudmeny, du kommer inte att tappa pengar)\n\n";
	while (true)
	{
		std::cin >> choice;
		system("cls");

		if (std::cin.fail() || std::cin.rdbuf()->in_avail() > 1)
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Anv\x84nd bara y(Ja)/n(Nej)\n\n\n\n\nL (G\x86 tillbaka till huvudmeny, du kommer inte att tappa pengar)\n\n";
			continue;
		}
		else if (choice == 'y')
		{
			std::cout << "Det kommer att finnas tv\x86 spelare: Player // Banken";
			std::cout << "\nDu kan satsa p\x86 Player // Banken // Lika";
			std::cout << "\nDen som f\x86r h\x94gst sammanlagda nummer vinner!\nOm det blir lika vinner du bara om du satsade p\x86 lika";
			std::cout << "\n\nUtbetalning: 2x om du satsade p\x86 en spelare // 10x p\x86 lika!!!\n";
			std::cout << "1. Player\n2. Banken\n3. Lika\n";
			break;
		}
		else if (choice == 'n')
		{
			std::cout << "Satsa pengar:\n1. Player (2x Utbetalning)\n2. Banken (2x Utbetalning)\n3. Lika (10x Utbetalning)\n\n";
			break;
		}
		else if (choice == 'l')
		{
			MainMenu();
			break;
		}
	}
}

void GuessDiceBaccarat()
{
	while (true)
	{
		std::cin >> globalGuess;
		system("cls");

		if (globalGuess != 1 && globalGuess != 2 && globalGuess != 3 || std::cin.rdbuf()->in_avail() > 1)
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Du kan bara gissa p\x86:\n(1) Player\n(2) Banken\n(3) Lika\n";
			continue;
		}
		else
		{
			switch (globalGuess)
			{
			case 1:
			{
				globalBacaratbet = "Player";
				return;
			}
			case 2:
			{
				globalBacaratbet = "Banken";
				return;
			}
			case 3:
			{
				globalBacaratbet = "Lika";
				return;
			}
			default:
			{
				globalBacaratbet = "Error";
				return;
			}
			}
		}
	}
}

void CheckTooMuchDiceBaccarat()
{
	if (globalDiceBaccaratTracker > 500)
	{
		system("cls");
		std::cout << "Du har vunnit f\x94r mycket gtfo\n\ntryck p\x86 enter f\x94r att forts\x84tta\n";
		Enter();
		system("cls");
		MainMenu();
	}
	else
	{
		return;
	}
}

void MoneyDiceBaccarat()
{
	if (globalDiceBaccaratTracker > 0)
	{
		std::cout << "Du har tj\x84rnat " << globalDiceBaccaratTracker << "kr!!!\n\ntryck p\x86 enter f\x94r att forts\x84tta\n";
		Enter();
	}
	else if (globalDiceBaccaratTracker < 0)
	{
		std::cout << "Du har tappat " << globalDiceBaccaratTracker << "kr\n\ntryck p\x86 enter f\x94r att forts\x84tta\n";
		Enter();
	}
	else
	{
		std::cout << "Du har inte tappat eller tj\x84rnat något\n\ntryck p\x86 enter f\x94r att forts\x84tta\n";
		Enter();
	}
}

void WinConditionDiceBaccarat()
{
	std::cout << "Player fick " << globalNumberA << " + " << globalNumberB << " = " << globalNumberA + globalNumberB << "\n";
	std::cout << "Banken fick " << globalNumberC << " + " << globalNumberD << " = " << globalNumberC + globalNumberD << "\n";
	if (globalNumberA + globalNumberB > globalNumberC + globalNumberD)
	{
		std::cout << "\nPlayer vann!\n";
		if (globalGuess == 1)
		{
			std::cout << "Du satsade p\x86 " << globalBacaratbet << "\n\nDu vann!\n";
			Win();
			AddStats(DiceBaccarat, globalBet, +globalBet);
			globalDiceBaccaratTracker += globalBet;
			std::cout << "Kontobalans: " << globalMoney << "kr\n";
		}
		else if (globalGuess != 1)
		{
			std::cout << "Du satsade p\x86 " << globalBacaratbet << "\n\nDu f\x94rlorade\n";
			Lose();
			AddStats(DiceBaccarat, globalBet, -globalBet);
			globalDiceBaccaratTracker -= globalBet;
			std::cout << "Kontobalans: " << globalMoney << "kr\n";
		}
	}
	else if (globalNumberA + globalNumberB < globalNumberC + globalNumberD)
	{
		std::cout << "\nBanken vann!\n";
		if (globalGuess == 2)
		{
			std::cout << "Du satsade p\x86 " << globalBacaratbet << "\n\nDu vann!\n";
			Win();
			AddStats(DiceBaccarat, globalBet, +globalBet);
			globalDiceBaccaratTracker += globalBet;
			std::cout << "Kontobalans: " << globalMoney << "kr\n";
		}
		else if (globalGuess != 2)
		{
			std::cout << "Du satsade p\x86 " << globalBacaratbet << "\n\nDu f\x94rlorade\n";
			Lose();
			AddStats(DiceBaccarat, globalBet, -globalBet);
			globalDiceBaccaratTracker -= globalBet;
			std::cout << "Kontobalans: " << globalMoney << "kr\n";
		}
	}
	else if (globalNumberA + globalNumberB == globalNumberC + globalNumberD)
	{
		std::cout << "\nDet blev lika!\n";
		if (globalGuess == 3)
		{
			std::cout << "Du satsade p\x86 " << globalBacaratbet << "\n\nDu vann!\n";
			Win10x();
			AddStats(DiceBaccarat, globalBet, globalBet * 9);
			globalDiceBaccaratTracker += globalBet * 9;
			std::cout << "Kontobalans: " << globalMoney << "kr\n";
		}
		else if (globalGuess != 3)
		{
			std::cout << "Du satsade p\x86 " << globalBacaratbet << "\n\nDu f\x94rlorade\n";
			Lose();
			AddStats(DiceBaccarat, globalBet, -globalBet);
			globalDiceBaccaratTracker -= globalBet;
			std::cout << "Kontobalans: " << globalMoney << "kr\n";
		}
	}
	std::cout << "\nvill du k\x94ra igen?";
	std::cout << "\nJa(y)\n";
	std::cout << "Nej(n)\n";
}