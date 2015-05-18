//
//  ViewBestScores.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/05/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__ViewBestScores__
#define __ShmupTerminal__ViewBestScores__

#include <stdio.h>
#include "View.h"

class ViewBestScores : public virtual View {

public:


    ViewBestScores();

    virtual ~ViewBestScores();

    int treatEvent() override;

    int treatEventSFML() override;

    void showViewTerminal() override;

    void showViewSFML() override;

    void initButtons() override;
};



#endif /* defined(__ShmupTerminal__ViewBestScores__) */
