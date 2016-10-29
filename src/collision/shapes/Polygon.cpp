#include "Polygon.hpp"

Polygon::Polygon(){
	addPoint(100,100);
	addPoint(150,100);
	addPoint(125,150);
	colliding = false;
	position.x = 0;
	position.y = 0;
}

Polygon::Polygon(std::vector< sf::Vector2f > set_points){
	setPoints(set_points);
	colliding = false;
	position.x = 0;
	position.y = 0;
}

void Polygon::addPoint(float x,float y){
	addPoint(sf::Vector2f(x,y));
}

void Polygon::addPoint(sf::Vector2f new_point){
	points.push_back(new_point);
}

void Polygon::setPoints(std::vector< sf::Vector2f > set_points){
	points = set_points;
}

void Polygon::setPoints(std::vector< float > set_point_x, std::vector< float > set_point_y){
	points.clear();
	for(unsigned int i=0; i<set_point_x.size(); i++){
		points.push_back(sf::Vector2f(set_point_x[i], set_point_y[i]));
	}
}
void Polygon::draw(sf::RenderWindow &window){
	sf::VertexArray vert(sf::LinesStrip);
	sf::Vertex vertex;
	vertex.color = sf::Color::White;
	if (colliding){
		vertex.color = sf::Color::Yellow;
		colliding = false;
	}
	for(unsigned int i=0; i<points.size(); i++){
		vertex.position = points[i] + position;
		vert.append(vertex);
	}
	vertex.position = points[0] + position;
	vert.append(vertex);
	window.draw(vert);
}

void Polygon::getVert(sf::VertexArray &vert){	
	sf::Vertex vertex;
	sf::Color color;
	color = sf::Color::White;
	if (colliding){
		color = sf::Color::Yellow;
		colliding = false;
	}
	vertex.position = points[0] + position;
	vertex.color = sf::Color::Transparent;
	vert.append(vertex);
	vertex.color = color;
	for(unsigned int i=0; i<points.size(); i++){
		vertex.position = points[i] + position;
		vert.append(vertex);
	}
	vertex.position = points[0] + position;
	vert.append(vertex);
	vertex.color = sf::Color::Transparent;
	vert.append(vertex);
}

std::vector<float> Polygon::getX(){
	std::vector<float> return_x;
	for(unsigned int i=0; i<points.size(); i++){
		return_x.push_back(points[i].x + position.x);
	}
	return return_x;
}

std::vector<float> Polygon::getY(){
	std::vector<float> return_y;
	for(unsigned int i=0; i<points.size(); i++){
		return_y.push_back(points[i].y + position.y);
	}
	return return_y;
}

void Polygon::getNormals(std::vector< float > &x, std::vector<float> &y){
	for(unsigned int i=0; i<points.size()-1; i++){
		x.push_back((points[i].y - points[i+1].y) * -1);
		y.push_back(points[i].x - points[i+1].x);
		//std::cout << x[i] << " | " << y[i] << "\n";
	}
	x.push_back((points[points.size()-1].y - points[0].y) * -1);
	y.push_back(points[points.size()-1].x - points[0].x);
	//std::cout << x[x.size()-1] << " | " << y[y.size()-1] << "\n";
}

sf::Vector2f Polygon::getClosestPoint(const float x, const float y){
	float min_dist = FLT_MAX;
	unsigned int min_id;
	for(unsigned int i=0; i<points.size(); i++){
		float cx =  pow(points[i].x + position.x - x, 2);
		float cy =  pow(points[i].y  + position.y - y, 2);
		float dist = sqrt(cx + cy);
		if (dist < min_dist){
			min_dist = dist;
			min_id = i;
		}
	}
	return sf::Vector2f(points[min_id].x + position.x, points[min_id].y + position.y);
}

void Polygon::setPosition(float x, float y){
	position = sf::Vector2f(x,y);
}

void Polygon::transfer(float x, float y){
	position += sf::Vector2f(x,y);
}