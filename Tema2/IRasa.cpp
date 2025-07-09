#include "IRasa.h"



std::ostream& operator<<(std::ostream& os, const rasa_nume& rasa)
{
    switch (rasa)
    {
    case EROARE_RASA:
        throw new Exceptie("EROARE_RASA la supraincarcarea operatorului << pentru enum rasa_nume.");
        break;
    case ORC:
        os << "ORC";
        break;
    case ELF:
        os << "ELF";
        break;
    case HUMAN:
        os << "HUMAN";
        break;
    case GOBLIN:
        os << "GOBLIN";
        break;
    default:
        throw new Exceptie("Eroare la supraincarcarea operatorului << pentru enum rasa_nume.");
        break;
    }

    return os;
}