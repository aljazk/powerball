#include "CollisionObject.hpp"

CollisionObject::CollisionObject(){
	reset();
}

CollisionObject::CollisionObject(const Polygon &p){
	add(p);
	reset();
}

CollisionObject::CollisionObject(const Circle &c){
	add(c);
	reset();
}

CollisionObject::CollisionObject(ObjectSetter &s){
	set(s);
}

void CollisionObject::reset(){
	position_x = 0, position_y = 0;
	velocity_x = 0, velocity_y = 0;
	rotation = 0;
	mass = 1, elasticity = 1;
	id = 0;
	colliding = false;
}

void CollisionObject::set(ObjectSetter &setter){
	polygons = setter.getPolygons();
	circles = setter.getCircles();
	
	position_x = setter.position_x, position_y = setter.position_y;
	velocity_x = setter.velocity_x, velocity_y = setter.velocity_y;
	rotation = setter.rotation;
	mass = setter.mass, elasticity = setter.elasticity;
	colliding = false;
}

void CollisionObject::clear(){
	polygons.clear();
	circles.clear();
}

void CollisionObject::add(const Polygon &p){
	polygons.push_back(p);
}

void CollisionObject::add(const Circle &c){
	circles.push_back(c);
}

void CollisionObject::setPosition(const float x, const float y){
	position_x = x;
	position_y = y;
}

void CollisionObject::addPosition(const float x, const float y){
	position_x += x;
	position_y += y;
}

void CollisionObject::setVelocity(const float x, const float y){
	velocity_x = x;
	velocity_y = y;
}

void CollisionObject::addVelocity(const float x, const float y){
	velocity_x += x;
	velocity_y += y;
}

void CollisionObject::setMass(const float m){
	mass = m;
}

void CollisionObject::setElasticity(const float e){
	elasticity = e;
}

void CollisionObject::getPosition(float &x, float &y){
	x = position_x;
	y = position_y;
}

void CollisionObject::getVelocity(float &x, float &y){
	x = velocity_x;
	y = velocity_y;
}

void CollisionObject::move(const float eclipsed){
	if(mass != 0){
		position_x += velocity_x * eclipsed / mass;
		position_y += velocity_y * eclipsed / mass;
	}
}

void CollisionObject::handleCollision(CollisionObject &o, sf::Vector2f v){ // no friction
	float nm = mass + o.mass;
	float m1 = mass / nm;
	float m2 = o.mass / nm;

	addPosition(v.x * m1, v.y * m1);
	o.addPosition(-v.x * m2, -v.y * m2);

	float l = sqrt(pow(v.x,2) + pow(v.y,2));
	v.x /= l;
	v.y /= l;

	float d1 = abs(v.x * velocity_x + v.y * velocity_y);
	float d2 = abs(v.x * o.velocity_x + v.y * o.velocity_y);
	float d = abs(d1 + d2);

	float p1 = (1.0 + elasticity) * d * m1;
	float p2 = (1.0 + o.elasticity) * d * m2;

	velocity_x += v.x * p1;
	velocity_y += v.y * p1;
	o.velocity_x += v.x * p2 * -1;
	o.velocity_y += v.y * p2 * -1;
}

