#include "Functions.h"
#include <iostream>
#include <random>

void DiceGuide() //testing test
{
	std::cout << "\nbeh\x94ver du instruktioner?\ny(Ja)/n(Nej)\n\n\n\n\nL (G\x86 tillbaka till huvudmeny, du kommer inte att tappa pengar)\n\n";
	while (true)
	{
		std::cin >> choice;
		system("cls");

		if (std::cin.fail() || std::cin.rdbuf()->in_avail() > 1 || (choice != 'y' && choice != 'n' && choice != 'l'))
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Anv\x84nd bara y(Ja)/n(Nej)\n\n\n\n\nL (G\x86 tillbaka till huvudmeny, du kommer inte att tappa pengar)\n\n";
			continue;
		}
		else if (choice == 'y')
		{
			std::cout << "Spelet g\x86r ut p\x86 att du kommer sl\x86 tv\x86 stycken sexsiffringa t\x84rningar,\ndu ska gissa p\x86 ett tal mellan 2 till 12.\nOm din gissning \x84r lika med summan av de tv\x86 t\x84rningarna vinner du 2x av de satsade pengarna!\nSkriv in ditt nummer: ";
			break;
		}
		else if (choice == 'n')
		{
			std::cout << "Skriv in ditt nummer: ";
			break;
		}
		else if (choice == 'l')
		{
			MainMenu();
			break;
		}
	}
}

void GuessDice()
{
	while (true)
	{
		std::cin >> globalGuess;
		system("cls");
		if (globalGuess >= 2 && globalGuess <= 12)
		{
			break;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			std::cout << "Skriv bara ett nummer mellan 2-12 ";
		}
	}
}

void Dice()
{
	globalNumberA = GetRndInt();
	std::cout << "tryck p\x86 enter f\x94r att sl\x86 t\x84rning ";

	Enter();
	system("cls");

	std::cout << "du fick " << globalNumberA << '\n' << "tryck p\x86 p\x86 enter f\x94r sl\x86 din andra t\x84rning ";

	Enter();
	system("cls");

	globalNumberB = GetRndInt();
	std::cout << "du fick " << globalNumberB << '\n' << "tryck p\x86 p\x86 enter f\x94r resultat ";

	Enter();
	system("cls");
}

void MoneyDice()
{
	if (globalDiceTracker > 0)
	{
		std::cout << "Du har tj\x84rnat " << globalDiceTracker << "kr!!!\n\ntryck p\x86 enter f\x94r att forts\x84tta\n";
		Enter();
	}
	else if (globalDiceTracker < 0)
	{
		std::cout << "Du har tappat " << globalDiceTracker << "kr\n\ntryck p\x86 enter f\x94r att forts\x84tta\n";
		Enter();
	}
	else
	{
		std::cout << "Du har inte tappat eller tj\x84rnat något\n\ntryck p\x86 enter f\x94r att forts\x84tta\n";
		Enter();
	}
}

void WinConditionDice()
{
	std::cout << globalNumberA << " plus " << globalNumberB << " blir " << globalNumberA + globalNumberB;
	if (globalGuess == globalNumberA + globalNumberB)
	{
		std::cout << "\ndu vann!\n";
		Win();
		AddStats(DiceGame, globalBet, +globalBet);
		globalDiceTracker += globalBet;
		std::cout << "Kontobalans: " << globalMoney << "kr\n";
	}
	else
	{
		std::cout << "\ndu f\x94rlorade.\n";
		Lose();
		AddStats(DiceGame, globalBet, -globalBet);
		globalDiceTracker -= globalBet;
		std::cout << "Kontobalans: " << globalMoney << "kr\n";
	}
	std::cout << "\nvill du k\x94ra igen?";
	std::cout << "\nJa(y)\n";
	std::cout << "Nej(n)\n";
}

void CheckTooMuchDice()
{
	if (globalDiceTracker > 500)
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