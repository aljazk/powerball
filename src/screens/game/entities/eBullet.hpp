#ifndef EBULLET_H
#define EBULLET_H

#include "Entity.hpp"
#include "../../../draw/VertQuad.hpp"
#include "../../../collision/ObjectMap.hpp"

class eBullet : public Entity{
		sf::Vector2f position;
		sf::Vector2f velocity;
		float life_time, max_life_time;
	public:
		eBullet();
		eBullet(const sf::Vector2f, const sf::Vector2f);
		eBullet(const float, const float, const float, const float);
		void set(const sf::Vector2f, const sf::Vector2f);
		void collide(ObjectMap &);
		void move(const float);
		void getVert(sf::VertexArray&);
		ObjectSetter getObjectSetter();
};

#endif