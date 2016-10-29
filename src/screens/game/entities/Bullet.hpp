#ifndef BULLET_H
#define BULLET_H

#include "../../../draw/VertQuad.hpp"
#include "../../../collision/shapes/ObjectSetter.hpp"

class Bullet{
		sf::Vector2f position;
		sf::Vector2f velocity;
		float life_time, max_life_time;
	public:
		Bullet();
		Bullet(const sf::Vector2f, const sf::Vector2f);
		Bullet(const float, const float, const float, const float);
		void set(const sf::Vector2f, const sf::Vector2f);
		void setPosition(const sf::Vector2f);
		void setVelocity(const sf::Vector2f);
		void getVertex(sf::VertexArray&);
		bool move(const float);
		ObjectSetter getObjectSetter();

};

#endif