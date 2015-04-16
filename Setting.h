#ifndef SETTING_H
#define SETTING_H

#include "Level.h"
#include "Langage.h"

class Settings
{

private:
    unsigned int _difficulty;
    unsigned int _nbLife;
    Language _language;
    
    
public:

// CONSTRUCTOR AND DESTRUCTOR
    Settings();
    
    virtual ~Settings();

// METHODS
    bool changeDifficulty(unsigned int difficulty);
    
    bool changeNbLife(unsigned int nbLife);
    
    bool changeLanguage(std::string language);

// ACCESSOR METHODS
    
    unsigned int * getDifficulty() ;
    
    unsigned int * getNbLife() ;
    
    Language * getLanguage();
    
    
};

#endif // SETTING_H
