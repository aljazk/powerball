#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <SFML/Graphics.hpp>
#include "../../../gui/GUI.hpp"
#include <iostream>
#include <sstream>

class LevelSelect{
		sf::Font font;
		sf::Text text;
		sf::Clock clock;
		float eclipsed;
		sf::Texture back;
		sf::Vector2u backSize;
		GUI gui;
		void createInter();
	public:
		LevelSelect();
		std::string run(sf::RenderWindow &);
};

#endif