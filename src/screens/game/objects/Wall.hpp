#ifndef WALL_H
#define WALL_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "../level/Read.hpp"
#include "../../../collision/shapes/Polygon.hpp"

class Wall{
		std::vector<float> x, y;
	public:
		Wall();
		Wall(std::vector<float>, std::vector<float>);
		Wall(std::vector<sf::Vector2f>);
		void add(float, float);
		void add(sf::Vector2f);
		std::string get();
		Polygon getPoly();
		void getVert(sf::VertexArray &);

};

#endif