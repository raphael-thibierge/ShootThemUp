//
//  ViewMainMenu.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewMainMenu.h"



using namespace std;


ViewMainMenu::ViewMainMenu(){}

ViewMainMenu::~ViewMainMenu(){}

int ViewMainMenu::treatEvent() {
    int returnValue = 1;
    
    if (_modele->getPlayer() == nullptr){
        
        cout << "------------------" << endl;
        cout << "Menu" << endl ;
        cout << "\t (1) Nouvelle Partie" << endl ;
        cout << "\t (2) Charger une partie" << endl;
        cout << "\t (3) Quitter" << endl ;
        int answer;
        do {
            cout << "Choix" << endl;
            cin >> answer;
            
        } while ( answer > 3 && answer < 0 );
        
        switch (answer) {
            case 1:
                _modele->newGame();
                returnValue = 1;
                break;
                
            case 2:
                if (!_modele->loadGame()){
                    cout << "Impossible de charger la partie" << endl;
                }
                else
                    returnValue = 1;
                break;
                
            case 3:
                returnValue = 0;
                break;
                
            default:
                break;
        }
    }
    else {
        
        
        cout << "------------------" << endl;
        cout << "Menu" << endl ;
        cout << "\t (1) Joueur" << endl ;
        cout << "\t (2) Accéder à la boutique" << endl;
        cout << "\t (3) Réglages" << endl ;
        cout << "\t (4) Quitter" << endl;
        
        int answer;
        do {
            cout << "Choix" << endl;
            cin >> answer;
            
        } while ( answer > 4 && answer < 0 );
        
        switch (answer) {
            case 1:
                returnValue = -2;
                break;
                
            case 2:
                returnValue = -3;
                break;
            
            case 3:
                returnValue = -4;
                break;
            
            case 4:
                returnValue = 0;
            
            default:
                break;
        }

        
    }
    
    
    return returnValue;
}

void ViewMainMenu::showView() {
    
}