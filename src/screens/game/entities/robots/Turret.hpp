#ifndef TURRET_H
#define TURRET_H

#include "../Robot.hpp"
#include "../Bullet.hpp"
#include <vector>

class Turret : public Robot{
		sf::Vector2f ball_position;
		float turret_angle, turret_speed;
		float fire_speed;
		float cooldown, cooldown_time;
	public:
		Turret();
		Turret(const float, const float);
		Turret(const sf::Vector2f);
		void set();
		void move(const float);
		void getVert(sf::VertexArray&);
		void setBallPosition(const sf::Vector2f);
};

#endif