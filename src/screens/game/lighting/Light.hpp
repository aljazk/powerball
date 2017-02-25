#ifndef LIGHT_H
#define LIGHT_H

#include "../../../draw/VertQuad.hpp"
#include <SFML/Graphics.hpp>

class Light{
		float x,y;
		sf::Color color;
		float size;
	public:
		Light();
		Light(const float, const float);
		Light(const float, const float, const float);
		Light(const float, const float, const float, const sf::Color &);
		void set(const float, const float);
		void set(const float, const float, const float);
		void set(const float, const float, const float, const sf::Color &);
		void setPosition(const float, const float);
		void setSize(const float);
		void setColor(const sf::Color &);
		void getVert(sf::VertexArray &);
		const sf::Vector2f getPosition(){
			return sf::Vector2f(x,y);
		}
};

#endif