#ifndef ROBOT_H
#define ROBOT_H

#include "Entity.hpp"
#include "../../../draw/VertQuad.hpp"
#include "../../../collision/ObjectMap.hpp"
#include <cmath>

#include "Bullet.hpp"

class Robot : public Entity{
	protected:
		float health, max_health;
		float energy, max_energy;
		float dmg;
	public:
		Robot();
		Robot(const float, const float);
		Robot(const sf::Vector2f);
		void set();
		virtual void collide(ObjectMap &){};
		virtual void move(const float){};
		void getVert(sf::VertexArray&);
		virtual void setBallPosition(const sf::Vector2f){};
};

#endif