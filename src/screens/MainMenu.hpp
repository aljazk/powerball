#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include "../gui/GUI.hpp"
#include "GameScreen.hpp"
#include "mapeditor/MapEditor.hpp"
#include <iostream>
#include <sstream>


class MainMenu{
		sf::Texture back;
		void gameMainMenu(int);
		void pauseMainMenu();
		void gameOver(int);
		sf::RenderWindow window;
		int windowX, windowY;
		sf::Font font;
		sf::Text text;
		sf::Clock clock;
		float eclipsed;
		bool mouseDown, rightMouseDown;
		GUI gui;
		void createGUI();
    public:
		MainMenu();
		void run(sf::RenderWindow &);
};

#endif
