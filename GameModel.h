
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
<<<<<<< HEAD
    Settings * _settings;

=======
    Setting * _setting;
    Langage * _langage;
>>>>>>> 53b6521293fccb7775c0b160d4d2d48a9dd6342b

public :
// CONSTRUCTOR / DESTRUCTOR
//

	GameModel();

	~GameModel ();


// METHODS

    void nextStep();

    void newGame ();
    
    bool loadGame();

    void saveGame ();

    void play ();

    void nextLevel ();

    void newLevel ();

    void destructLevel();



// ACCESSOR METHODS

    Player* getPlayer() const;
    Level* getLevel() const;
    Shop* getShop() const;
    Settings* getSettings() const;



};

#endif // GAMEMODEL_H
