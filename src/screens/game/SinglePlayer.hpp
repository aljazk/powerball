#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include <SFML/Graphics.hpp>
#include "Pause.hpp"
#include "LevelComplete.hpp"
#include "GameOver.hpp"
#include "../../gui/GUI.hpp"
#include "../../collision/ObjectMap.hpp"
#include "ball/Ball.hpp"
#include "entities/Entities.hpp"
#include "level/Level.hpp"
#include "Camera.hpp"
#include <iostream>
#include <memory>

class SinglePlayer{
		std::string action;
		sf::Clock clock;
		sf::Texture back;
		sf::Vector2u backSize;
		float eclipsed;
		sf::Font font;
		sf::Text text;
		GUI gui;
		void createGUI();
		Level level;
		ObjectMap map;
		Ball ball;
		Entities ai;
	public:
		SinglePlayer();
		void setLevel(const Level &);
		void run(sf::RenderWindow &);
		std::string getAction(){ return action; }
};

#endif