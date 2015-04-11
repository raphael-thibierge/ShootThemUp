#include "Langage.h"
#include <iostream>
#include <fstream>

using namespace std;

Langage::Langage()
{
    loaded("TextEnglish.txt");
}

Langage::~Langage()
{
    //dtor
}

void Langage::changed(string langage)
{
    if (langage=="french")
    {
        string text = "TextFrench.txt";
        loaded(text);
    }
    if(langage=="english")
    {
        string text = "TextEnglish.txt";
        loaded(text);
    }
}


void Langage::loaded(string text)
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
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

string Langage::getText(string text)
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


