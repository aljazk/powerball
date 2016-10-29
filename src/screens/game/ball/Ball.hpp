#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "../../../draw/VertQuad.hpp"
#include <cmath>

class Ball{
		float position_x, position_y;
		float velocity_x, velocity_y;
		float energy, max_energy;
		
		sf::Texture ball_texture;
	public:
		Ball();
		void set(float, float, float, float);
		void getPosition(float &, float &);
		void getVelocity(float &, float &);
		void move(const float);
		void draw(sf::RenderWindow &);

};

#endif