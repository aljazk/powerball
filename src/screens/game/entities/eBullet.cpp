#include "eBullet.hpp"

eBullet::eBullet(){
	set(sf::Vector2f(0,0), sf::Vector2f(0,0));
}

eBullet::eBullet(sf::Vector2f new_position, sf::Vector2f new_velocity){
	set(new_position, new_velocity);
}

eBullet::eBullet(const float px, const float py, const float vx, const float vy){
	set(sf::Vector2f(px, py), sf::Vector2f(vx, vy));
}

void eBullet::set(sf::Vector2f new_position, sf::Vector2f new_velocity){
	position = new_position;
	velocity = new_velocity;
	life_time = 0;
	max_life_time = 10;
}

void eBullet::collide(ObjectMap &map){
	//map.collideBullets(bullets);
}
void eBullet::move(const float eclipsed){
	position.x += velocity.x * eclipsed;
	position.y += velocity.y * eclipsed;
	life_time += eclipsed;
	//std::cout << life_time << std::endl;
	if(life_time > max_life_time){
		check_delete = true;
	}
}

void eBullet::getVert(sf::VertexArray& vert){
	VertQuad quad;
	quad.set(sf::Vector2f(46,51), sf::Vector2f(8,8), position);
	quad.add(vert);
}