//
//  ViewIntroduction.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__ViewIntroduction__
#define __ShmupTerminal__ViewIntroduction__

#include "View.h"
#include <stdio.h>

class ViewIntroduction : public virtual View
{
private:
    sf::Clock _time;

// CONSTRUCTOR AND DESTRUCTOR
//
public:

    ViewIntroduction();

    virtual ~ViewIntroduction();


// METHODS
//
    int treatEvent() override;

    int treatEventSFML() override;

    void showViewTerminal() override;

    void showViewSFML() override;

    bool initSFML() override;

};



#endif /* defined(__ShmupTerminal__ViewIntroduction__) */
