#include "apple.h"
#include "snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//constructor
Apple::Apple(){
    this->shape  = sf::CircleShape(CIRCLERADIUS);
    this->shape.setFillColor(sf::Color::Red);    
    this->placeApple();

    }
//destructor
Apple::~Apple(){
    //TODO //Audio Noise ???
}
void Apple::placeApple(){
    int relaiveSpace = (WINDOWSIZE - CIRCLESIZE) / CIRCLESIZE;  
    this->shape.setPosition(std::rand() % relaiveSpace* CIRCLESIZE, std::rand() % relaiveSpace *CIRCLESIZE);
    

}

void Apple::eatApple(Snake * snake){
    //check if head in range apple
    sf::Vector2f positionHead = snake->head->shape.getPosition();
    float radiusHead = snake->head->shape.getRadius();
    if(positionHead.x +radiusHead >= this->shape.getPosition().x && 
       positionHead.x -radiusHead <= this->shape.getPosition().x &&
       positionHead.y +radiusHead >= this->shape.getPosition().y && 
       positionHead.y -radiusHead <= this->shape.getPosition().y){
           snake->grow();
           this->placeApple();
    }
}