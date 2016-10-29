#include "Circle.hpp"

Circle::Circle(){
	set(100, 100, 10);
}

Circle::Circle(float x, float y){
	set(x, y, 10);
}

Circle::Circle(float x, float y, float r){
	set(x, y, r);
}

void Circle::set(float x, float y, float r){
	position.x = x;
	position.y = y;
	radius = r;
	colliding = false;
}

float Circle::getX(){
	return position.x;
}

float Circle::getY(){
	return position.y;
}

float Circle::getR(){
	return radius;
}

void Circle::setPosition(float x, float y){
	position.x = x;
	position.y = y;
}

void Circle::transfer(float x, float y){
	position.x += x;
	position.y += y;
}

void Circle::draw(sf::RenderWindow &window){
	VertCircle circ(position, radius);
	circ.setColor(sf::Color::White);
	if(colliding){
		circ.setColor(sf::Color::Yellow);
		colliding = false;
	}
	sf::VertexArray vert(sf::TrianglesStrip);
	circ.add(vert);
	window.draw(vert);
}

void Circle::getVert(sf::VertexArray &vert){
	VertCircle circ(position, radius);
	circ.setColor(sf::Color::White);
	if(colliding){
		circ.setColor(sf::Color::Yellow);
		colliding = false;
	}
	circ.addLine(vert);
}