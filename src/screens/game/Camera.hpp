#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Camera{
		sf::View view;
		unsigned int window_size_x, window_size_y;
	public:
		Camera();
		Camera(const unsigned int, const unsigned int);
		void set(const unsigned int x, const unsigned int y);
		void setWindowSize(const unsigned int, const unsigned int);
		void pos(const float, const float);
		void pos(const sf::Vector2f);
		sf::View get();
};

#endif