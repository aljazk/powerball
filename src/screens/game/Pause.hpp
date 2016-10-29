#ifndef PAUSE_H
#define PAUSE_H

#include <SFML/Graphics.hpp>
#include "../../gui/GUI.hpp"
#include <iostream>
#include <sstream>

class Pause{
		sf::Texture background;
		std::string action;
		GUI gui;
		void createGUI();
	public:
		Pause();
		void run(sf::RenderWindow &);
		std::string getAction();
};

#endif