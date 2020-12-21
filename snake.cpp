#include "snake.h"
#include <iostream>

void setPositionOfNewElement(Snakeelement * element);

 Snake::Snake()
    {   
        //TODO geleich mit eins anfacgen ?
        head = NULL;
        tail = NULL;
        temp = NULL;
        this->grow();
}
Snake::~Snake(){
    //TODO
}

bool Snake::isEmpty(){
    if(head == NULL){
        return true;
    }
    else
    {
        return false;
    }
    
}

void Snake::grow(){
    temp = new Snakeelement;
    temp->shape = sf::CircleShape(CIRCLESIZE);
    temp->prev =tail;
    temp->next = NULL;
    if(isEmpty()){
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail =temp;     
        this->setPositionOfNewElement();
    }
       
 }

void Snake::setPositionOfNewElement(){
   printf("setPOS");
   if(this->tail->prev->direction.x > 0){
   this->tail->shape.setPosition(this->tail->prev->shape.getPosition().x -2*this->head->shape.getRadius() ,
                           this->tail->prev->shape.getPosition().y);
   }
   if(this->tail->prev->direction.x < 0){
   this->tail->shape.setPosition(this->tail->prev->shape.getPosition().x +2*this->head->shape.getRadius() ,
                           this->tail->prev->shape.getPosition().y);
   }
   if(this->tail->prev->direction.y < 0){
   this->tail->shape.setPosition(this->tail->prev->shape.getPosition().x  ,
                           this->tail->prev->shape.getPosition().y +2*this->head->shape.getRadius());
   }
   if(this->tail->prev->direction.y < 0){
   this->tail->shape.setPosition(this->tail->prev->shape.getPosition().x  ,
                           this->tail->prev->shape.getPosition().y -2*this->head->shape.getRadius());
   }
}

void Snake::follow(){
   temp = head->next;
   while(this->temp != NULL){
                        if(this->temp->prev->direction.x == 0 && this->temp->prev->direction.y == SPEED){
                          // printf("down");
                           //down
                           this->temp->direction.x = 0;
                           this->temp->direction.y = SPEED;
                           this->temp->shape.setPosition(this->temp->prev->shape.getPosition().x , this->temp->shape.getPosition().y + this->temp->direction.y);
                        }
                         if(this->temp->prev->direction.x == 0 && this->temp->prev->direction.y == -SPEED){
                           //printf("up");
                           //up
                           this->temp->direction.x = 0;
                           this->temp->direction.y = -SPEED;
                     
                        }

                        if(this->temp->prev->direction.x == SPEED && this->temp->prev->direction.y == 0){
//printf("right");
                           //Right
                           this->temp->direction.x = SPEED;
                           this->temp->direction.y = 0;
                        }
                        if(this->temp->prev->direction.x == -SPEED && this->temp->prev->direction.y == 0){
                           //printf("left");
                           //Left
                           this->temp->direction.x = -SPEED;
                           this->temp->direction.y = 0;
                        }
                        //TOTOOOOOO
                        
                     temp = temp->next;
                  }
}
// Wohin kommt move??


void Snake::move(sf::Event event){
    switch (event.key.code)
               {
                  //up
               case sf::Keyboard::W:
               
                  this->head->direction.x = 0;
                  this->head->direction.y = -SPEED;
                  this->head->shape.setPosition(this->head->shape.getPosition().x +this->head->direction.x , this->head->shape.getPosition().y + this->head->direction.y);
                  //this->follow();
                  //std::cout<<event.key.code<<"\n";
                  break;
                  //down 
               case sf::Keyboard::S:
                  this->head->direction.x = 0;
                  this->head->direction.y = SPEED;
                  this->head->shape.setPosition(this->head->shape.getPosition().x +this->head->direction.x , this->head->shape.getPosition().y + this->head->direction.y);
                  //this->follow();
                  // direction.x = 0;
                  // direction.y = SPEED;
                  // shape.setPosition(shape.getPosition().x +direction.x , shape.getPosition().y + direction.y);
                 // std::cout<<event.key.code<<"\n";
                  break;
                  //right
               case sf::Keyboard::D:
                  this->head->direction.x = SPEED;
                  this->head->direction.y = 0;
                  this->head->shape.setPosition(this->head->shape.getPosition().x +this->head->direction.x , this->head->shape.getPosition().y + this->head->direction.y);
                 // this->follow();
                  // direction.x = SPEED;
                  // direction.y = 0;
                  // shape.setPosition(shape.getPosition().x + direction.x , shape.getPosition().y + direction.y);
                 // std::cout<<event.key.code<<"\n";
                 // std::cout<<shape.getPosition().x<<"\n";
                  break;
                  //left
               case sf::Keyboard::A:
                  this->head->direction.x = -SPEED;
                  this->head->direction.y = 0;
                  this->head->shape.setPosition(this->head->shape.getPosition().x +this->head->direction.x , this->head->shape.getPosition().y + this->head->direction.y);
                 // this->follow();
               // direction.x = -SPEED;
               // direction.y = 0;
               //    shape.setPosition(shape.getPosition().x +direction.x , shape.getPosition().y + direction.y);
                  //std::cout<<event.key.code<<"\n";
                  break;

               default:

               break;
               }
               
    }



bool Snakeelement::shapeOutOfWindowBounds(){
      if(shape.getPosition().x < 0 -shape.getRadius() ||
         shape.getPosition().x > WINDOWSIZE - (shape.getRadius()) ||
         shape.getPosition().y < 0 -shape.getRadius()||
         shape.getPosition().y > WINDOWSIZE - (shape.getRadius())
         ){
         return true;
      }
      return false;
   }

void Snakeelement::comeFromOtherSide(){
if( shapeOutOfWindowBounds()){
               if(direction.x > 0){
                  shape.setPosition(0.0,shape.getPosition().y);    
               }
               if(direction.x < 0){
                  shape.setPosition(WINDOWSIZE - shape.getRadius(), shape.getPosition().y);    
               }
               if(direction.y > 0){
                  shape.setPosition(shape.getPosition().x , 0.0);    
               }
               if(direction.y < 0){
                  shape.setPosition(shape.getPosition().x ,WINDOWSIZE - shape.getRadius());    
               }

            }
    }


