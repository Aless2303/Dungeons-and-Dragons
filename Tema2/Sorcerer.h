#pragma once

#include"CAClasa.h"



class Sorcerer : public CAClasa
{
public:
	Sorcerer();

	int skill1(Atribute atr) override;
	int skill2(Atribute atr) override;
};

