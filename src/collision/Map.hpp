#ifndef MAP_H
#define MAP_H

#include "Collision.hpp"

class Map{
		std::vector<Polygon> polygons;
		std::vector<Circle> circles;
	public:
		Map();
		void clear();
		void add(Polygon &);
		void add(Circle &);
		void add(std::vector<Polygon> &);
		void add(std::vector<Circle> &);
		
		void checkCollision();
		void checkPolygonCollision();
		void checkCircleCollision();
		void checkCircleToPolygonCollision();
		
		void draw(sf::RenderWindow &);

};

#endif