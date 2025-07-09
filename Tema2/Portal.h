#pragma once


#include<iostream>
#include"Room.h"

class Room;
class Portal
{
	int Difficulty;
	std::string nume;
	std::string atribut;
	std::string nume_camera_teleport;
	Room* teleport;
public:
	Portal() = default;
	Portal(int diff, std::string name, std::string atr, Room* portal);
	Portal(int diff, std::string name, std::string atr, std::string nume_teleport);

	void set_teleport(Room* camera) { this->teleport = camera; };
	std::string getNume_camera_teleport();

	std::string getNume();

	void prezinta_portal();

	int getDifficulty();
	std::string getAtribut();

	Room* getCamera_teleport();

};

