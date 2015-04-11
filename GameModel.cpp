#include "GameModel.h"

using namespace std;

// Constructors/Destructors
//

GameModel::GameModel() {
    cout << "\n=====================" << endl;
    cout << "CONSTRUCTOR GAMEMODEL" << endl;

    _height = 500;
    _width = 200;
    _player = new Player;
    _shop = new Shop;
    _level = nullptr;
    newLevel();
}

GameModel::~GameModel() {
    cout << "\n=====================" << endl;
    cout << "DESTRUCTION DE GAMEMODEL" << endl;

    destructLevel();
    delete _player;
}

//
// Methods
//

void GameModel::nextStep(){


    // fonction moteur du jeu
    // fonction qui fait tourner le jeu

    if (!_level->win()){
        if (!_level->loose()) {
        // le jeu continue

        for (auto enemy : *_level->getEnemy()){
            enemy->move();

        }

        for (auto bullet : *_level->getBullet()){
            bullet->move();
        }

        _level->collisionManager();


        }
    }

    else {
        nextLevel();
    }
}

/**
 */
bool GameModel::loadGame ()
{
    // chargement d'une partie depuis un fichier
    return true;
}

/**
 */
void GameModel::newGame ()
{
    // création d'une nouvelle partie
}

/**
 */
void GameModel::saveGame ()
{
    // sauvegarde de l'ensemble de la partie.
    // a réaliser plus tard
}

/**
 */
void GameModel::play ()
{

}

/**
 */
void GameModel::nextLevel ()
{
    delete _level;
    _player->nextLevel();
    _level = new Level(_player);
}


void GameModel::newLevel ()
{
    if (_level != nullptr)
        destructLevel();
    _level = new Level(_player);
}

void GameModel::destructLevel()
{
    delete _level;
}


// Accessor methods
//

Player* GameModel::getPlayer()  const{
    return _player ;
}

Level* GameModel::getLevel() const {

    return _level;
}








// Other methods
//



