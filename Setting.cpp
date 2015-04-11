#include "Setting.h"

Setting::Setting()
{
    //ctor
}

Setting::~Setting()
{
    //dtor
}


void Setting::changeDifficulty(Level *level, unsigned int difficulty)
{
    level->setDifficulty(difficulty);
}

void Setting::changeNbLife(Level *level, unsigned int nbLife)
{
    level->getPlayer()->setNbLife(nbLife);
}
