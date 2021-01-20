#include "snake.h"
#include <iostream>

void setPositionOfNewElement(Snakeelement * element);
//CONSTRUCTOR
 Snake::Snake()
    {   

        head = NULL;
        tail = NULL;
        temp = NULL;
        size = 0;

        //Starts with head
        this->grow();
        head->shape.setFillColor(sf::Color::Yellow);
}
Snake::~Snake(){
    std::cout << "GAME OVER" << "\n";
    std::cout << "HIGHSCORE: " <<this->size << "\n";
}

//Check if Snake empty 
bool Snake::isEmpty(){
    if(head == NULL){
        return true;
    }
    else
    {
        return false;
    }
    
}
 
//Snake gets new Snakeelement when Apple eaten
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

//Help for grow() 
   //setsnew Element at right Position
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

//all Elements Except Head follow the next Element
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

// Move the Head
      //Check if opposite pressed (Down ,UP ==> Snakes stillgoes down)
void Snake::move(sf::Event event){
    switch (event.key.code)
               {
                  //up
               case sf::Keyboard::W:
               //Fallthrough
               case sf::Keyboard::Up:
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
               //Fallthrough
               case sf::Keyboard::Down:
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
               //Fallthrough
               case sf::Keyboard::Right:
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
               //Fallthrough
               case sf::Keyboard::Left:
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


//Check if Wall is hit
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
//TODO 
   /*
   * When head goes througwall appear from other side 
   * PROBLEM: FOLLOW METHODE funktionsweiße
   * 
   * 
      */
void Snake::comeFromOtherSide(){
   
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

//Chech if SnakeHead hit Snakebody
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

