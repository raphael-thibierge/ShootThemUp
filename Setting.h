#ifndef SETTING_H
#define SETTING_H

#include "Level.h"
#include "Langage.h"

class Settings
{
<<<<<<< HEAD
private:
    unsigned int _difficulty;
    unsigned int _nbLife;
    Language * _language;
    
    
public:

// CONSTRUCTOR AND DESTRUCTOR
    Settings();
    
    virtual ~Settings();

// METHODS
    void changeDifficulty(unsigned int difficulty);
    
    void changeNbLife(unsigned int nbLife);
    
    void changeLanguage(std::string language);
=======
    public:
        Setting();
        virtual ~Setting();
        void changeDifficulty(Level *level, unsigned int difficulty);
        void changeNbLife(Level *level, unsigned int nbLife);
        void changeLangage(std::string langage);
    protected:
    private:
>>>>>>> 53b6521293fccb7775c0b160d4d2d48a9dd6342b

// ACCESSOR METHODS
    
    unsigned int * getDifficulty() ;
    
    unsigned int * getNbLife() ;
    
    Language * getLanguage() const;
    
    
};

#endif // SETTING_H
