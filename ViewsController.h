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
    bool _quit;
    GameModel* _modele;
    std::map<std::string, View*> _allViews;
    View* _view ;
    
    // pour que la vue du jeu soit stoqué dans la pile
    ViewGame _game;
    
public:

    ViewsController();

    ~ViewsController();

    bool treatEvent();

    void showView();

    void quit();

    void init(GameModel* modele);

private:
    void changeView(std::string view);








};


#endif /* defined(__ShmupTerminal__ViewsController__) */
