#pragma once


#include"IClasa.h"





class CAClasa:public IClasa
{
private:
	//Atribute atribute;
	clasa_nume clasa;

public:
	CAClasa(clasa_nume temp_clasa);
	//void print_atribute();
	clasa_nume getClasa() override;
	virtual int skill1(Atribute atr) = 0;
	virtual int skill2(Atribute atr) = 0;
};

