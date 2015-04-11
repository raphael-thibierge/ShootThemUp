#include "Langage.h"
#include <iostream>
#include <fstream>

using namespace std;

Langage::Langage()
{
    _listText["play"]="Play";
    _listText["shop"]="Shop";
    _listText["setting"]="Setting";
    _listText["quit"]="Quit";
    _listText["move"]="Move";
    _listText["shoot"]="Shoot";
    _listText["nothing"]="Nothing";
    _listText["escape"]="Escape";
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