void CollisionObject::collide(CollisionObject &o){
	colliding = false;
	for(unsigned int i=0; i<circles.size(); i++){
		for(unsigned int j=0; j<o.circles.size(); j++){
			Circle c1 = circles[i];
			c1.transfer(position_x, position_y);
			Circle c2 = o.circles[j];
			c2.transfer(o.position_x, o.position_y);
			if (Collision::check(c1, c2)){
				circles[i].colliding = true;
				o.circles[j].colliding = true;
				colliding = true;
				o.colliding = true;
				handleCollision(o, Collision::get(c1, c2));
				// add mass and elasticity
			}
		}
	}
	for(unsigned int i=0; i<polygons.size(); i++){
		for(unsigned int j=0; j<o.polygons.size(); j++){
			Polygon p1 = polygons[i];
			p1.transfer(position_x, position_y);
			Polygon p2 = o.polygons[j];
			p2.transfer(o.position_x, o.position_y);
			if (Collision::check(p1, p2)){
				polygons[i].colliding = true;
				o.polygons[j].colliding = true;
				colliding = true;
				o.colliding = true;
				handleCollision(o, Collision::get(p1, p2));
			}
		}
	}
	for(unsigned int i=0; i<circles.size(); i++){
		for(unsigned int j=0; j<o.polygons.size(); j++){
			Circle c1 = circles[i];
			c1.transfer(position_x, position_y);
			Polygon p1 = o.polygons[j];
			p1.transfer(o.position_x, o.position_y);
			if (Collision::check(c1, p1)){
				circles[i].colliding = true;
				o.polygons[j].colliding = true;
				colliding = true;
				o.colliding = true;
				handleCollision(o, Collision::get(c1, p1));
			}
		}
	}
	for(unsigned int i=0; i<polygons.size(); i++){
		for(unsigned int j=0; j<o.circles.size(); j++){
			Polygon p1 = polygons[i];
			p1.transfer(position_x, position_y);
			Circle c1 = o.circles[j];
			c1.transfer(o.position_x, o.position_y);
			if (Collision::check(p1, c1)){
				polygons[i].colliding = true;
				o.circles[j].colliding = true;
				colliding = true;
				o.colliding = true;
				handleCollision(o, Collision::get(p1, c1));
			}
		}
	}
}

void CollisionObject::collide(CollisionObject &o, sf::RenderWindow &window){
	colliding = false;
	for(unsigned int i=0; i<circles.size(); i++){
		for(unsigned int j=0; j<o.circles.size(); j++){
			Circle c1 = circles[i];
			c1.transfer(position_x, position_y);
			Circle c2 = o.circles[j];
			c2.transfer(o.position_x, o.position_y);
			if (Collision::check(c1, c2)){
				circles[i].colliding = true;
				o.circles[j].colliding = true;
				colliding = true;
				o.colliding = true;
				handleCollision(o, Collision::get(c1, c2));
				// add mass and elasticity
			}
		}
	}
	for(unsigned int i=0; i<polygons.size(); i++){
		for(unsigned int j=0; j<o.polygons.size(); j++){
			Polygon p1 = polygons[i];
			p1.transfer(position_x, position_y);
			Polygon p2 = o.polygons[j];
			p2.transfer(o.position_x, o.position_y);
			if (Collision::check(p1, p2)){
				polygons[i].colliding = true;
				o.polygons[j].colliding = true;
				colliding = true;
				o.colliding = true;
				handleCollision(o, Collision::get(p1, p2));
			}
		}
	}
	for(unsigned int i=0; i<circles.size(); i++){
		for(unsigned int j=0; j<o.polygons.size(); j++){
			Circle c1 = circles[i];
			c1.transfer(position_x, position_y);
			Polygon p1 = o.polygons[j];
			p1.transfer(o.position_x, o.position_y);
			if (Collision::checkTest(c1, p1, window)){
				circles[i].colliding = true;
				o.polygons[j].colliding = true;
				colliding = true;
				o.colliding = true;
				handleCollision(o, Collision::get(c1, p1));
			}
		}
	}
	for(unsigned int i=0; i<polygons.size(); i++){
		for(unsigned int j=0; j<o.circles.size(); j++){
			Polygon p1 = polygons[i];
			p1.transfer(position_x, position_y);
			Circle c1 = o.circles[j];
			c1.transfer(o.position_x, o.position_y);
			if (Collision::checkTest(p1, c1, window)){
				polygons[i].colliding = true;
				o.circles[j].colliding = true;
				colliding = true;
				o.colliding = true;
				handleCollision(o, Collision::get(p1, c1));
			}
		}
	}
}

void CollisionObject::draw(sf::RenderWindow &window){
	sf::VertexArray vert(sf::LinesStrip);
	for(unsigned int i=0; i<polygons.size(); i++){
		polygons[i].getVert(vert);
	}
	for(unsigned int i=0; i<circles.size(); i++){
		circles[i].getVert(vert);
	}
	for(unsigned int i=0; i<vert.getVertexCount(); i++){
		vert[i].position.x += position_x;
		vert[i].position.y += position_y;
		if(colliding){
			if(vert[i].color != sf::Color::Yellow){
				if(vert[i].color != sf::Color::Transparent){
					vert[i].color = sf::Color::Red;
				}
			}
		}
	}
	window.draw(vert);
}