#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include "../../../gui/GUI.hpp"
#include "../objects/Wall.hpp"
#include "../../../collision/shapes/ObjectSetter.hpp"
#include "Read.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Level{
		void loadLine(std::string);
		
		std::vector<Wall> walls;
	public:
		Level();
		void load();
		void load(const std::string &);
		void save();
		void save(const std::string &);
		void clear();
		void draw(sf::RenderWindow &);
		
		void addWall(std::string);
		void addWall(const std::vector<sf::Vector2f> &);
		const std::vector<Wall> & getWalls(){
			return walls;
		}
		ObjectSetter getWallObject();
};

#endif