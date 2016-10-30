#include "Robot.hpp"

Robot::Robot(){
	set();
}

Robot::Robot(const float x, const float y){
	set();
	position.x = x;
	position.y = y;
}

Robot::Robot(const sf::Vector2f new_position){
	set();
	position = new_position;
}

void Robot::set(){
	position.x = 0;
	position.y = 0;
	health = 100;
	max_health = 100;
	energy = 100;
	max_energy = 100;
	dmg = 10;
	addType("robot");
}

void Robot::getVert(sf::VertexArray &vert){
	VertQuad quad;
	quad.set(sf::Vector2f(45,0), sf::Vector2f(50,50), position);
	quad.add(vert);
}