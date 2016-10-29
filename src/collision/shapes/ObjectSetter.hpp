#ifndef OBJECTSETTER_H
#define OBJECTSETTER_H

#include "Polygon.hpp"
#include "Circle.hpp"
#include <vector>

class ObjectSetter{
		std::vector<Polygon> polygons;
		std::vector<Circle> circles; // make so it can be made out of multiple shapes -- just skip collision if they have same object id
	public:
		ObjectSetter();
		void reset();
		void clear();
		void add(const Polygon &);
		void add(const Circle &);

		float position_x, position_y;
		float velocity_x, velocity_y;
		float rotation; // make rotations
		float mass, elasticity;
		
		std::vector<Polygon> getPolygons();
		std::vector<Circle> getCircles();
};

#endif