#pragma once


#include"Personaj.h"
#include <ctime>
#include <cstdlib>
#include <random>


class Enemy : public Personaj
{

public:
	Enemy();
	Enemy(IRasa* rasa, IClasa* clasa, Trecut trecut,std::string name);

	void prezinta_inamic();
	int atac_random();

};

