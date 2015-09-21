#ifndef LANGAGE_H
#define LANGAGE_H
#include <map>
#include<string>
#include <iostream>
#include <fstream>
#include "ResourcePath.hpp"

class Language
{
private:
    std::map<std::string, std::string> _listText;
    std::string _language;
    

// CONSTRUCTOR AND DESTRUCTOR
//
public:
    
    Language();
    
    virtual ~Language();

// METHODS
//
    // change lan
    bool change(const std::string language);
    
    void loadFromFile(const std::string text);

//ACCESSOR METHODS
//
    std::string getText(const std::string text);

    std::string getLanguage();



};

#endif // LANGAGE_H
