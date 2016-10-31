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
	position = new_position;
	velocity = new_velocity;
	life_time = 0;
	max_life_time = 10;
	addType("bullet");
	dying = false;
}

void Bullet::collide(ObjectMap &map){
	ObjectSetter os = getObjectSetter();
	CollisionObject bullet_object(os);
	map.collide(bullet_object);
	if(bullet_object.colliding){
		float px, py, vx, vy;
		bullet_object.getPosition(px, py);
		bullet_object.getVelocity(vx, vy);
		set(sf::Vector2f(px, py), sf::Vector2f(vx, vy));
		dying = true;
		life_time = max_life_time-1;
	}
	if(!dying){
		map.collideBall(bullet_object);
		if(bullet_object.colliding){
			float px, py, vx, vy;
			bullet_object.getPosition(px, py);
			bullet_object.getVelocity(vx, vy);
			set(sf::Vector2f(px, py), sf::Vector2f(vx, vy));
			dying = true;
			life_time = max_life_time-1;
		}
	}
}

void Bullet::move(const float eclipsed){
	position.x += velocity.x * eclipsed;
	position.y += velocity.y * eclipsed;
	life_time += eclipsed;
	//std::cout << life_time << std::endl;
	if(life_time > max_life_time){
		check_delete = true;
	}
}

void Bullet::getVert(sf::VertexArray& vert){
	VertQuad quad;
	quad.set(sf::Vector2f(46,51), sf::Vector2f(8,8), position);
	if(dying){
		int fade = (max_life_time - life_time) * 255;
		quad.setColor(sf::Color(255,255,255, fade));
	}
	quad.add(vert);
}

ObjectSetter Bullet::getObjectSetter(){
	ObjectSetter os;
	os.add(Circle(0,0,4));
	os.position_x = position.x;
	os.position_y = position.y;
	os.velocity_x = velocity.x;
	os.velocity_y = velocity.y;
	os.elasticity = 0.1;
	os.mass = 10;
	return os;
}