#pragma once

#include"CAClasa.h"


class Ninja : public CAClasa
{
public:
	Ninja();


	int skill1(Atribute atr) override;
	int skill2(Atribute atr) override;
};

