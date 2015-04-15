#include "Setting.h"
 using namespace std;

using namespace std;

Settings::Settings(){
    cout << "\n=====================" << endl;
    cout << "CONSTRUCTOR SETTINGS" << endl;
    
    _difficulty = DIFFICULTY;
    _nbLife = NB_LIFE_PLAYER;
    //_language = new Language;
}

Settings::~Settings(){
    cout << "\n=====================" << endl;
    cout << "DESTRUCTOR SETTINGS" << endl;
}


void Settings::changeDifficulty(unsigned int difficulty){
    _difficulty = difficulty;
    //level->setDifficulty(difficulty);
}

void Settings::changeNbLife(unsigned int nbLife){
    _nbLife = nbLife;
    //level->getPlayer()->setNbLife(nbLife);
}

void Settings::changeLanguage(string language){
    _language.change(language);
}


// ACCESSOR METHODS

unsigned int * Settings::getDifficulty() {
    return &_difficulty;
}

unsigned int * Settings::getNbLife() {
    return &_nbLife;
}


Language * Settings::getLanguage() {
    return &_language;
}
