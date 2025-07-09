#include "CAClasa.h"

CAClasa::CAClasa(clasa_nume temp_clasa) : clasa(temp_clasa)
{
}

clasa_nume CAClasa::getClasa()
{
    return this->clasa;
}
