#include "GameModel.h"

using namespace std;

//
// CONSTRUCTOR AND DESTRUCTOR
//

GameModel::GameModel()
{
    //cout << "\n=====================" << endl;
    //cout << "CONSTRUCTOR GAMEMODEL" << endl;
    
    srand (time(NULL));
    
    _height = 500;
    _width = 200;
    _settings = new Settings;
    _player = nullptr;
    _level = nullptr;
    
}

GameModel::~GameModel()
{
    //cout << "\n=====================" << endl;
    //cout << "DESTRUCTION DE GAMEMODEL" << endl;
    
    destructLevel();
    delete _player;
    delete _shop;
    delete _level;
    delete _settings;
}

//
// Methods
//

void GameModel::nextStep()
{
    if (_player != nullptr){
        
        
        if(_level==nullptr && _player->getLevel()>0)
        {
            _level=new Level(_player, _settings->getDifficulty());
        }
        
        // fonction moteur du jeu
        // fonction qui fait tourner le jeu
        
        if ( _level != nullptr)
        {
            
            // le jeu continue
            int random= rand()%(-2);
            if(random==1)
            {
                for (auto enemy : *_level->getEnemies())
                {
                    random = rand()%(-3);
                    if(random==2)
                        enemy->shoot("standart", "SOUTH", this->getLevel()->getBullet());
                }
            }
            
            for (auto bullet : *_level->getBullet())
            {
                bullet->move();
            }
            
            _level->collisionManager();
            
            for (auto enemy : *_level->getEnemies())
            {
                enemy->move();
                
            }
            
            
            if (_level->loose())
            {
                destructLevel();
            }
            else if (_level->win()){
                destructLevel();
                _player->resetPosition();
            }
            
        }
    }
}


bool GameModel::loadGame ()
{
    // chargement d'une partie depuis un fichier
    return true;
}


void GameModel::newGame ()
{

    _player = new Player();
    _player->resetPosition();
    _shop = new Shop(_player);
}


void GameModel::saveGame ()
{
    // sauvegarde de l'ensemble de la partie.
    // a réaliser plus tard
}


void GameModel::play ()
{
    newLevel();
    _player->setNbLife(*_settings->getNbLife());
}


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
    _level = nullptr;
}


//
// ACCESSOR METHODS
//

Player* GameModel::getPlayer()
{
    return _player ;
}

Level* GameModel::getLevel()
{
    return _level;
}

Shop* GameModel::getShop()
{
    return _shop;
}

Settings* GameModel::getSettings()
{
    return _settings;
}