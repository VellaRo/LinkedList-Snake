#include <SFML/Graphics.hpp>  
#include <iostream>
#include "fonts.h"      // ArialFontDatei

void runMenu(sf::RenderWindow *window) {
   sf::Font font;
   if (!font.loadFromFile(ArialFontDatei)) {
      std::cerr << "Font nicht gefunden\n";
   }
   sf::Text text("Hello", font, 80);
   text.setFillColor(sf::Color::Black);
   
   while (window->isOpen()) {
      // Ereignisse abfragen
      sf::Event event;
      while (window->pollEvent(event)) {
         // ggf. Fenster schließen
        if (event.type == sf::Event::Closed) {
            window->close();
        }
      }
      window->clear(sf::Color::White); // ohne Param.: Black
      // hier alles zeichnen:
      window->draw(text);
      window->display();
   }
}
