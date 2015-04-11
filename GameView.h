
#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <stdio.h>
#include <string>
#include <vector>
#include "GameModel.h"




class GameView
{

private :

    GameModel * _model ;


public:

// Constructors/Destructors
//

	GameView ();

	virtual ~GameView ();

// Methods
//
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

#endif // GAMEVIEW_H
