#include <SFML/Graphics.hpp>  
#include <iostream>
#include "fonts.h"      // ArialFontDatei
#include "snake.h"

void runMenu(sf::RenderWindow *window) {
   sf::Font font;
   if (!font.loadFromFile(ArialFontDatei)) {
      std::cerr << "Font nicht gefunden\n";
   }
   sf::Text startGameText("StartGame", font, 40);
   startGameText.setFillColor(sf::Color::White);
   startGameText.setPosition( WINDOWSIZE -startGameText.getLocalBounds().width ,0);
   std::cout<<startGameText.getLocalBounds().width;
   
   
   while (window->isOpen()) {
      // Ereignisse abfragen
      sf::Event event;
      while (window->pollEvent(event)) {
         // ggf. Fenster schließen
        if (event.type == sf::Event::Closed) {
            window->close();
        }
      }
      window->clear(); // ohne Param.: Black
      // hier alles zeichnen:
      window->draw(startGameText);
      window->display();
   }
}
