#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"
#include "Bomb.h"
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
    //std::list<Bomb*> * _bombList;

public:

// Constructors/Destructors
//

	Player ();

    virtual ~Player ();


// Methods
//
    void shoot (std::string bulletType, std::string direction, std::list<Bullet*> * bulletList) override;

    void nextLevel();

    void score(std::string typeEnemy, unsigned int levelEnemy, unsigned int difficultyLevel);

    void activatedShild();

    std::string toString() override;

private :

    void initPlayer();





   // ACCESSOT METHODS
    public :

    unsigned int getLevel() const;

    unsigned int getShild() const;

    float getMoney() const;

    std::string getBulletType() const;

    void setLevel( unsigned int level);

    void setShild( unsigned int shild);

    void setBulletType( std::string bulletType);

    void setMoney( float money);



};

#endif // PLAYER_H
