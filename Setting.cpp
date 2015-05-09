#include "Setting.h"
 using namespace std;

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//

Settings::Settings(){
    _difficulty = DIFFICULTY;
    _nbLife = NB_LIFE_PLAYER;
    //_language = new Language;
}

Settings::~Settings(){}


//
// METHODS
//

bool Settings::changeDifficulty(unsigned int difficulty){
    if (difficulty > 0 && difficulty < 4){
        _difficulty = difficulty;
        return true;
    }
    return false;
}

bool Settings::changeNbLife(unsigned int nbLife){
    if (nbLife > 0){
        _nbLife = nbLife;
        return true;
    }
    return false;
}

bool Settings::changeLanguage(string language){
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

