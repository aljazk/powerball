#include "Map.hpp"

Map::Map(){

}

void Map::clear(){
	polygons.clear();
	circles.clear();
}

void Map::add(Polygon &new_polygon){
	polygons.push_back(new_polygon);
}

void Map::add(std::vector<Polygon> &new_polygons){
	for(unsigned int i=0; i<new_polygons.size(); i++){
		polygons.push_back(new_polygons[i]);
	}
}

void Map::add(Circle &new_circle){
	circles.push_back(new_circle);
}

void Map::add(std::vector<Circle> &new_circles){
	for(unsigned int i=0; i<new_circles.size(); i++){
		circles.push_back(new_circles[i]);
	}
}

void Map::checkCollision(){
	checkPolygonCollision();
	checkCircleCollision();
	checkCircleToPolygonCollision();
}

void Map::checkPolygonCollision(){
	for(unsigned int i=0; i<polygons.size(); i++){
		for(unsigned int j=0; j<polygons.size(); j++){
			if (i != j){
				if (Collision::check(polygons[i], polygons[j])){
					polygons[i].colliding = true;
				}
			}
		}
	}
}

void Map::checkCircleCollision(){
	for(unsigned int i=0; i<circles.size(); i++){
		for(unsigned int j=0; j<circles.size(); j++){
			if(i != j){
				if (Collision::check(circles[i], circles[j])){
					circles[i].colliding = true;
				}
			}
		}
	}
}

void Map::checkCircleToPolygonCollision(){
	for(unsigned int i=0; i<polygons.size(); i++){
		for(unsigned int j=0; j<circles.size(); j++){
			if (Collision::check(polygons[i], circles[j])){
				polygons[i].colliding = true;
				circles[j].colliding = true;
			}
		}
	}
}

void Map::draw(sf::RenderWindow &window){
	for(unsigned int i=0; i<polygons.size(); i++){
		polygons[i].draw(window);
	}
	for(unsigned int i=0; i<circles.size(); i++){
		circles[i].draw(window);
	}
}