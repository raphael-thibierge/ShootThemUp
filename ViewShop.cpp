//
//  ViewShop.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewShop.h"

using namespace std;

ViewShop::ViewShop() {}

ViewShop::~ViewShop() {}

int ViewShop::treatEvent()
{
    int returnValue = 1;
    int answer;
    do
    {
        cout << _language->getText("choice") << endl;
        cin >> answer;

    }
    while ( (answer > 10 && answer < 15) || (answer > 25 && answer < 20) || (answer > 4 && answer < 2));

    switch (answer)
    {
    case 11:
        if(_modele->getShop()->upgradeBullet("level2")){
            cout<<_language->getText("purchaseRight")<<endl;
        }
        else{
            cout<<_language->getText("purchaseWrong")<<endl;
        }
        break;

    case 12:
        if(_modele->getShop()->upgradeBullet("level3")){
            cout<<_language->getText("purchaseRight")<<endl;
        }
        else{
            cout<<_language->getText("purchaseWrong")<<endl;
        }
        break;

    case 13:
        if(_modele->getShop()->upgradeBullet("level4")){
            cout<<_language->getText("purchaseRight")<<endl;
        }
        else{
            cout<<_language->getText("purchaseWrong")<<endl;
        }
        break;

    case 14:
        if(_modele->getShop()->upgradeBullet("level5")){
            cout<<_language->getText("purchaseRight")<<endl;
        }
        else{
            cout<<_language->getText("purchaseWrong")<<endl;
        }
        break;

    case 21:
        if(_modele->getShop()->upgradeShip("ship2")){
            cout<<_language->getText("purchaseRight")<<endl;
        }
        else{
            cout<<_language->getText("purchaseWrong")<<endl;
        }
        break;

    case 22:
        if(_modele->getShop()->upgradeShip("ship3")){
            cout<<_language->getText("purchaseRight")<<endl;
        }
        else{
            cout<<_language->getText("purchaseWrong")<<endl;
        }
        break;

    case 23:
        if(_modele->getShop()->upgradeShip("ship4")){
            cout<<_language->getText("purchaseRight")<<endl;
        }
        else{
            cout<<_language->getText("purchaseWrong")<<endl;
        }
        break;

    case 3:
        returnValue = 0;
        break;


    default:
        break;
    }

    return returnValue;
}


void ViewShop::showView()
{
    cout << "\n---------------------- \n " + _language->getText("shop") << endl;
    cout << _language->getText("money") << " " + to_string(_modele->getPlayer()->getMoney()) + "$"<< endl <<endl;

    cout << "\t (1) " + _language->getText("upgradeMainShoot") << endl;
    cout << "\t \t (11) " + _language->getText("upgradeMainShootlvl2") + "  100$"<< endl;
    cout << "\t \t (12) " + _language->getText("upgradeMainShootlvl3") + "  200$" << endl;
    cout << "\t \t (13) " + _language->getText("upgradeMainShootlvl4") + "  350$" << endl;
    cout << "\t \t (14) " + _language->getText("upgradeMainShootlvl5") + "  500$"<< endl;
    cout << "\t (2) " + _language->getText("upgradeShip") << endl;
    cout << "\t \t (21) " + _language->getText("upgradeShiplvl2") + "  200$"<< endl;
    cout << "\t \t (22) " + _language->getText("upgradeShiplvl3") + "  500$"<< endl;
    cout << "\t \t (23) " + _language->getText("upgradeShiplvl4") + "  1000$"<< endl;
    cout << "\t (3) " + _language->getText("quit") << endl;

}
