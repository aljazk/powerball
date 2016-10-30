#ifndef ENTITIES_H
#define ENTITIES_H

#include <iostream>
#include <unordered_set>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Robot.hpp"
#include "eBullet.hpp"

#include "robots/Turret.hpp"

class Entities{
		std::unordered_set<std::shared_ptr<Entity>> entities;
		std::unordered_set<std::shared_ptr<Entity>> robots;
		std::unordered_set<std::shared_ptr<Entity>> bullets;
		sf::Texture Entities_texture;
		sf::Vector2f ball_position;
	public:
		Entities();
		~Entities();
		void loadTexture(const std::string &);
		void add(std::shared_ptr<Entity>); // use like Entities.add(std::unique_ptr<Robot>(new Robot(5)));
		void clear(){ entities.clear(); }
		void add();
		void check_delete();
		void collide(ObjectMap &);
		void setBallPosition(const sf::Vector2f);
		void setBallPosition(const float, const float);
		void move(const float);
		void draw(sf::RenderWindow &);

};

#endif