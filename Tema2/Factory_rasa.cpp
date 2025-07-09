#include "Factory_rasa.h"


rasa_nume convert_string_to_rasa(std::string nume_rasa)
{
    if (nume_rasa == "ORC")
        return ORC;
    else if (nume_rasa == "ELF")
        return ELF;
    else if (nume_rasa == "HUMAN")
        return HUMAN;
    else if (nume_rasa == "GOBLIN")
        return GOBLIN;
    else
        throw new Exceptie("Eroare. Ai introdus numele rasei gresit.");
}



IRasa* Factory_rasa::getRasa(std::string nume_rasa)
{
    IRasa* rasa = nullptr;
    rasa_nume temp_rasa = convert_string_to_rasa(nume_rasa);
    switch (temp_rasa)
    {
    case rasa_nume::ORC:
        rasa = new Orc();
        return rasa;
        break;
    case rasa_nume::ELF:
        rasa = new Elf();
        return rasa;
        break;
    case rasa_nume::HUMAN:
        rasa = new Human();
        return rasa;
        break;
    case rasa_nume::GOBLIN:
        rasa = new Goblin();
        return rasa;
        break;
    default:
        return rasa;
        break;
    }
}


