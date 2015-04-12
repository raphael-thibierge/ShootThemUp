
#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <string>


#include "Level.h"
#include "Setting.h"
#include "Shop.h"
#include "Langage.h"

class GameModel
{

private:
    int _width;
    int _height;

    Player * _player;
    Level * _level;
    Shop * _shop;
    Setting * _setting;
    Langage * _langage;

public :
// Constructors/Destructors
//

	GameModel();

	~GameModel ();


// METHODS

    void nextStep();

    bool loadGame ();

    void newGame ();

    void saveGame ();

    void play ();

    void nextLevel ();

    void newLevel ();

    void destructLevel();



// ACCESSOR METHODS

    Player* getPlayer() const;
    Level* getLevel() const;



};

#endif // GAMEMODEL_H
