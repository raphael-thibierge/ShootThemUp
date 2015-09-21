//
//  ViewMainMenu.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__ViewMainMenu__
#define __ShmupTerminal__ViewMainMenu__

#include <stdio.h>
#include "View.h"


class ViewMainMenu : public virtual View {

// CONSTRUCTOR AND DESTRUCTOR
//
public:

    ViewMainMenu();

    virtual ~ViewMainMenu();

// METHODS
//
    int treatEvent() override;

    int treatEventSFML() override;

    void showViewTerminal() override;

    void showViewSFML() override;

    // screen at end of the program
    void showQuit();

    bool initSFML() override;

};


#endif /* defined(__ShmupTerminal__ViewMainMenu__) */
