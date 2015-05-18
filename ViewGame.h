//
//  ViewGame.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__ViewGame__
#define __ShmupTerminal__ViewGame__

#include <stdio.h>

#include "View.h"
// choix 3 et 4 non gérés

class ViewGame : virtual public View
{

// CONSTRUCTOR AND DESTRUCTOR
//
public:

    ViewGame();

    virtual ~ViewGame();

// METHODS
//
    int treatEvent() override;

    int treatEventSFML() override;

    void showViewTerminal() override;

    void showViewSFML() override;

    // transitions betweent 2 levels
    void showTransition();

    // screen when player loose
    void showLoose();

    void initButtons() override;
};


#endif /* defined(__ShmupTerminal__ViewGame__) */
