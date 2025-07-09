#pragma once

#include"CARasa.h"


class Orc : public CARasa
{
public:
	Orc();


	int skill1(Atribute atr) override;
	int skill2(Atribute atr) override;
};

