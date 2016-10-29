#ifndef OBJECTADDING_H
#define OBJECTADDING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "GiftWrapping.hpp"
#include "../game/level/Level.hpp"

class ObjectAdding{
		std::vector<sf::Vector2f> points;
		sf::Vector2i mouse_position;
		bool mLeft, mRight;
		int mode;
	public:
		unsigned int gridSize;
		ObjectAdding();
		void key(const sf::Event &, const sf::RenderWindow &, Level &);
		void addPoint(const float, const float);
		void addPoint(sf::Vector2f);
		void popPoint();
		void reset();
		void draw(sf::RenderWindow &);
		void drawGrid(sf::RenderWindow &);

};

#endif