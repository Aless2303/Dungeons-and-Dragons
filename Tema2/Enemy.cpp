#include "Enemy.h"
#include<set>

IRasa* generare_random_rasa()
{
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));
	//int aleatoriu = std::rand() % 5;

	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, 3);
	std::size_t aleatoriu = distribution(generator);

	switch (aleatoriu)
	{
	case 0:
		return new Elf();
	case 1:
		return new Goblin();
	case 2:
		return new Human();
	case 3:
		return new Orc();
	default:
		return nullptr;
	}

}

IClasa* generare_random_clasa()
{
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, 3);
	std::size_t aleatoriu = distribution(generator);

	switch (aleatoriu)
	{
	case 0:
		return new Fighter();
	case 1:
		return new Ninja();
	case 2:
		return new Sorcerer();
	case 3:
		return new Warrior();
	default:
		return nullptr;
	}
}

Trecut generare_random_trecut()
{
	std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<std::size_t> distribution(0, 3);
	std::size_t aleatoriu = distribution(generator);

	switch (aleatoriu)
	{
	case 0:
		return HOT;
	case 1:
		return MAGICIAN;
	case 2:
		return SOLDAT;
	case 3:
		return ACOLIT;
	default:
		return EROARE_TRECUT;
	}
}

std::set<std::string> numereUnice;

std::string generareNumarUnic() {
	static std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(1, 10000);

	std::string numarGenerat;
	do {
		numarGenerat = std::to_string(distribution(generator));
	} while (numereUnice.find(numarGenerat) != numereUnice.end());

	numereUnice.insert(numarGenerat);
	return numarGenerat;
}



Enemy::Enemy() : Personaj(generare_random_rasa(), generare_random_clasa(), generare_random_trecut(),generareNumarUnic())
{
}

Enemy::Enemy(IRasa* rasa, IClasa* clasa, Trecut trecut,std::string name) : Personaj(rasa,clasa,trecut,name)
{
}

void Enemy::prezinta_inamic()
{
	this->prezinta_personaj();
}

int Enemy::atac_random()
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, 1);

	int rasa_clasa = distribution(generator);
	int skill1_2 = distribution(generator);

	int dmg = 0;

	if (rasa_clasa == 0)
	{
		if (skill1_2 == 0)
			dmg = this->rasa_personaj->skill1(this->atribute_personaj);
		else
			dmg = this->rasa_personaj->skill2(this->atribute_personaj);
	}
	else if (rasa_clasa == 1)
	{
		if (skill1_2 == 0)
			dmg = this->clasa_personaj->skill1(this->atribute_personaj);
		else
			dmg = this->clasa_personaj->skill2(this->atribute_personaj);
	}
	return dmg;
}
