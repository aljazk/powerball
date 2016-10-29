#include "Entity.hpp"

Entity::Entity(){
	set();
}

void Entity::set(){
	position.x = 0;
	position.y = 0;
	id = "entitiy";
	check_delete = false;
}

void Entity::collide(ObjectMap &){
	
}

void Entity::move(const float){
	
}

void Entity::getVert(sf::VertexArray&){
	
}

void Entity::setBallPosition(const sf::Vector2f){
	
}

std::unique_ptr<Entity> Entity::getEntity(){
	return std::unique_ptr<Entity>(new Entity);//fuck u
}