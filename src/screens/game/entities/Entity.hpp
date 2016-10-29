#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "../../../draw/VertQuad.hpp"
#include "../../../collision/ObjectMap.hpp"

class Entity{
	protected:
		sf::Vector2f position;
		bool check_delete;
		std::unique_ptr<Entity> add_entity;
	public:
		std::string id;
		Entity();
		virtual void set();
		virtual void collide(ObjectMap &);
		virtual void move(const float);
		virtual void getVert(sf::VertexArray&);
		virtual void setBallPosition(const sf::Vector2f);
		virtual std::unique_ptr<Entity> getEntity();
		virtual bool checkDelete(){
			return check_delete;
		}
};

#endif