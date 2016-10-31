#ifndef EBULLET_H
#define EBULLET_H

#include "Entity.hpp"
#include "../../../draw/VertQuad.hpp"
#include "../../../collision/ObjectMap.hpp"

class Bullet : public Entity{
		sf::Vector2f position;
		sf::Vector2f velocity;
		float life_time, max_life_time;
		bool dying;
	public:
		Bullet();
		Bullet(const sf::Vector2f, const sf::Vector2f);
		Bullet(const float, const float, const float, const float);
		void set(const sf::Vector2f, const sf::Vector2f);
		void collide(ObjectMap &);
		void move(const float);
		void getVert(sf::VertexArray&);
		ObjectSetter getObjectSetter();
};

#endif