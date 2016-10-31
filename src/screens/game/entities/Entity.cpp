#include "Entity.hpp"

Entity::Entity(){
	set();
}

void Entity::set(){
	position.x = -100;
	position.y = 0;
	id = "entitiy";
	check_delete = false;
	addType("entity");
}

void Entity::move(const float){
	
}

void Entity::getVert(sf::VertexArray& vert){
	VertQuad quad;
	quad.set(sf::Vector2f(45,0), sf::Vector2f(50,50), position);
	quad.setColor(sf::Color::Red);
	quad.add(vert);
}

std::shared_ptr<Entity> Entity::getEntity(){
	std::shared_ptr<Entity> return_entity = add_entity;
	add_entity.reset();
	return return_entity;
}
		
bool Entity::checkDelete(){
	return check_delete;
}

void Entity::addType(const std::string &new_type){
	types.emplace(new_type);
}

void Entity::removeType(const std::string &remove_type){
	types.erase(remove_type);
}

bool Entity::checkType(const std::string &check_type){
	if (types.find(check_type) == types.end()){
		return false;
	} else {
		return true;
	}
}