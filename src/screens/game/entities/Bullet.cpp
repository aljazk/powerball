#include "Bullet.hpp"

Bullet::Bullet(){
	set(sf::Vector2f(0,0), sf::Vector2f(0,0));
}

Bullet::Bullet(sf::Vector2f new_position, sf::Vector2f new_velocity){
	set(new_position, new_velocity);
}

Bullet::Bullet(const float px, const float py, const float vx, const float vy){
	set(sf::Vector2f(px, py), sf::Vector2f(vx, vy));
}

void Bullet::set(sf::Vector2f new_position, sf::Vector2f new_velocity){
	setPosition(new_position);
	setVelocity(new_velocity);
	life_time = 0;
	max_life_time = 10;
	check_delete = false;
}

void Bullet::setPosition(sf::Vector2f new_position){
	position = new_position;
}

void Bullet::setVelocity(sf::Vector2f new_velocity){
	velocity = new_velocity;
}


void Bullet::getVertex(sf::VertexArray& vert){
	VertQuad quad;
	quad.set(sf::Vector2f(46,51), sf::Vector2f(8,8), position);
	quad.add(vert);
}

bool Bullet::move(float eclipsed){
	position.x += velocity.x * eclipsed;
	position.y += velocity.y * eclipsed;
	life_time += eclipsed;
	//std::cout << life_time << std::endl;
	if(life_time > max_life_time){
		return true;
	} else {
		return false;
	}
}

ObjectSetter Bullet::getObjectSetter(){
	ObjectSetter os;
	os.add(Circle(0,0,4));
	os.position_x = position.x;
	os.position_y = position.y;
	os.velocity_x = velocity.x;
	os.velocity_y = velocity.y;
	return os;
}