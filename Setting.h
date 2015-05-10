#ifndef SETTING_H
#define SETTING_H

#include "Level.h"
#include "Language.h"

class Settings
{

private:
    unsigned int _difficulty;
    unsigned int _nbLife;
    Language _language;


public:

// CONSTRUCTOR AND DESTRUCTOR
//
    Settings();

    virtual ~Settings();

// METHODS
//
    // change game difficulty
    bool changeDifficulty(unsigned int difficulty);
    
    // change initial life number
    bool changeNbLife(unsigned int nbLife);

    // change gameLanguage
    bool changeLanguage(std::string language);

// ACCESSOR METHODS
//

    unsigned int * getDifficulty() ;

    unsigned int * getNbLife() ;

    Language * getLanguage();

    
    void setDifficulty(const unsigned int value);
    
    void setNbLife(const unsigned int value);

};

#endif // SETTING_H
