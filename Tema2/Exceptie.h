#pragma once
#include"IExceptie.h"
#include<iostream>



class Exceptie : public IExceptie
{
private:
	std::string mesaj;
public:
	Exceptie(std::string m) : mesaj(m) {};
	void printMesaj() override;
};

