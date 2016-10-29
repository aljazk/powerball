#include "ObjectMap.hpp"

ObjectMap::ObjectMap(){

}

void ObjectMap::set(const CollisionObject &o){
	ball = o;
}

void ObjectMap::add(const CollisionObject &o){
	objects.push_back(o);
}

void ObjectMap::add(const std::vector<CollisionObject> &o){
	for(unsigned int i=0; i<o.size(); i++){
		objects.push_back(o[i]);
	}
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
		
void ObjectMap::collide(){
	for(unsigned int i=0; i<objects.size(); i++){
		ball.collide(objects[i]);//unexpected crash happens after random time
	}
}

void ObjectMap::collideBullets(std::vector<Bullet> &bullets){
	if (bullets.size() > 0){
		for(unsigned int i=0; i<bullets.size(); i++){
			collideBullet(bullets[i]);
		}
	}
}

void ObjectMap::collideBullet(Bullet &bullet){
	ObjectSetter os = bullet.getObjectSetter();
	CollisionObject bullet_object(os);
	for(unsigned int j=0; j<objects.size(); j++){
		bullet_object.collide(objects[j]);
	}
	ball.collide(bullet_object);
	if(bullet_object.colliding == true){
		//bullet.check_delete = true;
	}
}
	