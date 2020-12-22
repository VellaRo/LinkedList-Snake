#include "snake.h"
#include <iostream>

void setPositionOfNewElement(Snakeelement * element);
//CONSTRUCTOR
 Snake::Snake()
    {   
        //TODO geleich mit eins anfacgen ?
        head = NULL;
        tail = NULL;
        temp = NULL;
        size = 0;
        this->grow();
        head->shape.setFillColor(sf::Color::Yellow);
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
    size++;
    temp = new Snakeelement;
    temp->shape = sf::CircleShape(CIRCLERADIUS);
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
   if(this->tail->prev->direction.y > 0){
   this->tail->shape.setPosition(this->tail->prev->shape.getPosition().x  ,
                           this->tail->prev->shape.getPosition().y -2*this->head->shape.getRadius());
   }
}

void Snake::follow(){
   
   this->temp = this->tail;
   while(temp->prev != NULL){
      this->temp->direction = this->temp->prev->direction;
      this->temp = this->temp->prev;
   }
   this->temp = head->next;
   while(this->temp != NULL){
                     this->temp->shape.setPosition(this->temp->prev->shape.getPosition().x - this->temp->direction.x ,this->temp->prev->shape.getPosition().y - this->temp->direction.y);
                     this->temp = this->temp->next;
                  }
}

void Snake::move(sf::Event event){
    switch (event.key.code)
               {
                  //up
               case sf::Keyboard::W:
                  //if direction == Opposite
                  if(this->head->direction.y != SPEED){
                     
                     this->head->direction.x = 0;
                     this->head->direction.y = -SPEED; 
                  }   
                  else{ //MOVEMENT DOWN
                     
                     this->head->direction.x = 0;
                     this->head->direction.y = SPEED;
                  }
               this->head->shape.setPosition(this->head->shape.getPosition().x +this->head->direction.x , this->head->shape.getPosition().y + this->head->direction.y);
                  this->follow();
                  break;
                  //down 
               case sf::Keyboard::S:
                  //if direction == Opposite
                  if(this->head->direction.y != -SPEED){
                     
                     this->head->direction.x = 0;
                     this->head->direction.y = SPEED;

                  }
                  // MOVEMENT UP
                  else
                  {
                     this->head->direction.x = 0;
                     this->head->direction.y = -SPEED;
                  }
                     this->head->shape.setPosition(this->head->shape.getPosition().x +this->head->direction.x , this->head->shape.getPosition().y + this->head->direction.y);
                     this->follow();  
                  break;
                  //right
               case sf::Keyboard::D:
               //if direction == Opposite
                  if(this->head->direction.x != -SPEED){
                     this->head->direction.x = SPEED;
                     this->head->direction.y = 0;
                  
                  }
                  else{ //MOVEMENT LEFT
                     this->head->direction.x = -SPEED;
                     this->head->direction.y = 0;            
                  }
                  this->head->shape.setPosition(this->head->shape.getPosition().x +this->head->direction.x , this->head->shape.getPosition().y + this->head->direction.y);
                  this->follow();
                  break;
                  //left
               case sf::Keyboard::A:
                  //if direction == Opposite
                  if(this->head->direction.x != SPEED){
                     this->head->direction.x = -SPEED;
                     this->head->direction.y = 0;
                  }
                  //RIGHT
                  else
                  {// MOVEMENT RIGHT
                     this->head->direction.x = SPEED;
                     this->head->direction.y = 0;                
                   }
                  
                  this->head->shape.setPosition(this->head->shape.getPosition().x +this->head->direction.x , this->head->shape.getPosition().y + this->head->direction.y);
                  this->follow();
                  break;
               default:

               break;

               }
               
    }



bool Snake::shapeOutOfWindowBounds(){
      this->temp = this->head;
      while(temp != NULL){
      if(this->temp->shape.getPosition().x < 0 -this->temp->shape.getRadius() ||
         this->temp->shape.getPosition().x > WINDOWSIZE - (this->temp->shape.getRadius()) ||
         this->temp->shape.getPosition().y < 0 -this->temp->shape.getRadius()||
         this->temp->shape.getPosition().y > WINDOWSIZE - (this->temp->shape.getRadius())
         ){
         return true;
         }
         this->temp = this->temp->next;
      }
         return false;
   }

void Snake::comeFromOtherSide(){
   //TODO
this->temp = this->head;
      while(this->temp != NULL){
               if(this->temp->direction.x > 0){
                  this->temp->shape.setPosition(0.0,this->temp->shape.getPosition().y);    
               }
               if(this->temp->direction.x < 0){
                  this->temp->shape.setPosition(WINDOWSIZE - 2* this->temp->shape.getRadius(), this->temp->shape.getPosition().y);    
               }
               if(this->temp->direction.y > 0){
                  this->temp->shape.setPosition(this->temp->shape.getPosition().x , 0.0);    
               }
               if(this->temp->direction.y < 0){
                  this->temp->shape.setPosition(this->temp->shape.getPosition().x ,WINDOWSIZE - 2*this->temp->shape.getRadius());    
               }
    this->temp = this->temp->next;
    }
}

bool Snake::hitItself(){
   this->temp =this->head->next;
   while(this->temp != NULL){
      if(head->shape.getPosition().x == temp->shape.getPosition().x &&
         head->shape.getPosition().y == temp->shape.getPosition().y){
            return true;
      }
   temp = temp->next;
   }
   return false;
}

