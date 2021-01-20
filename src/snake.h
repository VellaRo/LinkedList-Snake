#ifndef SNAKE_H
#define SNAKE_H

#define CIRCLERADIUS 20.f 
#define CIRCLESIZE 40
#define SPEED 40
#define WINDOWSIZE 600

//Boundarais
const bool WALL = true;

#include <SFML/Graphics.hpp>

// Sankeelement CircleShaped
class Snakeelement{

  public:
  Snakeelement *next;
  Snakeelement *prev;
  sf::CircleShape shape; 
  sf::Vector2f direction;

  void setPositionOfNewElement();
};


class Snake{

public:
  Snakeelement * head;
  Snakeelement * tail;
  Snakeelement * temp;

  int size;
  
  //constructor
  explicit Snake();
  
  //destructor
  ~Snake();
  
  void grow();
  bool isEmpty();
  void setPositionOfNewElement(); 
  void follow();
  void move(sf::Event event);
  void comeFromOtherSide();
  bool shapeOutOfWindowBounds();
  bool hitItself();

};
#endif