#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include <vector>
#include<Windows.h>
#include "player.h"
#include "background.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	Background background;
public:


	Game() {
		window.create(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);

		window.setFramerateLimit(FPS);

	}

	void chek_events() {
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				
				window.close();
		}
	}


	void update() {
		player.update();
		background.update();
	}


	void chek_collisons() {
	}
	void draw() {
		window.clear();
		background.draw(window);
		player.draw(window);
		window.display();
	}

	void play() {
		while (window.isOpen())
		{
			chek_events();
			update();
			chek_collisons();
			draw();
		}
	}
};