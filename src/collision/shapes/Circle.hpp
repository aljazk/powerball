#ifndef CIRCLE_H
#define CIRCLE_H

#include "../../draw/VertCircle.hpp"

class Circle{
		sf::Vector2f position;
		float radius;
	public:
		Circle();
		Circle(float, float);
		Circle(float, float, float);
		void set(float, float, float);
		
		float getX();
		float getY();
		float getR();
		
		void draw(sf::RenderWindow&);
		void getVert(sf::VertexArray &);
		bool colliding;
		
		unsigned int object_id;
		
		void setPosition(float, float);
		void transfer(float, float);
};

#endif