#include "GameModel.h"

using namespace std;

// CONSTRUCTOR AND DESTRUCTOR
//

GameModel::GameModel() {
    cout << "\n=====================" << endl;
    cout << "CONSTRUCTOR GAMEMODEL" << endl;

    _height = 500;
    _width = 200;
    _settings = new Settings;
    _player = nullptr;

    _level = nullptr;

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

    if (_player != nullptr && _level != nullptr){

        if (!_level->win()){
            if (!_level->loose()) {
                // le jeu continue
                int random= rand()%(-2);
                if(random==1)
                {
                    for (auto enemy : *_level->getEnemy())
                    {
                        random = rand()%(-3);
                        if(random==2)
                        
                            enemy->shoot("standart", "SOUTH", this->getLevel()->getBullet());
                    }
                }

                _level->collisionManager();

                for (auto enemy : *_level->getEnemy()){
                    enemy->move();

                }

                for (auto bullet : *_level->getBullet()){
                    bullet->move();
                }




            }
        }

        else {
            nextLevel();
        }
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

    _player = new Player();
    _shop = new Shop(_player);
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
    newLevel();
}

/**
 */
void GameModel::nextLevel ()
{
    delete _level;
    _player->nextLevel();
    _level = new Level(_player, _settings->getDifficulty());
}


void GameModel::newLevel ()
{
    if (_level != nullptr)
        destructLevel();
    _level = new Level(_player, _settings->getDifficulty());
}

void GameModel::destructLevel()
{
    delete _level;
}


// ACCESSOR METHODS
//

Player* GameModel::getPlayer(){
    return _player ;
}

Level* GameModel::getLevel(){
    return _level;
}

Shop* GameModel::getShop(){
    return _shop;
}

Settings* GameModel::getSettings(){
    return _settings;
}








// Other methods
//



