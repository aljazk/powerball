#include "Camera.hpp"

Camera::Camera(){
	set(640, 480);
}

Camera::Camera(unsigned int x, unsigned int y){
	set(x,y);
}

void Camera::set(unsigned int x, unsigned int y){
	setWindowSize(x, y);
	view.reset(sf::FloatRect(0, 0, window_size_x, window_size_y));
}

void Camera::setWindowSize(unsigned int x, unsigned int y){
	window_size_x = x;
	window_size_y = y;
}

void Camera::pos(const float x, const float y){
	view.reset(sf::FloatRect(x-window_size_x/2, y-window_size_y/2, window_size_x, window_size_y));
}

sf::View Camera::get(){
	return view;
}