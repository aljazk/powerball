#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <SFML/Graphics.hpp>
#include "../../gui/GUI.hpp"
#include "../game/level/Level.hpp"
#include "ObjectAdding.hpp"
#include "EditorCamera.hpp"
#include <iostream>

class MapEditor{
		sf::Font font;
		sf::Text text;
		GUI gui;
		void createGUI();
		Level level;
	public:
		MapEditor();
		void run(sf::RenderWindow &);
};

#endif