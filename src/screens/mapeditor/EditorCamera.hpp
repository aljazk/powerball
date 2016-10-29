#ifndef EDITOREditorCamera_H
#define EDITOREditorCamera_H

#include <SFML/Graphics.hpp>
#include <iostream>

class EditorCamera{
		sf::View view;
		bool keyA, keyD, keyW, keyS;
		bool mA, mD, mW, mS;
		bool zoom;
		float delta;
		unsigned int window_size_x, window_size_y;
	public:
		EditorCamera();
		EditorCamera(unsigned int, unsigned int);
		void set(unsigned int x, unsigned int y);
		void setWindowSize(unsigned int, unsigned int);
		sf::View get();
		void move();
		void move(const float);
		void key(const sf::Event &);
		float getZoom();
		float move_speed;
		float zoom_speed;
};

#endif