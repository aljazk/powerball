#include "Collision.hpp"

Collision::Collision(){

}

bool Collision::check(Polygon &p1, Polygon &p2){
	Normals n;
	n.setObjects(p1, p2);
	if(n.checkCollision()){
		return true;
	}
	return false;
}

sf::Vector2f Collision::get(Polygon &p1, Polygon &p2){
	Normals n;
	n.setObjects(p1, p2);
	return n.collision();
}

bool Collision::check(Circle &c1, Circle &c2){
	float cx =  pow(c1.getX()-c2.getX(), 2);
	float cy =  pow(c1.getY()-c2.getY(), 2);
	float dist = sqrt(cx + cy);
	if(dist < c1.getR() + c2.getR()){
		return true;
	}
	return false;
}

sf::Vector2f Collision::get(Circle &c1, Circle &c2){
	float cx =  pow(c1.getX()-c2.getX(), 2);
	float cy =  pow(c1.getY()-c2.getY(), 2);
	float dist = sqrt(cx + cy);
	if(dist < c1.getR() + c2.getR()){
		cx =  c1.getX()-c2.getX();
		cy =  c1.getY()-c2.getY();
		float f = atan2(cy, cx);
		dist = c1.getR() + c2.getR() - dist;
		cx = cos(f) * dist;
		cy = sin(f) * dist;
		return sf::Vector2f(cx, cy);
	}
	return sf::Vector2f(0,0);
}

bool Collision::check(Polygon &p, Circle &c){
	Normals n;
	n.setObjects(p, c);
	if(n.checkCollision()){
		return true;
	}
	return false;
}

bool Collision::check(Circle &c, Polygon &p){
	return check(p, c);
}

bool Collision::checkTest(Polygon &p, Circle &c, sf::RenderWindow &window){
	Normals n;
	n.setObjects(p, c);
	if(n.checkCollision()){
		n.draw(window);
		return true;
	}
	n.draw(window);
	return false;
}

bool Collision::checkTest(Circle &c, Polygon &p, sf::RenderWindow &window){
	return checkTest(p, c, window);
}

sf::Vector2f Collision::get(Polygon &p, Circle &c){
	Normals n;
	n.setObjects(p, c);
	return n.collision();
}

sf::Vector2f Collision::get(Circle &c, Polygon &p){
	return get(p, c);
}