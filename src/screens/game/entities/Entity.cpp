#include "Entity.hpp"

Entity::Entity(){
	set();
}

void Entity::set(){
	position.x = 0;
	position.y = 0;
	id = "entitiy";
	check_delete = false;
	addType("entity");
}

void Entity::collide(ObjectMap &){
	
}

void Entity::move(const float){
	
}

void Entity::getVert(sf::VertexArray&){
	
}

std::unique_ptr<Entity> Entity::getEntity(){
	return std::unique_ptr<Entity>(new Entity);
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