#include "Door.h"

Door::Door(int diff, std::string name, std::string atr, Room* usa) : Difficulty(diff), nume(name),atribut(atr),teleport(usa)
{
}

Door::Door(int diff, std::string name, std::string atr, std::string nume_usa): Difficulty(diff),nume(name),atribut(atr),nume_camera_usa(nume_usa)
{
}

int Door::getDifficulty()
{
    return this->Difficulty;
}

std::string Door::getNume()
{
    return this->nume;
}

std::string Door::getAtribut()
{
    return this->atribut;
}

Room* Door::getCamera_teleport()
{
    return this->teleport;
}

void Door::prezinta_door()
{
    std::cout << "\033[1;33m";
    std::cout << this->nume << " " << this->atribut << " Duce spre " << this->nume_camera_usa << std::endl;
    std::cout << "\033[0m";
}
