//
//  ViewMainMenu.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewMainMenu.h"



using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//
ViewMainMenu::ViewMainMenu(){}

ViewMainMenu::~ViewMainMenu(){}


//
// METHODS
//
int ViewMainMenu::treatEvent() {
    int returnValue = 1;
    int answer;
    
    if (_modele->getPlayer() == nullptr){
        
  
        do {
            cout << _language->getText("choice") << endl;
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
                returnValue = -4;
                break;
            
            case 4:
                returnValue = 0;
                showQuit();
                
            default:
                break;
        }
    }
    else {
        
        do {
            cout << _language->getText("choice") << endl;
            cin >> answer;
            
        } while ( answer > 4 && answer < 0 );
        
        switch (answer) {
            case 1:
                _modele->play();
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
                showQuit();
                break;
            
            default:
                break;
        }
    }
    
    
    return returnValue;
}

void ViewMainMenu::showView() {
    if (_modele->getPlayer() == nullptr){
        
        cout << "\n------------------" << endl;
        cout << _language->getText("menu") << endl ;
        cout << "\t (1) " + _language->getText("newGame") << endl ;
        cout << "\t (2) " + _language->getText("loadGame") << endl;
        cout << "\t (3) " + _language->getText("settings") << endl ;
        cout << "\t (4) " + _language->getText("quit") << endl;
    }
    
    else {
        
        cout << "\n------------------" << endl;
        cout << _language->getText("menu") << endl ;
        cout << "\t (1) " + _language->getText("play") << endl ;
        cout << "\t (2) " + _language->getText("goShop") << endl;
        cout << "\t (3) " + _language->getText("settings") << endl ;
        cout << "\t (4) " + _language->getText("quit") << endl;
    
    }
    
}

void ViewMainMenu::showQuit(){

    
    cout << "    ________  __    __  ________        ________  __    __  _______" << endl;
    cout << "   |        \\|  \\  |  \\|        \\      |        \\|  \\  |  \\|       \\" << endl;
    cout << "    \\$$$$$$$$| $$  | $$| $$$$$$$$      | $$$$$$$$| $$\\ | $$| $$$$$$$\\" << endl;
    cout << "      | $$   | $$__| $$| $$__          | $$__    | $$$\\| $$| $$  | $$" << endl;
    cout << "      | $$   | $$    $$| $$  \\         | $$  \\   | $$$$\\ $$| $$  | $$" << endl;
    cout << "      | $$   | $$$$$$$$| $$$$$         | $$$$$   | $$\\$$ $$| $$  | $$" << endl;
    cout << "      | $$   | $$  | $$| $$_____       | $$_____ | $$ \\$$$$| $$__/ $$" << endl;
    cout << "      | $$   | $$  | $$| $$     \\      | $$     \\| $$  \\$$$| $$    $$" << endl;
    cout << "       \\$$    \\$$   \\$$ \\$$$$$$$$       \\$$$$$$$$ \\$$   \\$$ \\$$$$$$$" << endl;

    
    
}