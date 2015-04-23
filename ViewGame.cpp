//
//  ViewGame.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewGame.h"
using namespace std;

ViewGame::ViewGame(){}

ViewGame::~ViewGame(){}

int ViewGame::treatEvent(){
    int returnValue = 1;
    
    if (_modele->getLevel() != nullptr)
    {
        
        int reponse;
        
        do {
            cout << "Choix : ";
            cin >> reponse;
        } while (reponse<0 || reponse>5);
        
        switch (reponse) {
            case 1:
                int dx, dy;
                cout << _language->getText("moveX") << " : ";
                cin >> dx ;
                cout << _language->getText("moveY") << " : ";
                cin >> dy;
                _modele->getPlayer()->RectanglePosition::move(dx, dy);
                break;
                
            case 2:
                _modele->getPlayer()->shoot("standart", "NORTH", _modele->getLevel()->getBullet());
                break;
                
            case 3 :
                break;
                
            case 5 :
                returnValue = 0;
                _modele->destructLevel();
                _modele->getPlayer()->setScore(0);
                break;
                
            default:
                break;
        }
    }
    else
        if (_modele->getPlayer()->getNbLife() == 0)
            returnValue = 0;
    return returnValue;
}


void ViewGame::showView(){
    if(_modele->getLevel()==nullptr)
        if (_modele->getPlayer()->getNbLife() > 0)
            showTransition();
        else
            showLoose();
        else {
            cout << "\n--------------" << endl;
            cout << "Jeu" << endl;
            cout << endl;
            cout << _modele->getPlayer()->toString() << endl;
            cout << endl;
            
            if (!_modele->getLevel()->getEnemies()->empty())
                for (auto enemy : *_modele->getLevel()->getEnemies())
                    cout << enemy->toString() << endl;
            cout << endl;
            
            if (!_modele->getLevel()->getBullet()->empty())
                for (auto bullet : *_modele->getLevel()->getBullet())
                    cout << bullet->toString() << endl;
            cout << endl;
            
            
            cout << "\t (1)" + _language->getText("move") << endl;
            cout << "\t (2)" + _language->getText("shoot") << endl;
            cout << "\t (3)" + _language->getText("bomb") << endl;
            cout << "\t (4)" + _language->getText("nothing") << endl;
            cout << "\t (5)" + _language->getText("escape") << endl;
        }
}

void ViewGame::showTransition(){
    
    
    cout << " __    __                        __            __                                     __ "<<endl;
    cout << "|  \\  |  \\                      |  \\          |  \\                                   |  \\"<<endl;
    cout << "| $$\\ | $$  ______   __    __  _| $$_         | $$       ______  __     __   ______  | $$"<<endl;
    cout << "| $$$\\| $$ /      \\ |  \\  /  \\|   $$ \\        | $$      /      \\|  \\   /  \\ /      \\ | $$"<<endl;
    cout << "| $$$$\\ $$|  $$$$$$\\ \\$$\\/  $$ \\$$$$$$        | $$     |  $$$$$$\\\\$$\\ /  $$|  $$$$$$\\| $$"<<endl;
    cout << "| $$\\$$ $$| $$    $$  >$$  $$   | $$ __       | $$     | $$    $$ \\$$\\  $$ | $$    $$| $$"<<endl;
    cout << "| $$ \\$$$$| $$$$$$$$ /  $$$$\\   | $$|  \\      | $$_____| $$$$$$$$  \\$$ $$  | $$$$$$$$| $$"<<endl;
    cout << "| $$  \\$$$ \\$$     \\|  $$ \\$$\\   \\$$  $$      | $$     \\ $$     \\   \\$$$    \\$$     \\| $$"<<endl;
    cout << " \\$$   \\$$  \\$$$$$$$ \\$$   \\$$    \\$$$$        \\$$$$$$$$ \\$$$$$$$    \\$      \\$$$$$$$ \\$$"<<endl;
    
    cout << endl << endl << _language->getText("score") << " : " << _modele->getPlayer()->getScore() << endl;
    cout << _language->getText("money") << " : " << _modele->getPlayer()->getMoney() << endl;
}

void ViewGame::showLoose(){
    
    
    cout << "     __      __   ______   __    __        __        ______    ______    ______   ________        __" << endl;
    cout << "    |  \\    /  \\ /      \\ |  \\  |  \\      |  \\      /      \\  /      \\  /      \\ |        \\      |  \\" << endl;
    cout << "     \\$$\\  /  $$|  $$$$$$\\| $$  | $$      | $$     |  $$$$$$\\|  $$$$$$\\|  $$$$$$\\| $$$$$$$$      | $$" << endl;
    cout << "      \\$$\\/  $$ | $$  | $$| $$  | $$      | $$     | $$  | $$| $$  | $$| $$___\\$$| $$__          | $$" << endl;
    cout << "       \\$$  $$  | $$  | $$| $$  | $$      | $$     | $$  | $$| $$  | $$ \\$$    \\ | $$  \\         | $$" << endl;
    cout << "        \\$$$$   | $$  | $$| $$  | $$      | $$     | $$  | $$| $$  | $$ _\\$$$$$$\\| $$$$$          \\$$" << endl;
    cout << "        | $$    | $$__/ $$| $$__/ $$      | $$_____| $$__/ $$| $$__/ $$|  \\__| $$| $$_____        __" << endl;
    cout << "        | $$     \\$$    $$ \\$$    $$      | $$      \\$$    $$ \\$$    $$ \\$$    $$| $$     \\      |  \\" << endl;
    cout << "         \\$$      \\$$$$$$   \\$$$$$$        \\$$$$$$$$ \\$$$$$$   \\$$$$$$   \\$$$$$$  \\$$$$$$$$       \\$$" << endl;
    
    
    
}
