#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H

#include "Polygon.hpp"
#include "Circle.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "ObjectSetter.hpp"
#include "../Collision.hpp"

class CollisionObject{
		std::vector<Polygon> polygons;
		std::vector<Circle> circles;
		
		float position_x, position_y;
		float velocity_x, velocity_y;
		float rotation; // make rotations
		float mass, elasticity;
		
	public:
		CollisionObject();
		CollisionObject(const Polygon &);
		CollisionObject(const Circle &);
		CollisionObject(ObjectSetter &);
		void reset();
		void set(ObjectSetter &);
		
		unsigned int id;
		bool colliding;
		
		void clear();
		void add(const Polygon &);
		void add(const Circle &);
		
		void setPosition(const float, const float);
		void addPosition(const float, const float);
		void setVelocity(const float, const float);
		void addVelocity(const float, const float);
		void setMass(const float);
		void setElasticity(const float);
		void setId(const unsigned int);
		
		void getPosition(float &, float &);
		void getVelocity(float &, float &);
		
		void move(const float);
		
		void handleCollision(CollisionObject &, sf::Vector2f);
		void collide(CollisionObject &, sf::RenderWindow &);
		void collide(CollisionObject &);
		
		void draw(sf::RenderWindow &);
};

#endif