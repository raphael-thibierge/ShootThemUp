#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"
#include "Enemy.h"
#include <string>

const int NB_LIFE_INITIAL = 3 ;
const int Q_LIFE_INITIAL = 500 ;

class Player : virtual public Ship
{

private:
    std::string _bulletType;
    unsigned int _score;
    float _money;
    unsigned int _level;
    unsigned int _shild;
    unsigned int _bombNumber;

public:

// CONSTRUCTOR AND DESTRUCTOR
//

	Player ();

    virtual ~Player ();


// METHODS
//
    
    // player use a bomb if he has one
    void useBomb(std::list<Enemy*> &enemyList, const int difficulty);

    void nextLevel();
    // shoot a bullet
    void shoot (std::list<Bullet*> * bulletList) override;

    // update player's score, depend of enemy and difficulty
    void score(Enemy * enemy, unsigned int difficulty);

    void activateShild();
    
    // payer loose one life
    void looseLife();

    // affect damage to player
    void affectDamage(unsigned int damage);

    void resetPosition();

    void resetLifeLevel();

    // add money in function of the current score
    void addMoney();

    std::string toString() override;


private :

    void initPlayer();

// ACCESSOT METHODS
//

public :

// GETTERS
//
    unsigned int getLevel() const;

    unsigned int getShild() const;

    float getMoney() const;

    unsigned int getScore() const;

    std::string getBulletType() const;
    
    unsigned int getBombNumber() const;
    
    
// SETTERS
//
    void setNbLife(unsigned int nbLife);

    void setLevel( unsigned int level);

    void setShild( unsigned int shild);

    void setBulletType( std::string bulletType);

    void setMoney( float money);

    void setScore(unsigned int score);

    void setBombNumber(unsigned int value);

};

#endif // PLAYER_H
