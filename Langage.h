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
    
public:
// CONSTRUCTOR AND DESTRUCTOR
    Language();
    
    virtual ~Language();

// METHODS
    
    void change(std::string language);
    
    void loadFromFile(std::string text);

//ACCESSOR METHODS

    std::string getText(std::string text);




};

#endif // LANGAGE_H
