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
    
    cout << "\n---------------------- \n Shop \n"  << endl ;
    
    cout << "\t (1) Amélioration du Tir Principal" << endl;
    cout << "\t (2) Amélioration du Ship" << endl;
    cout << "\t (3) Quitter" << endl;
    cout << "Choix";
    
    
    int answer;
    do {
        cout << "Choix" << endl;
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
    cout << " Vue non disponible" << endl ;
}