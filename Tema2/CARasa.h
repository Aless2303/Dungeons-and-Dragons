#pragma once

#include"IRasa.h"




class CARasa : public IRasa
{
private:
	//Atribute atribute;
	rasa_nume rasa;

public:
	CARasa(rasa_nume temp_rasa);
	//void print_atribute();
	rasa_nume getRasa() override;
	virtual int skill1(Atribute atr) = 0;
	virtual int skill2(Atribute atr) = 0;

};

