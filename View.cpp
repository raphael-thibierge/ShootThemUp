//
//  View.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "View.h"

using namespace std;
//
// CONSTRUCTOR AND DESTRUCTOR
//
View::View(){
    initButtons();
}

View::~View(){
    _modele = nullptr;
}


//
// METHODS
//


void View::init(GameModel* modele, sf::RenderWindow * window)
{
    _modele = modele;
    _language = _modele->getSettings()->getLanguage();
    _window = window ;
    initButtons();
}

void View::displayStandartButton(std::string text, float positionX, float positionY, bool active)
{

    if (active)
    {
        _spritesList["standartButton_active"].SetPosition(positionX, positionY);
        _window->Draw(_spritesList["standartButton_active"]);
    }

    else
    {
        _spritesList["standartButton"].SetPosition(positionX, positionY);
        _window->Draw(_spritesList["standartButton"]);
    }
    _window->Draw(_spritesList["standartButton"]);

    displayText(text, positionX, positionY);

}

void View::displayText(std::string text, float positionX, float positionY)
{
    sf::String textDisplayed;
    textDisplayed.SetText(text);
    textDisplayed.SetPosition(positionX, positionY);
    _window->Draw(textDisplayed);

}


bool View::mouseOnButton
(const int mouseX, const int mouseY, const int buttonX, const int buttonY, const int buttonWidth, const int buttonHeight)
{ // return true if the mouse is on the button

    if (mouseX >= buttonX &&
        mouseX <= buttonX + buttonWidth &&
        mouseY >= buttonY &&
        mouseY <= buttonY + buttonHeight )
        return true;
    return false;
}

void View::initButtons()
{
        //buttons's image
    _imagesList.insert(make_pair("standartButtons", sf::Image()));
    _imagesList["standartButtons"].LoadFromFile(IMAGE_BUTTONS);

    // standart button
    _spritesList.insert(make_pair("standartButton", sf::Sprite()));
    _spritesList["standartButton"].SetImage(_imagesList["standartButtons"]);
    _spritesList["standartButton"].SetSubRect(sf::IntRect(BUTTON_SPRITE_X, BUTTON_SPRITE_Y, BUTTON_WIDTH + BUTTON_SPRITE_X , BUTTON_HEIGHT + BUTTON_SPRITE_Y));

    // standart active button
    _spritesList.insert(make_pair("standartButton_active", sf::Sprite()));
    _spritesList["standartButton_active"].SetImage(_imagesList["standartButtons"]);
    _spritesList["standartButton_active"].SetSubRect(sf::IntRect(BUTTON_SPRITE_ACTIVE_X, BUTTON_SPRITE_ACTIVE_Y, BUTTON_WIDTH + BUTTON_SPRITE_ACTIVE_X , BUTTON_HEIGHT + BUTTON_SPRITE_ACTIVE_Y));


}




