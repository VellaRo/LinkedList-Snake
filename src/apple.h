#ifndef apple_H
#define apple_H
#include <SFML/Graphics.hpp>
#include "snake.h"
class Apple
{
public:
    sf::CircleShape shape;

    Apple();
    ~Apple();
    void placeApple();
    void eatApple(Snake* snake);
};
#endif

