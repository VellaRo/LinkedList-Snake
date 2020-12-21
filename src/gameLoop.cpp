//#include "gameLoop.h"
#include "apple.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>     
#include <iostream>

void drawSnake(Snake * snake, sf::RenderWindow * window);

void run(){
    sf::RenderWindow window(sf::VideoMode(WINDOWSIZE, WINDOWSIZE) , "SNAKE");
    Snake snake;
    Apple apple;
    //apple.placeApple();
    //apple.shape.setFillColor(sf::Color::Green);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
           switch (event.type)
           {
           case sf::Event::Closed:
              window.close();
              break;

            default:
              break;
           }  
        }

        window.clear();
        window.draw(apple.shape);
        drawSnake(&snake, &window);
        window.display();
        snake.move(event);
        //snake.follow();
        //snake.follow();
        window.setFramerateLimit(5);
         if(snake.head->shapeOutOfWindowBounds()){
                 snake.head->comeFromOtherSide();   
               }
         apple.eatApple(&snake);
         
         ///TEST
         // std::cout<<snake.head->shape.getPosition().x<<"\n";
         // std::cout<<snake.head->shape.getPosition().y<<"\n";
         // std::cout<<apple.shape.getPosition().x<<"\n";
         // std::cout<<apple.shape.getPosition().y<<"\n";
    }
      
}

void drawSnake(Snake * snake, sf::RenderWindow * window){
  // int i= 0;
   snake->temp = snake->head;
   while(snake->temp != NULL){
      window->draw(snake->temp->shape);
      snake->temp = snake->temp->next;
     // printf("size %i : ",i++);
   }
}




