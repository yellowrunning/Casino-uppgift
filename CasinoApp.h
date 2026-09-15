#pragma once
#include <iostream>
#include <random>
#include "Functions.h"


void Introduction()
{
	std::cout << "Hej, v\x84lkommen till Scamkasino!\n";
	std::cout << "1. Gissa numret\n";
	std::cout << "2. Udda eller j\x84mmt\n";
	std::cout << "3. T\x84rnings baccarat\n";
	std::cout << "4. Statistik\n";
	std::cout << "5. St\x84ng ner spelet\n\n";
	std::cout << "Kontobalans " << globalMoney << "kr\n\n";
}