#pragma once

#include<iostream>
#include"Room.h"


void afisare_prezentare_joc();


class Dungeon_Master
{
private:
	static Dungeon_Master* instance;
	//camera actuala va fi mereu pozitia 0
	std::vector<Room*> harta;
	//Room* camera_actuala;
	Personaj* player;



	void citire_mapa_from_file(std::string filename);
	bool test_finish_game();


	Dungeon_Master();
	~Dungeon_Master();

public:
	static Dungeon_Master* getInstance();
	static void destroyInstanceAtExit();


	void actualizeaza_camera(Room* camera);

	void startGame(std::string filename_map);

};

