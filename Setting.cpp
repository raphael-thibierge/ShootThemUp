#include "Setting.h"
 using namespace std;

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//

Settings::Settings(){
    //cout << "\n=====================" << endl;
    //cout << "CONSTRUCTOR SETTINGS" << endl;
    
    _difficulty = DIFFICULTY;
    _nbLife = NB_LIFE_PLAYER;
    //_language = new Language;
}

Settings::~Settings(){
    //cout << "\n=====================" << endl;
    //cout << "DESTRUCTOR SETTINGS" << endl;
}


//
// METHODS
//

bool Settings::changeDifficulty(unsigned int difficulty)
{// return true if it has been changed
    if (difficulty > 0 && difficulty <= MAX_DIFFICULTY){
        _difficulty = difficulty;
        return true;
    }
    return false;
}

bool Settings::changeNbLife(unsigned int nbLife)
{// return true if it has been changed
    if (nbLife > 0){
        _nbLife = nbLife;
        return true;
    }
    return false;
}

bool Settings::changeLanguage(string language)
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
