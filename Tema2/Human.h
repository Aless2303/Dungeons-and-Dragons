#pragma once

#include"CARasa.h"


class Human : public CARasa
{
public:
	Human();


	int skill1(Atribute atr) override;
	int skill2(Atribute atr) override;
};

