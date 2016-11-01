#ifndef NORMALOBJECT_H
#define NORMALOBJECT_H

#include <math.h>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class NormalObject{
		float min_x, min_y, max_x, max_y, r;
		std::vector<float> x, y;
	public:
		float min, max;
		NormalObject();
		NormalObject(const std::vector<float>, const std::vector<float>, float, float);
		NormalObject(float, float, float, float, float);
		void set(const std::vector<float>, const std::vector<float>, float, float);
		void set(float, float, float, float, float);
		void getVert(sf::VertexArray &);

};

#endif