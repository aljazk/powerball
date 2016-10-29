#include "Entities.hpp"

Entities::Entities(){
	loadTexture("images/robots.png");
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

void Entities::collide(ObjectMap &map){
	for (const auto& e: entities){
		e->collide(map);
	}
}

void Entities::setBallPosition(const sf::Vector2f new_ball_position){
	setBallPosition(new_ball_position.x, new_ball_position.y);
}

void Entities::setBallPosition(const float ballx, const float bally){
	for (const auto& e: entities){
		e->setBallPosition(sf::Vector2f(ballx, bally));
	}
}

void Entities::move(const float eclipsed){
	for (const auto& e: entities){
		if(e->id == "turret"){
			e->move(eclipsed);
		}
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