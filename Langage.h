#ifndef LANGAGE_H
#define LANGAGE_H
#include <map>
#include<string>
#include <iostream>
#include <fstream>

class Langage
{
    public:
        Langage();
        virtual ~Langage();
        void changed(std::string langage);
        void loaded(std::string text);
    protected:
    private:
        std::map<std::string, std::string> _listText;

};

#endif // LANGAGE_H
