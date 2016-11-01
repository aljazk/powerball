#include "Normals.hpp"

Normals::Normals(){
	circle_set = false;
}

void Normals::add(float x, float y){
	Normal n(x,y);
	add(n);
}

void Normals::add(std::vector<float> x, std::vector<float> y){
	for(unsigned int i=0; i<x.size(); i++){
		add(x[i], y[i]);
	}
}
void Normals::add(const Normal &new_normal){
	Normal n = new_normal;
	if(!checkSame(n)){
		normals.emplace(std::make_shared<Normal>(new_normal));
	}
}
bool Normals::checkSame(Normal &c_normal){
	for (const auto& n: normals){
		if (c_normal.getX() == n->getX() && c_normal.getY() == n->getY()){
			return true;
		}
		if (c_normal.getX() == -n->getX() && c_normal.getY() == -n->getY()){
			return true;
		}
	}
	return false;
}

void Normals::clear(){
	normals.clear();
}

void Normals::draw(sf::RenderWindow& window){
	for (const auto& n: normals){
		n->draw(window);
	}
}

void Normals::setObjects(const Polygon &n_p1, const Polygon &n_p2){
	p1 = n_p1;
	p2 = n_p2;
	circle_set = false;
}

void Normals::setObjects(const Polygon &n_p1, const Circle &n_c){
	p1 = n_p1;
	c = n_c;
	circle_set = true;
}

bool Normals::checkCollision(){
	std::vector<float> x, y;
	p1.getNormals(x, y);
	if(!circle_set){
		p2.getNormals(x, y);
	}
	add(x, y);
	bool center = false;
	for (const auto& n: normals){
		n->setObject1(p1.getX(), p1.getY());
		if(!circle_set){
			n->setObject2(p2.getX(), p2.getY());
		} else {
			n->setObject2(c.getX(), c.getY(), c.getR());
		}
		if (!n->checkCollision(center)){
			return false;
		}
	}
	//std::cout << center << "\n";
	//std::cout << "Normals checked: " << normals.size() << "\n";
	if(circle_set && !center){
		sf::Vector2f cp = p1.getClosestPoint(c.getX(), c.getY());
		Circle cc(cp.x, cp.y, 0);
		/*
		std::cout << "Circle: " << c.getX() << " " << c.getY() << "\n";
		std::cout << "Point: " << cc.getX() << " " << cc.getY() << "\n";
		*/
		if(!Collision::check(c, cc)){
			return false;
		}
	}
	return true;
}

sf::Vector2f Normals::collision(){
	std::vector<float> x, y;
	p1.getNormals(x, y);
	if(!circle_set){
		p2.getNormals(x, y);
	}
	add(x, y);
	float dist = FLT_MAX;
	sf::Vector2f return_v;
	for (const auto& n: normals){
		n->setObject1(p1.getX(), p1.getY());
		if(!circle_set){
			n->setObject2(p2.getX(), p2.getY());
		} else {
			n->setObject2(c.getX(), c.getY(), c.getR());
		}
		bool coll = false; bool update = false;
		sf::Vector2f v = n->collision(dist, coll, update); //doesnt return right direction
		//std::cout << "\nv: " << v.x << " " << v.y << "\n";
		if (!coll){
			return v;
		} else if (update) {
			//std::cout << " set ";
			return_v = v;
		}
	}
	if(circle_set){
		sf::Vector2f cp = p1.getClosestPoint(c.getX(), c.getY());
		Circle cc(cp.x, cp.y, 0);
		sf::Vector2f cv = Collision::get(c, cc);
		if (cv.x != 0 && cv.y != 0){ // may fail
			//std::cout << " set ";
			return_v = cv;
		}
	}
	//std::cout << "Normals checked: " << normals.size() << "\n";
	//std::cout << " -return " << dist << "\n";
	return return_v;
}