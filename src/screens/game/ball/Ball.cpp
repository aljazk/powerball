#include "Ball.hpp"

Ball::Ball(){
	position_x = 0, position_y = 0;
	velocity_x = 0, velocity_y = 0;
	energy = 100, max_energy = 100;
	
	ball_texture.loadFromFile("images/ball.png");
}

void Ball::set(float px, float py, float vx, float vy){
	position_x = px;
	position_y = py;
	velocity_x = vx;
	velocity_y = vy;
}

void Ball::getPosition(float &x, float &y){
	x = position_x;
	y = position_y;
}

void Ball::getVelocity(float &x, float &y){
	x = velocity_x;
	y = velocity_y;
}

void Ball::move(const float eclipsed){
	//use eclipsed time right
	float speed = 300;
	float add_velocity_x = 0, add_velocity_y = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		add_velocity_x -= speed * eclipsed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		add_velocity_x += speed * eclipsed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		add_velocity_y -= speed * eclipsed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		add_velocity_y += speed * eclipsed;
	}
    if (abs(add_velocity_x)+abs(add_velocity_y) == speed*2){
        add_velocity_x *= sin(atan(1));
        add_velocity_y *= sin(atan(1));
    }
	velocity_x += add_velocity_x;
	velocity_y += add_velocity_y;
	float friction = 1;
	velocity_x *= 1 / (1 + eclipsed * friction);
	velocity_y *= 1 / (1 + eclipsed * friction);
	position_x += velocity_x * eclipsed;
	position_y += velocity_y * eclipsed;
}

void Ball::draw(sf::RenderWindow &window){
	VertQuad circle(sf::Vector2f(0, 0), sf::Vector2f(50, 50), sf::Vector2f(position_x, position_y));
	sf::VertexArray vert(sf::Quads);
	circle.add(vert);
	window.draw(vert, &ball_texture);
}