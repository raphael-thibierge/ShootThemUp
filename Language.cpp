#include "Language.h"
#include <iostream>
#include <fstream>

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//

Language::Language()
{
    _language = "French" ;
    loadFromFile("TextFrench.txt");
}

Language::~Language() {}

//
// METHODS
//

bool Language::change(string language)
{
    bool returnValue = false;

    if (language=="French"){
        _language = language;
        loadFromFile("TextFrench.txt");
        returnValue = true;
    }
    if(language=="English"){
        _language = language;
        loadFromFile("TextEnglish.txt");
        returnValue = true;
    }

    return returnValue;
}


void Language::loadFromFile(string text)
{
    ifstream file(text, ios::in);
    if(file)  // si l'ouverture a réussi
    {
        if (!_listText.empty())
            _listText.clear();


        string line;
        

        while(getline(file, line))
        {
            
            string key = "";
            string information = "";
            
            bool keyFound = false;
            for (auto c : line)
            {

                if (c == ' ' && !keyFound){
                    keyFound = true;
                }
                else if (!keyFound){
                    key += c;
                }
                else{
                    information += c;
                }
            }
            
            _listText[key] = information;
            
        }
        file.close();  // on ferme le fichier
    }
    else  // sinon
        cerr << "Can't open this file !" << endl;
}

//
//ACCESSOR METHODS
//

string Language::getText(string text)
{
    for (auto t : _listText)
    {
        if(text==t.first)
        {
            return t.second;
        }
    }
    return "Text not found.";
}

string Language::getLanguage()
{
    return _language;
}


