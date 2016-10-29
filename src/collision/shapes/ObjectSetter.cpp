#include "ObjectSetter.hpp"

ObjectSetter::ObjectSetter(){
	reset();
}

void ObjectSetter::reset(){
	position_x = 0, position_y = 0;
	velocity_x = 0, velocity_y = 0;
	rotation = 0;
	mass = 1, elasticity = 1;
}

void ObjectSetter::clear(){
	polygons.clear();
	circles.clear();
}

void ObjectSetter::add(const Polygon &p){
	polygons.push_back(p);
}

void ObjectSetter::add(const Circle &c){
	circles.push_back(c);
}

std::vector<Polygon> ObjectSetter::getPolygons(){
	return polygons;
}
std::vector<Circle> ObjectSetter::getCircles(){
	return circles;
}