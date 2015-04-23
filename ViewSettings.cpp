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
        cout << _language->getText("choice") << endl;
        cin >> answer;
        
    } while ( answer > 4 && answer < 0 );
    
    // treatement
    switch (answer) {
        case 1:
            cout << _language->getText("valueLower") << " 4" << endl;
            do {
                cout << _language->getText("newValue") << endl;
                cin >> answer;
            } while (answer <= 0 || answer > 3);
            
            if (_modele->getSettings()->changeDifficulty(answer))
                cout << _language->getText("successfullChange") << endl;
            else
                cout << _language->getText("fail");
            break;
            
        case 2:
            do {
                cout << _language->getText("newValue") << " : " << endl;
                cin >> answer;
            } while (answer <= 0);
            
            if (_modele->getSettings()->changeNbLife(answer))
                cout << _language->getText("successfullChange") << endl;
            else
                cout << _language->getText("fail");
            
            break;
            
        case 3:
            cout << _language->getText("availableLanguages") << endl;
            cout << "\t (1) " << _language->getText("english") << endl;
            cout << "\t (2) " << _language->getText("french") << endl;
            
            int answer;
            do {
                cout << _language->getText("choice") << endl;
                cin >> answer;
            } while (answer < 0 || answer >2);
            
            switch (answer) {
                case 1:
                    if (_modele->getSettings()->changeLanguage("English"))
                        cout << _language->getText("successfullChange");
                    else
                        cout << _language->getText("fail") << endl;
                    break;
                    
                case 2:
                    if (_modele->getSettings()->changeLanguage("French"))
                        cout << _language->getText("successfullChange") << endl;
                    else
                        cout << _language->getText("fail") << endl;
                    break;

                    
                default:
                    cout << _language->getText("fail") << endl;
                    break;
            }
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
    cout << _language->getText("settings") << endl << endl ;
    
    cout << _language->getText("difficulty") << " : " << *_modele->getSettings()->getDifficulty() << endl;
    cout << _language->getText("nbLifeInit") << " : " << *_modele->getSettings()->getNbLife() << endl;
    cout << _language->getText("language") << " : " << _language->getText("languageValue") <<endl ;
    cout << endl;
    cout << "Menu" << endl ;
    cout << "\t (1) " + _language->getText("changeDifficulty") << endl ;
    cout << "\t (2) " + _language->getText("changeNBLifeInit") << endl;
    cout << "\t (3) " + _language->getText("changeLanguage") << endl ;
    cout << "\t (4) " + _language->getText("quit") << endl;
    
    
    
}