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

std::unordered_set<std::shared_ptr<Polygon>> ObjectSetter::getPolygons1(){
	std::unordered_set<std::shared_ptr<Polygon>> return_p;
	for(unsigned int i=0; i<polygons.size(); i++){
		return_p.emplace(std::make_shared<Polygon>(polygons[i]));
	}
	return return_p;
}

std::unordered_set<std::shared_ptr<Circle>> ObjectSetter::getCircles1(){
	std::unordered_set<std::shared_ptr<Circle>> return_c;
	for(unsigned int i=0; i<circles.size(); i++){
		return_c.emplace(std::make_shared<Circle>(circles[i]));
	}
	return return_c;
}
