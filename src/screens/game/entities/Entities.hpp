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
		std::unordered_set<std::unique_ptr<Entity>> entities;
		sf::Texture Entities_texture;
		sf::Vector2f ball_position;
	public:
		Entities();
		void loadTexture(const std::string &);
		void add(std::unique_ptr<Entity> entity) { // use like Entities.add(std::unique_ptr<Robot>(new Robot(5)));
			entities.emplace(std::move(entity));
		}
		template <class T, class... Args>
		T& emplace(Args&&... args) { // use like Robot& A = Entities.emplace<Robot>(8);
			T* obj = new T(args...);
			entities.emplace(std::move(std::unique_ptr<T>(obj)));
			return *obj;
		}
		template <class T, class... Args>
		const T& emplace(Args&&... args) const {
			T* obj = new T(args...);
			entities.emplace(std::move(std::unique_ptr<T>(obj)));
			return *obj;
		}
		void clear(){
			entities.clear();
		}
		void add();
		void collide(ObjectMap &);
		void setBallPosition(const sf::Vector2f);
		void setBallPosition(const float, const float);
		void move(const float);
		void draw(sf::RenderWindow &);

};

#endif