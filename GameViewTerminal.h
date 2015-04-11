//
//  GameViewTerminal.h
//  ShmupTerminal
//
//  Created by Raphael Thibierge on 09/04/2015.
//  Copyright (c) 2015 Raphael Thibierge. All rights reserved.
//

#ifndef __ShmupTerminal__GameViewTerminal__
#define __ShmupTerminal__GameViewTerminal__

#include <stdio.h>
#include "GameModel.h"




class GameViewTerminal
{
    
    private :
    
    GameModel * _model ;
    
    
public:
    
    // Constructors/Destructors
    //
    
    GameViewTerminal ();
    
    virtual ~GameViewTerminal ();
    
    // Methods
    //
    bool treatEvent();
    
    /**
     */
    void showMenu () const;
    
    
    void showShop () const;
    /**
     */
    void showLanguage () const;
    
    /**
     */
    void showStore () const;
    
    /**
     */
    void showBestScore () const;
    
    /**
     */
    void showScore () const;
    
    /**
     */
    void showGame () const;
    
    /**
     */
    void showIntroduction () const;
    
    
    // ACCESSEURS
    void setModel(GameModel * model);
    
    
};















#endif /* defined(__ShmupTerminal__GameViewTerminal__) */
