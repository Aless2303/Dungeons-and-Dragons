#pragma once

#include<iostream>
#include"Room.h"

class Room;
class Door
{
	int Difficulty;
	std::string nume;
	std::string atribut;
	std::string nume_camera_usa;
	Room* teleport;
public:
	Door() = default;
	Door(int diff, std::string name, std::string atr, Room* usa);
	Door(int diff, std::string name, std::string atr, std::string nume_usa);

	void set_nume_camera_usa(std::string nume_nou) { this->nume_camera_usa = nume_nou; };
	void set_teleport(Room* camera) { this->teleport = camera; };
	std::string getNume_camera_teleport() { return this->nume_camera_usa; };
	int getDifficulty();
	std::string getNume();
	std::string getAtribut();

	Room* getCamera_teleport();

	void prezinta_door();

};

