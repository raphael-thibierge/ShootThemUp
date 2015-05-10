//
//  ViewsController.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 11/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__ViewsController__
#define __ShmupTerminal__ViewsController__

#include <stdio.h>

#include "GameModel.h"
#include "ViewGame.h"
#include "ViewShop.h"
#include "ViewIntroduction.h"
#include "ViewMainMenu.h"
#include "ViewSettings.h"
#include "ViewBestScores.h"
#include <map>


class ViewsController {

protected:
    // end of the program
    bool _quit;
    GameModel* _modele;
    // list of views
    std::map<std::string, View*> _allViews;
    // active view
    View* _view ;
    
    // game view in the queue
    ViewGame _game;
    
// CONSTRUCTOR AND DESTRUCTOR
//
public:

    ViewsController();

    ~ViewsController();

// METHODS
//
    // methods to treat events in the active view
    bool treatEvent();

    // show the current view
    void showView();

    // quit the program
    void quit();

    // init gamemodel for each views
    void init(GameModel* modele);

private:
    void changeView(std::string view);








};


#endif /* defined(__ShmupTerminal__ViewsController__) */
