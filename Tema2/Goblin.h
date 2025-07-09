#pragma once

#include"CARasa.h"


class Goblin : public CARasa
{
public:
	Goblin();


	int skill1(Atribute atr) override;
	int skill2(Atribute atr) override;


};

