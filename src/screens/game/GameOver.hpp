#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics.hpp>
#include "../../gui/GUI.hpp"
#include <iostream>
#include <sstream>

class GameOver{
		sf::Texture background;
		std::string action;
		GUI gui;
		void createInter();
	public:
		GameOver();
		void run(sf::RenderWindow &);
		std::string getAction();
};

#endif