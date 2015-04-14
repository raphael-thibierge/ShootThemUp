#include "Langage.h"
#include <iostream>
#include <fstream>

using namespace std;

Language::Language()
{
    loadFromFile("TextEnglish.txt");
}

Language::~Language()
{
    //dtor
}

void Language::change(string langage)
{
    if (langage=="french")
    {
        string text = "TextFrench.txt";
        loadFromFile(text);
    }
    if(langage=="english")
    {
        string text = "TextEnglish.txt";
        loadFromFile(text);
    }
}


void Language::loadFromFile(string text)
{
    ifstream file(text, ios::in);
    if(file)  // si l'ouverture a réussi
    {
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


