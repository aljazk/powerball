#ifndef COLLISION_H
#define COLLISION_H

#include "shapes/Circle.hpp"
#include "shapes/Polygon.hpp"
#include "Normals.hpp"

class Collision{
		
	public:
		Collision();
		static bool check(Polygon &, Polygon &);
		static sf::Vector2f get(Polygon &, Polygon &);
		static bool check(Circle &, Circle &);
		static sf::Vector2f get(Circle &, Circle &);
		static bool check(Polygon &, Circle &);
		static bool check(Circle &, Polygon &);
		static bool checkTest(Polygon &, Circle &, sf::RenderWindow &);
		static bool checkTest(Circle &, Polygon &, sf::RenderWindow &);
		static sf::Vector2f get(Polygon &, Circle &);
		static sf::Vector2f get(Circle &, Polygon &);
};

#endif