#include "Normal.hpp"

Normal::Normal(){
	set(0,0);
}

Normal::Normal(const float new_x, const float new_y){
	set(new_x, new_y);
}

void Normal::set(const float new_x, const float new_y){
	normal_x = new_x;
	normal_y = new_y;
	float l = sqrt(pow(normal_x,2) + pow(normal_y,2));
	normal_x /= l;
	normal_y /= l;
	//std::cout << normal_x  << " " << normal_y << "\n" << pow(normal_x,2) + pow(normal_y,2) << "\n";
}

float Normal::getX(){
	return normal_x;
}

float Normal::getY(){
	return normal_y;
}

void Normal::projectVector(float &x, float &y){
	float dp = (x*normal_x + y*normal_y);
	x = dp * normal_x;
	y = dp * normal_y;
}

void Normal::addObject(std::vector<float> px, std::vector<float> py){
	for(unsigned int i=0; i<px.size(); i++){
		projectVector(px[i],py[i]);
	}
	NormalObject o(px, py, normal_x, normal_y);
	objects.push_back(o);
}

void Normal::addObject(float px, float py, float r){
	projectVector(px, py);
	NormalObject o(px, py, r, normal_x, normal_y);
	objects.push_back(o);
}

void Normal::draw(sf::RenderWindow &window){
	sf::VertexArray vert(sf::Lines);
	vert.append(sf::Vector2f(normal_x * -1000,normal_y * -1000));
	vert.append(sf::Vector2f(normal_x * 1000,normal_y * 1000));
	
	for(unsigned int i=0; i<objects.size(); i++){
		//std::cout << "Object: " << i << "\n";
		objects[i].getVert(vert);
	}
	window.draw(vert);
}

bool Normal::checkCollision(){
	unsigned int c = 0;
	for(unsigned int i=1; i<objects.size(); i++){
		float size = objects[c].max - objects[c].min + objects[i].max - objects[i].min;
		float dist1 = objects[c].max - objects[i].min;
		float dist2 = objects[i].max - objects[c].min;
		if (dist1 > 0 && dist1 < size){
			return true;
		}
		if (dist2 > 0 && dist2 < size){
			return true;
		}
	}
	return false;
}

bool Normal::checkCollision(bool &center){
	unsigned int c = 0;
	for(unsigned int i=1; i<objects.size(); i++){
		float size = objects[c].max - objects[c].min + objects[i].max - objects[i].min;
		float dist1 = objects[c].max - objects[i].min;
		float dist2 = objects[i].max - objects[c].min;
		if (dist1 > 0 && dist1 < size && dist1 < dist2){
			float csize = objects[i].max - objects[i].min;
			if (dist1 > csize/2) center = true;
			return true;
		}
		if (dist2 > 0 && dist2 < size){
			float csize = objects[i].max - objects[i].min;
			if (dist2 > csize/2) center = true;
			return true;
		}
	}
	return false;
}

sf::Vector2f Normal::collision(float &dist, bool &coll){
	unsigned int c = 0;
	coll = false;
	for(unsigned int i=1; i<objects.size(); i++){
		float size = objects[c].max - objects[c].min + objects[i].max - objects[i].min;
		float dist1 = objects[c].max - objects[i].min;
		float dist2 = objects[i].max - objects[c].min;
		if (dist1 > 0 && dist1 < size && dist1 < dist2){
			coll = true;
			if (dist1 < dist){//if distance is bigger collision can be ignored
				dist = dist1;
				float x = normal_x * dist1;
				float y = normal_y * dist1;
				return sf::Vector2f(x, y);
			}
			return sf::Vector2f(0,0);
		}
		if (dist2 > 0 && dist2 < size){
			coll = true;
			if (dist2 < dist){
				dist = dist2;
				float x = normal_x * dist2;
				float y = normal_y * dist2;
				return sf::Vector2f(x, y);
			}
			return sf::Vector2f(0,0);
		}
	}
	return sf::Vector2f(0,0);
}

sf::Vector2f Normal::collision(float &dist, bool &coll, bool &update){
	unsigned int c = 0;
	coll = false; update = false;
	for(unsigned int i=1; i<objects.size(); i++){
		float size = objects[c].max - objects[c].min + objects[i].max - objects[i].min;
		float dist1 = objects[c].max - objects[i].min;
		float dist2 = objects[i].max - objects[c].min;
		if (dist1 > 0 && dist1 < size && dist1 < dist2){
			coll = true;
			if (dist1 < dist){//if distance is bigger collision can be ignored
				//std::cout << "dist1\n";
				dist = dist1;
				float x = normal_x * dist1;
				float y = normal_y * dist1;
				update = true;
				return sf::Vector2f(x, y);
			}
			return sf::Vector2f(0,0);
		}
		if (dist2 > 0 && dist2 < size){
			coll = true;
			if (dist2 < dist){
				//std::cout << "dist2\n";
				dist = dist2;
				float x = normal_x * dist2;
				float y = normal_y * dist2;
				update = true;
				return sf::Vector2f(-x, -y);
			}
			return sf::Vector2f(0,0);
		}
	}
	return sf::Vector2f(0,0);
}
