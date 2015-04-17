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
    
public:
    
    ViewMainMenu();
    
    virtual ~ViewMainMenu();
    
    int treatEvent() override;
    
    void showView() override;
    
    void showQuit();
    
};


#endif /* defined(__ShmupTerminal__ViewMainMenu__) */
