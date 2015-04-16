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

    int reponse;

    do {
        cout << "Choix : ";
        cin >> reponse;
    } while (reponse<0 || reponse>5);

    switch (reponse) {
        case 1:
            int dx, dy;
            cout << _language->getText("moveX") ;
            cin >> dx ;
            cout << _language->getText("moveY");
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

    return returnValue;
}


void ViewGame::showView(){
    cout << "\n--------------" << endl;
    cout << "Jeu" << endl;
    cout << endl;
    cout << _modele->getPlayer()->toString() << endl;
    cout << endl;

    if (!_modele->getLevel()->getEnemy()->empty())
        for (auto enemy : *_modele->getLevel()->getEnemy())
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

void ViewGame::showTransition(){




}
