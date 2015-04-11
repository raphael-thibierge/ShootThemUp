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
            // à améliorer
            break;
            
        case 2:
            _modele->loadGame();
            break;
            
        default:
            break;
    }
    
    
    return 0;
}

void ViewMainMenu::showView() {
    
}