#include "Human.h"
#include"Atribute.h"

Human::Human() : CARasa(HUMAN)
{
}

int Human::skill1(Atribute atr)
{
	int val_atr = atr.get_charisma();
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, 5);
	int dice = distribution(generator);


	return dice + val_atr;
}

int Human::skill2(Atribute atr)
{
	int val_atr = atr.get_charisma();
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, 5);
	int dice = distribution(generator);


	return dice + val_atr;
}
