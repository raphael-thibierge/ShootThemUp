//
//  viewGame.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__viewGame__
#define __ShmupTerminal__viewGame__

#include <stdio.h>
#include "View.h"
// choix 3 et 4 non gérés

class ViewGame : virtual public View
{
    
public:
    
    ViewGame();
    
    virtual ~ViewGame();
    
    int treatEvent() override;
    
    void showView() override;
    

};


#endif /* defined(__ShmupTerminal__viewGame__) */
