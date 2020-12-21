#include "apple.h"
#include "snake.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Apple::Apple(){
    this->shape  = sf::CircleShape(CIRCLERADIUS);
    std::cout<<"Apple generated  \n";
    this->shape.setFillColor(sf::Color::Red);    
    this->placeApple();

    }

Apple::~Apple(){
}
void Apple::placeApple(){
    std::cout<<"apple has been placed"<< "\n";
    int relaiveSpace = 600 - 40 / 40;  
    std::cout<<"hakko";  
    std::cout<<relaiveSpace;
    this->shape.setPosition(std::rand() % relaiveSpace* CIRCLESIZE, std::rand() % relaiveSpace *CIRCLESIZE);
    

}

void Apple::eatApple(Snake * snake){

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