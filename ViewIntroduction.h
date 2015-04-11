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
    
public:
    
    ViewIntroduction();
    
    virtual ~ViewIntroduction();
    
    int treatEvent() override;
    
    void showView() override;
    
    
};



#endif /* defined(__ShmupTerminal__ViewIntroduction__) */
