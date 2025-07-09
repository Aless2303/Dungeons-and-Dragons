#define _CRT_SECURE_NO_WARNINGS

#include"Dungeon_Master.h"


int main()
{



	try {
		afisare_prezentare_joc();
		Dungeon_Master::getInstance()->startGame("Camere.txt");
	}
	catch (IExceptie* ex)
	{
		ex->printMesaj();
	}





	return 0;
}