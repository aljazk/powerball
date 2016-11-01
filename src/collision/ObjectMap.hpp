#ifndef OBJECTMAP_H
#define OBJECTMAP_H

#include "shapes/CollisionObject.hpp"
#include "Collision.hpp"
#include "../screens/game/ball/Ball.hpp"
#include <vector>
#include <memory>

class ObjectMap{
		std::vector<CollisionObject> objects;
		std::shared_ptr<Ball> ptr_ball;
		CollisionObject ball;
		void updateObject();
		void updatePtr();
	public:
		ObjectMap();
		void set(const CollisionObject &);
		void set(const std::shared_ptr<Ball>);
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