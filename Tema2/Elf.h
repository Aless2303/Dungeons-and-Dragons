#pragma once

#include"CARasa.h"


class Elf : public CARasa
{
public:
	Elf();


	int skill1(Atribute atr) override;
	int skill2(Atribute atr) override;
};

