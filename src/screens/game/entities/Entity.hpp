#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <unordered_set>
#include "../../../draw/VertQuad.hpp"
#include "../../../collision/ObjectMap.hpp"
#include <memory>

class Entity{
	protected:
		sf::Vector2f position;
		bool check_delete;
		std::shared_ptr<Entity> add_entity;
		std::unordered_set<std::string> types;
	public:
		std::string id;
		Entity();
		virtual void set();
		virtual void move(const float);
		virtual void getVert(sf::VertexArray&);
		virtual std::shared_ptr<Entity> getEntity();
		virtual bool checkDelete();
		virtual void addType(const std::string &);
		virtual void removeType(const std::string &);
		virtual bool checkType(const std::string &);
};

#endif