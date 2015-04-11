#ifndef SETTING_H
#define SETTING_H
#include "Level.h"

class Setting
{
    public:
        Setting();
        virtual ~Setting();
        void changeDifficulty(Level *level, unsigned int difficulty);
        void changeNbLife(Level *level, unsigned int nbLife);
    protected:
    private:

};

#endif // SETTING_H
