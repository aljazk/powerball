#ifndef OBJECTMAP_H
#define OBJECTMAP_H

#include "shapes/CollisionObject.hpp"
#include "Collision.hpp"
#include <vector>

class ObjectMap{
		std::vector<CollisionObject> objects;
		CollisionObject ball;
	public:
		ObjectMap();
		void set(const CollisionObject &);
		void add(const CollisionObject &);
		void add(const std::vector<CollisionObject> &);
				
		void setBall(float, float, float, float);
		void getPosition(float &, float &);
		void getVelocity(float &, float &);
		
		void collide();
		bool collide(CollisionObject &);
		bool collideBall(CollisionObject &);
		bool collideBullet(ObjectSetter &);
};

#endif