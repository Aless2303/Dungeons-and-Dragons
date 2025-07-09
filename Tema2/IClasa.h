#pragma once


#include"Exceptie.h"
#include<random>

typedef enum clasa_nume {
	EROARE_CLASA,
	FIGHTER,
	SORCERER,
	WARRIOR,
	NINJA,
};

class Atribute;
class IClasa
{
public:
	virtual clasa_nume getClasa() = 0;
	virtual int skill1(Atribute atr) = 0;
	virtual int skill2(Atribute atr) = 0;
};



std::ostream& operator<<(std::ostream& os, const clasa_nume& clasa);
