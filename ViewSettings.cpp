//
//  ViewSettings.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewSettings.h"





using namespace std;

ViewSettings::ViewSettings(){}

ViewSettings::~ViewSettings(){}

int ViewSettings::treatEvent(){
    int returnValue = 1;
    
    
    
    int answer;
    do {
        cout << "Choix" << endl;
        cin >> answer;
        
    } while ( answer > 4 && answer < 0 );
    
    
    // VALEURS PRENSENTES SONT DES CONSTANTES
    // A CHANGER AVEC MESSAGE QUI DEMANDE PARAMETRE SOUHAITE
    switch (answer) {
        case 1:
            _modele->getSettings()->changeDifficulty(3);
            break;
            
        case 2:
            _modele->getSettings()->changeNbLife(4);
            break;
            
        case 3:
            _modele->getSettings()->changeLanguage("English");
            break;
            
        case 4:
            returnValue = 0;
            
        default:
            break;
    }
    
    
    return returnValue;
}

void ViewSettings::showView(){
    
    cout << "\n------------------" << endl;
    cout << "Paramètres\n" << endl ;
    
    cout << "DIFFICULTEE = " << *_modele->getSettings()->getDifficulty() << endl;
    cout << "NOMBRE DE VIE INITIAL = " << *_modele->getSettings()->getNbLife() << endl;
    cout << endl;
    cout << "Menu" << endl ;
    cout << "\t (1) Changer la difficulté" << endl ;
    cout << "\t (2) Changer le nombre de vie initiales" << endl;
    cout << "\t (3) Changer la langue (non fonctionnel)" << endl ;
    cout << "\t (4) Quitter" << endl;
    
    
    
}