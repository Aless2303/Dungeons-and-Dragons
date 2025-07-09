#pragma once

#include"CAClasa.h"


class Warrior : public CAClasa
{
public:
	Warrior();


	int skill1(Atribute atr) override;
	int skill2(Atribute atr) override;
};

