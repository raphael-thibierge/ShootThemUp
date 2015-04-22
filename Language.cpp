#include "Language.h"
#include <iostream>
#include <fstream>

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//

Language::Language()
{
    loadFromFile("TextFrench.txt");
}

Language::~Language()
{
    //dtor
}

//
// METHODS
//

bool Language::change(string language)
{
    bool returnValue = false;

    if (language=="French"){
        loadFromFile("TextFrench.txt");
        returnValue = true;
    }
    if(language=="English"){
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
        string id;
        string information;

        while(getline(file, line))
        {
            file >> id >> information;
            _listText[id]=information;
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
    return "Text not find.";
}


