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

class View
{    
protected:

    GameModel* _modele;
    Language* _language;

    
// CONSTRUCTOR AND DESTRUCTOR
//
public :

    View();
    
    virtual ~View();
    
// METHODS
//
    virtual int treatEvent() =0;
    
    virtual void showView();

    void setView(GameModel* modele);
};


#endif /* defined(__ShmupTerminal__View__) */
