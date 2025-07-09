#include "Sorcerer.h"
#include"Atribute.h"


Sorcerer::Sorcerer() : CAClasa(SORCERER)
{
}

int Sorcerer::skill1(Atribute atr)
{
	int val_atr = atr.get_intelligence();
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, 5);
	int dice = distribution(generator);


	return dice + val_atr;
}

int Sorcerer::skill2(Atribute atr)
{
	int val_atr = atr.get_wisdom();
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, 5);
	int dice = distribution(generator);


	return dice + val_atr;
}
