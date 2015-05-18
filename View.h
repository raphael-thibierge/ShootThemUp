//
//  View.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__View__
#define __ShmupTerminal__View__

#include <stdio.h>
#include "GameModel.h"
#include <SFML/Graphics.hpp>


class View
{
protected:

    GameModel* _modele;
    Language* _language;

    std::map<std::string, sf::Sprite> _spritesList;
    std::map<std::string, sf::Image> _imagesList;

    // SFML Window
    sf::RenderWindow * _window;


// CONSTRUCTOR AND DESTRUCTOR
//
public :

    View();

    virtual ~View();

// METHODS
//
    // CONSOLE VERSION

    virtual int treatEvent() =0;

    virtual void showViewTerminal() =0 ;


    // SFML VERSION

    virtual int treatEventSFML() =0;

    virtual void showViewSFML() =0;

    void displayButton(std::string text, float positionX, float positionY);

    bool MouseOnButton(const int mouseX, const int mouseY, const int buttonX, const int buttonY, const int buttonWidth, const int buttonHeight);

    void init(GameModel* modele, sf::RenderWindow * window);

    virtual void initButtons() =0;


};


#endif /* defined(__ShmupTerminal__View__) */
