#ifndef NORMALS_H
#define NORMALS_H

#include <unordered_set>
#include <vector>
#include <cfloat>
#include "Normal.hpp"
#include "Collision.hpp"
#include "shapes/Polygon.hpp"
#include "shapes/Circle.hpp"
#include <memory>

class Normals{
		std::unordered_set<std::shared_ptr<Normal>> normals;
		Polygon p1, p2;
		Circle c;
		bool circle_set;
	public:
		Normals();
		Normals(const Normal &);
		void add(float, float);
		void add(std::vector<float>, std::vector<float>);
		void add(const Normal &);
		bool checkSame(Normal &);
		void clear();
		void draw(sf::RenderWindow &);
		void setObjects(const Polygon &, const Polygon &);
		void setObjects(const Polygon &, const Circle &);
		void object1(const Polygon &);
		void object2(const Polygon &);
		void circle(const Circle &);
		bool checkCollision();
		sf::Vector2f collision(); //return the vector of the smallest collision overlap

};

#endif