#include "Light.hpp"

Light::Light(){
	set(0,0);
}

Light::Light(const float set_x, const float set_y){
	set(set_x, set_y, 0);
}

Light::Light(const float set_x, const float set_y, const float set_size){
	set(set_x, set_y, set_size, sf::Color::White);
}

Light::Light(const float set_x, const float set_y, const float set_size, const sf::Color &set_color){
	setPosition(set_x, set_y);
	setSize(set_size);
	setColor(set_color);
}

void Light::set(const float set_x, const float set_y){
	set(set_x, set_y, 0);
}

void Light::set(const float set_x, const float set_y, const float set_size){
	set(set_x, set_y, set_size, sf::Color::White);
}

void Light::set(const float set_x, const float set_y, const float set_size, const sf::Color &set_color){
	setPosition(set_x, set_y);
	setSize(set_size);
	setColor(set_color);
}

void Light::setPosition(const float set_x, const float set_y){
	x = set_x;
	y = set_y;
}

void Light::setSize(const float set_size){
	size = set_size;
}

void Light::setColor(const sf::Color &set_color){
	color = set_color;
}

void Light::getVert(sf::VertexArray &vert){
	VertQuad v(sf::Vector2f(0,0), sf::Vector2f(100,100), sf::Vector2f(x,y), sf::Vector2f(size, size));
	v.setColor(color);
	v.add(vert);
}