#ifndef SNAKE_H
#define SNAKE_H

#define CIRCLERADIUS 20.f 
#define CIRCLESIZE 40
#define SPEED 40
#define WINDOWSIZE 600

const bool WALL = true;

#include <SFML/Graphics.hpp>


class Snakeelement{

  public:
  Snakeelement *next;
  Snakeelement *prev;
  sf::CircleShape shape; 
  sf::Vector2f direction;

  // Snakeelement();
  void setPositionOfNewElement();
  //void move(sf::Event event);
};

class Snake{

public:
  Snakeelement * head;
  Snakeelement * tail;
  Snakeelement * temp;

  int size;
  
  explicit Snake();
  ~Snake();
  void grow();
  bool isEmpty();
  void setPositionOfNewElement();
  void follow();
  void move(sf::Event event); //TODO
  void comeFromOtherSide();
  bool shapeOutOfWindowBounds();
  bool hitItself();


};
#endif