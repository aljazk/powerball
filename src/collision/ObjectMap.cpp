#include "ObjectMap.hpp"

ObjectMap::ObjectMap(){

}

void ObjectMap::set(const CollisionObject &o){
	ball = o;
}

void ObjectMap::set(const std::shared_ptr<Ball> set_ball){
	ptr_ball = set_ball;
}

void ObjectMap::add(const CollisionObject &o){
	objects.push_back(o);
	std::cout << objects.size() << std::endl;
}

void ObjectMap::add(const std::vector<CollisionObject> &o){
	for(unsigned int i=0; i<o.size(); i++){
		objects.push_back(o[i]);
	}
	std::cout << objects.size() << std::endl;
}

void ObjectMap::setBall(float px, float py, float vx, float vy){
	ball.setPosition(px, py);
	ball.setVelocity(vx, vy);
}

void ObjectMap::getPosition(float &x, float &y){
	ball.getPosition(x, y);
}

void ObjectMap::getVelocity(float &x, float &y){
	ball.getVelocity(x, y);
}

void ObjectMap::updateObject(){
	float px, py, vx, vy;
	ptr_ball->getPosition(px, py);
	ptr_ball->getVelocity(vx, vy);
	ball.setPosition(px, py);
	ball.setVelocity(vx, vy);
}
void ObjectMap::updatePtr(){
	float px, py, vx, vy;
	ball.getPosition(px, py);
	ball.getVelocity(vx, vy);
	ptr_ball->set(px, py, vx, vy);
}
		
void ObjectMap::collide(){
	updateObject();
	for(unsigned int i=0; i<objects.size(); i++){
		ball.collide(objects[i]);
	}
	updatePtr();
}

bool ObjectMap::collide(CollisionObject &obj){
	for(unsigned int i=0; i<objects.size(); i++){
		obj.collide(objects[i]);
	}
	return obj.colliding;
}

bool ObjectMap::collideBall(CollisionObject &obj){
	updateObject();
	ball.collide(obj);
	updatePtr();
	return obj.colliding;
}
	
bool ObjectMap::collideBullet(ObjectSetter &bullet){
	CollisionObject bullet_object(bullet);
	collide(bullet_object);
	collideBall(bullet_object);
	return bullet_object.colliding;
}