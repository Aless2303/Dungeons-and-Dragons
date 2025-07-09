#include "Goblin.h"
#include"Atribute.h"

Goblin::Goblin() : CARasa(GOBLIN)
{
}

int Goblin::skill1(Atribute atr)
{
	int val_atr = atr.get_strenght();
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, 5);
	int dice = distribution(generator);


	return dice + val_atr;
}

int Goblin::skill2(Atribute atr)
{
	int val_atr = atr.get_dexterity();
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, 5);
	int dice = distribution(generator);


	return dice + val_atr;
}
