#ifndef SETTING_H
#define SETTING_H
#include "Level.h"
#include "Langage.h"

class Setting
{
    public:
        Setting();
        virtual ~Setting();
        void changeDifficulty(Level *level, unsigned int difficulty);
        void changeNbLife(Level *level, unsigned int nbLife);
        void changeLangage(std::string langage);
    protected:
    private:

};

#endif // SETTING_H
