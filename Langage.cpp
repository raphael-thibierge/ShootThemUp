#include "Langage.h"
#include <iostream>
#include <fstream>
#include <vector>

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
    vector<string> listID;
    vector<string> listWord;
    int cpt=0;
    string line;
    ifstream file(text, ios::in);
    if(file)  // si l'ouverture a réussi
    {
        string id;
        string word;
        while(getline(file, line))
        {
            string word="";
            string separator=" ";
            int i=0,j;
            j = line.find(separator);
            while( j != string::npos )
            {
                if(cpt==0)
                {
                word=line.substr(i,j-i);
                i=j+1;
                j = line.find(separator,i);
                listID.push_back(word);
                }
            }
            word=line.substr(i);
            listWord.push_back(word);
        }
        file.close();  // on ferme le fichier
    }
    else  // sinon
        cerr << "Can't open this file !" << endl;

    int compt=0;
    for(auto id : listID)
    {
        _listText[id]=listWord[compt];
        compt++;
    }
    listID.clear();
    listWord.clear();
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
    return "Text not found.";
}


