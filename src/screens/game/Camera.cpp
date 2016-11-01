#include "Camera.hpp"

Camera::Camera(){
	set(640, 480);
}

Camera::Camera(const unsigned int x, const unsigned int y){
	set(x,y);
}

void Camera::set(const unsigned int x, const unsigned int y){
	setWindowSize(x, y);
	view.reset(sf::FloatRect(0, 0, window_size_x, window_size_y));
}

void Camera::setWindowSize(const unsigned int x, const unsigned int y){
	window_size_x = x;
	window_size_y = y;
}

void Camera::pos(const float x, const float y){
	view.reset(sf::FloatRect(x-window_size_x/2, y-window_size_y/2, window_size_x, window_size_y));
}

void Camera::pos(const sf::Vector2f pos){
	view.reset(sf::FloatRect(pos.x-window_size_x/2, pos.y-window_size_y/2, window_size_x, window_size_y));
}

sf::View Camera::get(){
	return view;
}