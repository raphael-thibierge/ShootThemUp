#ifndef LANGAGE_H
#define LANGAGE_H
#include <map>
#include<string>
#include <iostream>
#include <fstream>

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
    bool change(std::string language);
    
    void loadFromFile(std::string text);

//ACCESSOR METHODS
//
    std::string getText(std::string text);

    std::string getLanguage();



};

#endif // LANGAGE_H
