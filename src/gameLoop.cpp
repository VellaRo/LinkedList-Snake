//#include "gameLoop.h"
#include "apple.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>     
#include <iostream>
//#include "menu.h"
void drawSnake(Snake * snake, sf::RenderWindow * window);
void gameOver(Snake *snake , sf::RenderWindow *window);


void runMenu(sf::RenderWindow *window);
bool MenuOptionSelected =false;

void run(){
    sf::RenderWindow window(sf::VideoMode(WINDOWSIZE, WINDOWSIZE) , "SNAKE");
    Snake snake;
    Apple apple;    
    //Menu menu;

    if(MenuOptionSelected ==false){

           runMenu(&window);
        }
   else{
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
        //MOVE SNAKE
        snake.move(event);
         //CHECK IF APPLE EATEN // THAN PLACE APPLE
        apple.eatApple(&snake);
         
         //CHECK IF GAMEOVER
        gameOver(&snake , &window);

         //SetFrames
        window.setFramerateLimit(5);
        
        window.clear();
        window.draw(apple.shape);
        drawSnake(&snake, &window);
        window.display();
    }
    }
}
      


void drawSnake(Snake * snake, sf::RenderWindow * window){
   snake->temp = snake->head;
   while(snake->temp != NULL){
      window->draw(snake->temp->shape);
      snake->temp = snake->temp->next;
   }
}

void gameOver(Snake *snake , sf::RenderWindow *window){
   if(snake->hitItself()){
           std::cout<<"GAME OVER \n";

           window->close();
        }
          if(snake->shapeOutOfWindowBounds()){
             if(WALL == true){
                  std::cout<<"GAME OVER";
                  window->close();
                    
               }
            else{
               //muss noch gemacht werden
               snake->comeFromOtherSide();
            }
          }
          // PRINT HIGHSCORE
   std::cout<<"\nHIGHSCORE : "<<snake->size<<"\n";
}

// void runMenu(sf::RenderWindow *window){

//    sf::Font font;
//    font.loadFromFile("/usr/share/fonts/truetype/liberation2/LiberationSans-Regular.ttf");

//    sf::Text text;

//    text = sf::Text("hello", font, 80);
//    text.setFont(font);
//    text.setColor(sf::Color::Yellow);
//    window->draw(text);
//    window->clear(sf::Color::White);
//    window->display();
// }
