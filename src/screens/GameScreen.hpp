#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include "game/SinglePlayer.hpp"
#include "game/level/Level.hpp"
#include "game/level/LevelSelect.hpp"
#include <iostream>
#include <sstream>

class GameScreen{
	public:
		GameScreen();
		static void run(sf::RenderWindow &);
		static void run(sf::RenderWindow &, std::string);
};

#endif