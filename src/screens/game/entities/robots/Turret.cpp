#include "Turret.hpp"

Turret::Turret(){
	set();
}

Turret::Turret(const float x, const float y){
	set();
	position.x = x;
	position.y = y;
}
Turret::Turret(const sf::Vector2f new_position){
	set();
	position = new_position;
}

void Turret::set(){
	turret_angle = 0;
	turret_speed = 1;
	cooldown = 0.5;
	cooldown_time = 3;
	fire_speed = 200;
	id = "turret";
	addType("robot");
	addType("turret");
}

float fixAngle(float ang){
	if (ang > atan(1)*8){
		ang -= atan(1)*8;
	} else if (ang < 0){
		ang += atan(1)*8;
	}
	return ang;
}

void Turret::move(const float eclipsed){
	//rotate turret
	turret_angle = fixAngle(turret_angle);
	float dx = ball_position.x - position.x;
	float dy = ball_position.y - position.y;
	float f = atan2(dy, dx);
	f = fixAngle(f);
	float dist = atan2(sin(f-turret_angle), cos(f-turret_angle));
	if (dist > 0){
		turret_angle += turret_speed * eclipsed;
	} else if(dist < 0){
		turret_angle -= turret_speed * eclipsed;
	}
	
	//shoot bullet
	cooldown_time -= eclipsed;
	if (cooldown_time < 0){
		sf::Vector2f new_bullet_position = position;
		new_bullet_position.x += cos(turret_angle)*42;
		new_bullet_position.y += sin(turret_angle)*42;
		sf::Vector2f new_bullet_velocity = sf::Vector2f(cos(turret_angle)*fire_speed, sin(turret_angle)*fire_speed);
		add_entity = std::make_shared<Bullet>(new_bullet_position, new_bullet_velocity);
		cooldown_time = cooldown;
		//std::cout << bullets.size() << std::endl;
	}
}

void Turret::getVert(sf::VertexArray &vert){
	
	//draw legs
	VertQuad quad;
	quad.set(sf::Vector2f(45,0), sf::Vector2f(50,50), position);
	quad.add(vert);
	
	//draw turret
	quad.set(sf::Vector2f(0,0), sf::Vector2f(40,60), position);
	quad.setCenter(sf::Vector2f(20,20));
	quad.setAngle(turret_angle);
	quad.add(vert);
}

void Turret::setBallPosition(const sf::Vector2f new_ball_position){
	ball_position = new_ball_position;
}