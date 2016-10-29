#ifndef LAVELCOMPLETE_H
#define LEVELCOMPLETE_H

#include <SFML/Graphics.hpp>
#include "../../gui/GUI.hpp"
#include <iostream>
#include <sstream>

class LevelComplete{
		sf::Texture background;
		std::string action;
		GUI gui;
		void createGUI();
	public:
		LevelComplete();
		void run(sf::RenderWindow &);
		std::string getAction();
		
};

#endif