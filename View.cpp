//
//  View.cpp
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#include "View.h"

//
// CONSTRUCTOR AND DESTRUCTOR
//
View::View(){}

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

void View::displayButton(std::string text, float positionX, float positionY)
{
    _spritesList["button"].SetPosition(positionX, positionY);
    _window->Draw(_spritesList["button"]);

    sf::String buttonText;
    buttonText.SetText(_language->getText(text));
    buttonText.SetPosition(positionX, positionY);
    _window->Draw(buttonText);
}


bool View::MouseOnButton
(const int mouseX, const int mouseY, const int buttonX, const int buttonY, const int buttonWidth, const int buttonHeight)
{ // return true if the mouse is on the button
    if (mouseX >= buttonX &&
        mouseX <= buttonX + buttonWidth &&
        mouseY >= buttonY &&
        mouseY <= buttonY + buttonHeight )
        return true;
    return false;
}
