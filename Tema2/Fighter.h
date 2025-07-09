#pragma once

#include"CAClasa.h"


class Fighter : public CAClasa
{
public:
	Fighter();


	int skill1(Atribute atr) override;
	int skill2(Atribute atr) override;
};

