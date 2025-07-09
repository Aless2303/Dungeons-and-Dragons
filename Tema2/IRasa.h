#pragma once

#include"Exceptie.h"
#include<random>


typedef enum rasa_nume {
	EROARE_RASA,
	ORC,
	ELF,
	HUMAN,
	GOBLIN,
};


class Atribute;
class IRasa
{
public:
	virtual int skill1(Atribute atr)=0;
	virtual int skill2(Atribute atr)=0;
	virtual rasa_nume getRasa() = 0;
	
};

std::ostream& operator<<(std::ostream& os, const rasa_nume& rasa);
