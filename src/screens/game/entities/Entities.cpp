#include "Entities.hpp"

Entities::Entities(){
	loadTexture("images/robots.png");
}

Entities::~Entities(){
	entities.clear();
	robots.clear();
}

void Entities::add(){
	for (const auto& e: entities){
		add(e->getEntity());
	}
}

void Entities::loadTexture(const std::string &t_string){
	if (!Entities_texture.loadFromFile(t_string)){
		std::cout << "Cannot load texture from: " << t_string << "\n";
	}
	Entities_texture.setSmooth(true);
}
		
void Entities::add(std::shared_ptr<Entity> entity) {
	if (entity){
		entities.emplace(entity);
		if(entity->checkType("robot")){
			robots.emplace(entity);
		}
		if(entity->checkType("bullet")){
			bullets.emplace(entity);
		}
	}
}

void Entities::check_delete(){
	for (const auto& e: entities){
		if (e->checkDelete()){
			entities.erase(e);
		}
	}
}

void Entities::collide(ObjectMap &map){
	for (const auto& e: bullets){
		std::shared_ptr<Bullet> b = std::dynamic_pointer_cast<Bullet>(e);
		b->collide(map);
	}
}

void Entities::setBallPosition(const sf::Vector2f new_ball_position){
	setBallPosition(new_ball_position.x, new_ball_position.y);
}

void Entities::setBallPosition(const float ballx, const float bally){
	for (const auto& e: robots){
		std::shared_ptr<Robot> r = std::dynamic_pointer_cast<Robot>(e);
		r->setBallPosition(sf::Vector2f(ballx, bally));
	}
}

void Entities::move(const float eclipsed){
	for (const auto& e: entities){
		e->move(eclipsed);
	}
}

void Entities::draw(sf::RenderWindow &window){
	sf::VertexArray vertex;
	vertex.setPrimitiveType(sf::Quads);
	
	//draw entities
	for (const auto& e: entities){
		e->getVert(vertex);
	}
	
	window.draw(vertex, &Entities_texture);
}