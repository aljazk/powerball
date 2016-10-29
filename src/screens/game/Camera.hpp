#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Camera{
		sf::View view;
		unsigned int window_size_x, window_size_y;
	public:
		Camera();
		Camera(unsigned int, unsigned int);
		void set(unsigned int x, unsigned int y);
		void setWindowSize(unsigned int, unsigned int);
		void pos(const float, const float);
		sf::View get();
};

#endif