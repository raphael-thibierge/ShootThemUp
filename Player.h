#ifndef PLAYER_H
#define PLAYER_H

#include "Ship.h"

const int NB_LIFE_INITIAL = 3 ;
const int Q_LIFE_INITIAL = 500 ;

class Player : virtual public Ship
{

private:
    std::string _bulletType;
    unsigned int _score;
    float _money;
    unsigned int _level;

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

    std::string toString() override;

private :

    void initPlayer();





   // ACCESSOT METHODS
    public :

    unsigned int getLevel() const;

    void setBulletType( std::string bulletType);



};

#endif // PLAYER_H
