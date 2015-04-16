#include "Langage.h"
#include <iostream>
#include <fstream>

using namespace std;

Language::Language()
{
    loadFromFile("TextFrench.txt");
}

Language::~Language()
{
    //dtor
}

void Language::change(string language)
{
    if (language=="French")
    {
        loadFromFile("TextFrench.txt");
    }
    if(language=="English")
    {
        loadFromFile("TextEnglish.txt");
    }
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


