#include "Functions.h"
#include <iostream>
#include <random>

void OddEvenGuide()
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
			std::cout << "Spelet g\x86r ut p\x86 att du kommer sl\x86 tv\x86 stycken sexsiffringa t\x84rningar\nDu ska gissa p\x86 udda eller j\x84mnt.";
			std::cout << "\nOm de tv\x86 t\x84rningarna sl\x86r det du gissade p\x86 vinner du 2x de pengarna du satsade!\nOm t\x84rningarna sl\x86r udda och j\x84mnt f\x94rlorar du alltid.";
			std::cout << "\nGissa:\nUdda (1)\nJ\x84mnt (2)\n";
			break;
		}
		else if (choice == 'n')
		{
			std::cout << "Gissa:\nUdda (1)\nJ\x84mnt (2)\n";
			break;
		}
		else if (choice == 'l')
		{
			MainMenu();
			break;
		}
	}
}

void GuessOddEven()
{
	while (true)
	{
		std::cin >> globalGuess;
		system("cls");

		if (globalGuess != 1 && globalGuess != 2 || std::cin.rdbuf()->in_avail() > 1)
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Skriv bara Udda (1) eller J\x84mnt (2)\n";
			continue;
		}
		else
		{
			break;
		}
	}
}

void WinConditionOddEven()
{
	std::cout << "du fick " << globalNumberA << " och " << globalNumberB;
	if (globalNumberA % 2 == 1 && globalNumberB % 2 == 1)
	{
		if (globalGuess == 1)
		{
			std::cout << "\ndu vann!";
			Win();
			AddStats(OddEven, globalBet, +globalBet);
			globalOddEvenTracker += globalBet;
			std::cout << "Kontobalans: " << globalMoney << "kr\n";
		}
		else
		{
			std::cout << "\ndu f\x94rlorade.";
			Lose();
			AddStats(OddEven, globalBet, -globalBet);
			globalOddEvenTracker -= globalBet;
			std::cout << "Kontobalans: " << globalMoney << "kr\n";
		}
	}
	else if (globalNumberA % 2 == 0 && globalNumberB % 2 == 0)
	{
		if (globalGuess == 2)
		{
			std::cout << "\ndu vann!";
			Win();
			AddStats(OddEven, globalBet, +globalBet);
			globalOddEvenTracker += globalBet;
			std::cout << "Kontobalans: " << globalMoney << "kr\n";
		}
		else
		{
			std::cout << "\ndu f\x94rlorade.";
			Lose();
			AddStats(OddEven, globalBet, -globalBet);
			globalOddEvenTracker -= globalBet;
			std::cout << "Kontobalans: " << globalMoney << "kr\n";
		}
	}
	else
	{
		std::cout << "\ndu f\x94rlorade.";
		Lose();
		AddStats(OddEven, globalBet, -globalBet);
		globalOddEvenTracker -= globalBet;
		std::cout << "Kontobalans: " << globalMoney << "kr\n";
	}
	std::cout << "\nvill du k\x94ra igen?";
	std::cout << "\nJa(y)\n";
	std::cout << "Nej(n)\n";
}

void MoneyOddEven()
{
	if (globalOddEvenTracker > 0)
	{
		std::cout << "Du har tj\x84rnat " << globalOddEvenTracker << "kr!!!\n\ntryck p\x86 enter f\x94r att forts\x84tta\n";
		Enter();
	}
	else if (globalOddEvenTracker < 0)
	{
		std::cout << "Du har tappat " << globalOddEvenTracker << "kr\n\ntryck p\x86 enter f\x94r att forts\x84tta\n";
		Enter();
	}
	else
	{
		std::cout << "Du har inte tappat eller tj\x84rnat något\n\ntryck p\x86 enter f\x94r att forts\x84tta\n";
		Enter();
	}
}

void CheckTooMuchOddEven()
{
	if (globalOddEvenTracker > 500)
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