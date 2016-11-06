#ifndef LIGHTINGSCREEN_H
#define LIGHTINGSCREEN_H

#include <SFML/Graphics.hpp>
#include "../../../gui/GUI.hpp"
#include "Light.hpp"
#include "Lighting.hpp"
#include <sstream>
#include <iostream>

class LightingScreen{
		Lighting lighting;
		sf::Texture back;
		sf::Font font;
		sf::Text text;
		sf::Clock clock;
		float eclipsed;
		GUI gui;
		void createGUI();
	public:
		LightingScreen();
		void run(sf::RenderWindow &);
};

#endif