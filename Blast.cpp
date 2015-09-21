#include "Blast.h"

using namespace std;

Blast::Blast(const unsigned int type, const std::string direction, const float speed, const float X, const float Y) : _type(type), _direction(direction), _speed(speed)
{
    _time.restart();
    setPosition(X, Y);

    _soundBuffer.loadFromFile(SOUND_BLAST);
    _sound.setBuffer(_soundBuffer);
    playSound();
}

void Blast::move()
{
    RectanglePosition::move(_direction, _speed);
}

unsigned int Blast::getType()
{
    return _type;
}

float Blast::getTime()
{
    return _time.getElapsedTime().asSeconds();
}

void Blast::playSound()
{
    _sound.play();
}
