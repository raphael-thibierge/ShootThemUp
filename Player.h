#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"
#include "Enemy.h"
#include <string>

//const int NB_LIFE_INITIAL = 3 ;
//const int Q_LIFE_INITIAL = 500 ;

class Player : virtual public Ship
{

private:
    unsigned int _bulletType;
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
    void useBomb(std::list<Enemy*> &enemyList, std::list<Blast*> &blastList, const int difficulty);

    void nextLevel();

    // shoot a bullet
    void shoot (std::list<Bullet*> * bulletList) override;

    void move(std::string direction);

    // update player's score, depend of enemy and difficulty
    void score(Enemy * enemy, const unsigned int difficulty);

    void activateShild();

    void resetPosition();

    // add money in function of the current score
    void addMoney();

    // add one bomb to player's inventory
    void addBomb();

    // add one life
    void addLife(const unsigned int number);

    void pay(const float value);

    std::string toString() override;


private :

    void initPlayer();

// ACCESSOT METHODS
//

public :

// GETTERS
//
    unsigned int getLevel() const;

    unsigned int getShield() const;

    float getMoney() const;

    unsigned int getScore() const;

    unsigned int getBulletType() const;

    unsigned int getBombNumber() const;


// SETTERS
//
    void setNbLife(const unsigned int nbLife);

    void setLevel( const unsigned int level);

    void setShield( const unsigned int shild);

    void setBulletType( const unsigned int bulletType);

    void setMoney( const float money);

    void setScore( const unsigned int score);

    void setBombNumber( const unsigned int value);

};

#endif // PLAYER_H
