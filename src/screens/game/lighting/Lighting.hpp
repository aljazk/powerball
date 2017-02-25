#ifndef LIGHTING_H
#define LIGHTING_H

#include <vector>
#include <cmath>
#include "Light.hpp"
#include "../../../collision/Collision.hpp"
#include "../objects/Wall.hpp"

class Lighting{
		std::vector<Light> lights;
		std::vector<Wall> walls;
		unsigned int quality;
		unsigned int texture_size_x, texture_size_y;
		sf::Texture texture;
		sf::RenderStates states;
		sf::RenderTexture dark;
		sf::RenderTexture static_light;
		sf::RenderTexture light;
		sf::VertexArray fullScreenVertex;
		sf::VertexArray qualityVertex;
		void shadows(sf::VertexArray &, const sf::Vector2f);
	public:
		Lighting();
		void setPosition(const float, const float);
		void setPosition(const sf::Vector2f);
		void addLight(const Light &);
		void addStaticLight(const Light &);
		void setWalls(const std::vector<Wall> &set_walls){
			walls = set_walls;
		}
		void draw(sf::RenderWindow &);//i think i'll need costume draw function for this

};

#endif