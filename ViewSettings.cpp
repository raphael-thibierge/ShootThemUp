//
//  ViewSettings.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "ViewSettings.h"





using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//
ViewSettings::ViewSettings(){}

ViewSettings::~ViewSettings(){}


//
// METHODS
//
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

int ViewSettings::treatEventSFML()
{
    int returnvalue = 1;

    sf::Event event;

     while (_window->GetEvent(event))
    {

        switch (event.Type)
        {
            case sf::Event::Closed :
                returnvalue = 111;
                break;

            case sf::Event::MouseButtonPressed :
            {
                int mouseX = event.MouseButton.X ;
                int mouseY = event.MouseButton.Y ;

                if (mouseOnButton(mouseX, mouseY, SETTINGSVIEW_FRENCH_X, SETTINGSVIEW_FRENCH_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                {
                    _modele->getSettings()->changeLanguage("French");
                }

                if (mouseOnButton(mouseX, mouseY, SETTINGSVIEW_ENGLISH_X, SETTINGSVIEW_ENGLISH_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                {
                    _modele->getSettings()->changeLanguage("English");
                }

                if (mouseOnButton(mouseX, mouseY, SETTINGSVIEW_QUIT_X, SETTINGSVIEW_QUIT_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                {
                    returnvalue = 0;
                }

                if (mouseOnButton(mouseX, mouseY, SETTINGSVIEW_DIFFICULTY_1_X, SETTINGSVIEW_DIFFICULTY_1_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                {

                    returnvalue = 1;
                    _modele->getSettings()->changeDifficulty(1);
                }

                if (mouseOnButton(mouseX, mouseY, SETTINGSVIEW_DIFFICULTY_2_X, SETTINGSVIEW_DIFFICULTY_2_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                {
                    returnvalue = 1;
                    _modele->getSettings()->changeDifficulty(2);
                }

                if (mouseOnButton(mouseX, mouseY, SETTINGSVIEW_DIFFICULTY_3_X, SETTINGSVIEW_DIFFICULTY_3_Y, BUTTON_WIDTH, BUTTON_HEIGHT))
                {
                    returnvalue = 1;
                    _modele->getSettings()->changeDifficulty(3);
                }

                break;
            }

        default :
            break;
        }
    }

    return returnvalue;
}

void ViewSettings::showViewTerminal(){

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

void ViewSettings::showViewSFML()
{
    displayText(_language->getText("settings"), SETTINGSVIEW_TITLE_X, SETTINGSVIEW_TITLE_Y);

    displayText(_language->getText("language"), SETTINGSVIEW_LANGUAGE_X, SETTINGSVIEW_LANGUAGE_Y);
    displayText(_language->getText("nbLifeInit"), SETTINGSVIEW_NBLIFE_X, SETTINGSVIEW_NBLIFE_Y);
    displayText(_language->getText("difficulty"), SETTINGSVIEW_DIFFICULTY_X, SETTINGSVIEW_DIFFICULTY_Y);

    displayStandartButton(_language->getText("french"), SETTINGSVIEW_FRENCH_X, SETTINGSVIEW_FRENCH_Y);
    displayStandartButton(_language->getText("english"), SETTINGSVIEW_ENGLISH_X, SETTINGSVIEW_ENGLISH_Y);

    displayStandartButton("1", SETTINGSVIEW_DIFFICULTY_1_X, SETTINGSVIEW_DIFFICULTY_1_Y);
    displayStandartButton("2", SETTINGSVIEW_DIFFICULTY_2_X, SETTINGSVIEW_DIFFICULTY_2_Y);
    displayStandartButton("3", SETTINGSVIEW_DIFFICULTY_3_X, SETTINGSVIEW_DIFFICULTY_3_Y);

    displayStandartButton(_language->getText("quit"), SETTINGSVIEW_QUIT_X, SETTINGSVIEW_QUIT_Y);


}


void ViewSettings::initButtons()
{
}
