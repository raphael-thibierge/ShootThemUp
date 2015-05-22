//
//  ViewSettings.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__ViewSettings__
#define __ShmupTerminal__ViewSettings__

#include <stdio.h>
#include "View.h"


class ViewSettings : public virtual View{

// CONSTRUCTOR AND DESTRUCTOR
//
public:

    ViewSettings();

    virtual ~ViewSettings();


// METHODS
//
    int treatEvent() override;

    int treatEventSFML() override;

    void showViewTerminal() override;

    void showViewSFML() override;

    bool initSFML() override;
};

#endif /* defined(__ShmupTerminal__ViewSettings__) */

