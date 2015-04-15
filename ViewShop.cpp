//
//  ViewShop.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewShop.h"

using namespace std;

ViewShop::ViewShop(){}

ViewShop::~ViewShop(){}

int ViewShop::treatEvent(){
    int returnValue = 0;
    int answer;
    
    do {
        cout << _language->getText("choice") << endl;
        cin >> answer;
        
    } while ( answer > 3 && answer < 0 );
    
    switch (answer) {
        case 1:
            break;
            
        case 2:
            break;
            
        case 3:
            returnValue = 0;
            break;
            
            
        default:
            break;
    }

    
    
    
    return returnValue;
}


void ViewShop::showView(){
    cout << "\n---------------------- \n " + _language->getText("shop") << endl  << endl ;
    
    cout << "\t (1) " + _language->getText("upgradeMainShoot") << endl;
    cout << "\t (2) " + _language->getText("upgradeShip") << endl;
    cout << "\t (3) " + _language->getText("quit") << endl;

}