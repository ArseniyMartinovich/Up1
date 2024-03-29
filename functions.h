#pragma once
#include "SFML/Graphics.hpp"
#include "bat.h"
#include "ball.h"

void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}



void updateGame(Bat& bat, Ball& ball) {
	batControl(bat);
	batReboundEdges(bat);
	ballUpdate(ball);
}



void checkCollisions() {}

void drawGame(sf::RenderWindow& window, Bat& bat, Ball& ball) {
	window.clear();
	batDraw(window, bat);
	ballDraw(window, ball);
	window.display();
	
}
