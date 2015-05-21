#include "Setting.h"
 using namespace std;

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//

Settings::Settings(){
    _difficulty = LEVEL_DIFFICULTY;
    _nbLife = PLAYER_NB_LIFE;
}

Settings::~Settings(){}


//
// METHODS
//
bool Settings::changeDifficulty(const unsigned int difficulty)
{// return true if it has been changed
    if (difficulty > 0 && difficulty <= MAX_DIFFICULTY){
        _difficulty = difficulty;
        return true;
    }
    return false;
}

bool Settings::changeNbLife(const unsigned int nbLife)
{// return true if it has been changed
    if (nbLife > 0){
        _nbLife = nbLife;
        return true;
    }
    return false;
}

bool Settings::changeLanguage(const string language)
{// return true if it has been changed
    return _language.change(language);
}

//
// ACCESSOR METHODS
//

unsigned int * Settings::getDifficulty() {
    return &_difficulty;
}

unsigned int * Settings::getNbLife() {
    return &_nbLife;
}


Language * Settings::getLanguage() {
    return &_language;
}

void Settings::setDifficulty(const unsigned int value)
{
    _difficulty = value;
}

void Settings::setNbLife(const unsigned int value)
{
    _nbLife = value ;
}

