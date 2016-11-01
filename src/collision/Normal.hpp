#ifndef NORMAL_H
#define NORMAL_H

#include <math.h>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "NormalObject.hpp"

class NormalObject;
class Normal{
		float normal_x, normal_y;
		NormalObject object1, object2;
		void projectVector(float &, float &);
	public:
		Normal();
		Normal(const float, const float);
		void set(const float, const float);
		float getX();
		float getY();
		void setObject1(std::vector<float>, std::vector<float>);
		void setObject1(float, float, float);
		void setObject2(std::vector<float>, std::vector<float>);
		void setObject2(float, float, float);
		void draw(sf::RenderWindow&);
		//bool checkCollision();
		bool checkCollision();
		bool checkCollision(bool &);
		sf::Vector2f collision(float &, bool &);
		sf::Vector2f collision(float &, bool &, bool &); //returns overlap vector if its smaller than provided value
		

};
#endif