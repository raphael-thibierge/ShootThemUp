//
//  ViewShop.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__ViewShop__
#define __ShmupTerminal__ViewShop__

#include "View.h"

class ViewShop : public virtual View
{
    
public:
    ViewShop();
    
    virtual ~ViewShop();
    
    int treatEvent() override;
    
    void showView() override;
    
    
};


#endif /* defined(__ShmupTerminal__ViewShop__) */
