#include "Setting.h"
 using namespace std;

using namespace std;

Settings::Settings(){
    cout << "\n=====================" << endl;
    cout << "CONSTRUCTOR SETTINGS" << endl;
    
    _difficulty = DIFFICULTY;
    _nbLife = NB_LIFE_PLAYER;
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
    _language->change(language);
}


// ACCESSOR METHODS

unsigned int * Settings::getDifficulty() {
    return &_difficulty;
}

unsigned int * Settings::getNbLife() {
    return &_nbLife;
}

<<<<<<< HEAD
Language * Settings::getLanguage() const{
    return _language;
}
=======
void Setting::changeLangage(string langage)
{
    changeLangage(langage);
}
>>>>>>> 53b6521293fccb7775c0b160d4d2d48a9dd6342b
