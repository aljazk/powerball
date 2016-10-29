#include "Wall.hpp"

Wall::Wall(){
	
}

Wall::Wall(std::vector<float> n_x, std::vector<float> n_y){
	x = n_x;
	y = n_y;
}

Wall::Wall(std::vector<sf::Vector2f> pos){
	for(unsigned int i=0; i<pos.size(); i++){
		x.push_back(pos[i].x);
		y.push_back(pos[i].y);
	}
}

void Wall::add(float n_x, float n_y){
	x.push_back(n_x);
	y.push_back(n_y);
}

void Wall::add(sf::Vector2f p){
	x.push_back(p.x);
	y.push_back(p.y);
}

std::string Wall::get(){
	std::string return_string;
	for(unsigned int i=0; i<x.size(); i++){
		int rx = x[i];
		int ry = y[i];
		return_string += Read::fromInt(rx) + "," + Read::fromInt(ry) + ",";
	}
	return_string.pop_back();
	return_string += ";\n";
	std::cout << return_string << std::endl;
	return return_string;
}

Polygon Wall::getPoly(){
	Polygon p;
	p.setPoints(x, y);
	return p;
}

void Wall::getVert(sf::VertexArray &vert){
	sf::Vertex v;
	v.color = sf::Color::White;
	for(unsigned int i=0; i<x.size(); i++){
		v.position.x = x[i];
		v.position.y = y[i];
		vert.append(v);
	}
}