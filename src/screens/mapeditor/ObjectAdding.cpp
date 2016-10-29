#include "ObjectAdding.hpp"

ObjectAdding::ObjectAdding(){
	reset();
}

void ObjectAdding::key(const sf::Event &event, const sf::RenderWindow &window, Level &level){
	if (event.type == sf::Event::MouseMoved){
		sf::Vector2i mPos = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);
		sf::Vector2f pos = window.mapPixelToCoords(mPos);
		if(pos.x > 0){
			pos.x += gridSize/2;
		} else {
			pos.x -= gridSize/2;
		}
		pos.x = int(pos.x/gridSize);
		pos.x *= gridSize;
		if(pos.y > 0){
			pos.y += gridSize/2;
		} else {
			pos.y -= gridSize/2;
		}
		pos.y = int(pos.y/gridSize);
		pos.y *= gridSize;
		mouse_position = sf::Vector2i(pos.x, pos.y);
	}
	if (event.type == sf::Event::MouseButtonPressed){
		if (event.mouseButton.button == sf::Mouse::Left && !mLeft){
			sf::Vector2i mPos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
			sf::Vector2f pos = window.mapPixelToCoords(mPos);
			if(pos.x > 0){
				pos.x += gridSize/2;
			} else {
				pos.x -= gridSize/2;
			}
			pos.x = int(pos.x/gridSize);
			pos.x *= gridSize;
			if(pos.y > 0){
				pos.y += gridSize/2;
			} else {
				pos.y -= gridSize/2;
			}
			pos.y = int(pos.y/gridSize);
			pos.y *= gridSize;
			addPoint(pos);
			mLeft = true;
		}
		if (event.mouseButton.button == sf::Mouse::Right && !mRight){
			if(points.size() == 4){
				level.addWall(points);
			}
			points.clear();
			mRight =  true;
		}
	}
	if (event.type == sf::Event::MouseButtonReleased ){
		if (event.mouseButton.button == sf::Mouse::Left){
			mLeft = false;
		}
		if (event.mouseButton.button == sf::Mouse::Right){
			mRight = false;
		}
	}
}

void ObjectAdding::addPoint(const float x, const float y){
	addPoint(sf::Vector2f(x,y));
}

void ObjectAdding::addPoint(sf::Vector2f pos){
	std::cout << pos.x << " " << pos.y << std::endl;
	points.push_back(pos);
	if(points.size() > 2){
		points = GiftWrapping::getConvexHull(points);
	}
}

void ObjectAdding::popPoint(){
	points.pop_back();
}

void ObjectAdding::reset(){
	points.clear();
	mLeft = false;
	mRight = false;
	gridSize = 1;
	mode = -1;
}

void ObjectAdding::draw(sf::RenderWindow &window){
	std::vector<sf::Vector2f> draw_points = points;
	draw_points.push_back(sf::Vector2f(mouse_position.x, mouse_position.y));
	if(draw_points.size() > 3){
		draw_points = GiftWrapping::getConvexHull(draw_points);
	}
	if (draw_points.size() > 0){
		sf::VertexArray vert(sf::LinesStrip);
		for(unsigned int i=0; i<draw_points.size(); i++){
			vert.append(draw_points[i]);
		}
		vert.append(draw_points[0]);
		window.draw(vert);
	}
}

void ObjectAdding::drawGrid(sf::RenderWindow &window){
	sf::VertexArray vert(sf::Lines);
	sf::Vector2u wSize = window.getSize();
	sf::Vertex v;
	v.color = sf::Color(255,255,255,50);
	sf::Vector2f s = window.mapPixelToCoords(sf::Vector2i(0,0));
	sf::Vector2f w = window.mapPixelToCoords(sf::Vector2i(wSize.x,wSize.y));
	for(int i=s.x/gridSize; i<w.x/gridSize; i++){
		v.position.x = i*(int)gridSize;
		v.position.y = s.y;
		vert.append(v);
		v.position.y = w.y;
		vert.append(v);
	}
	for(int i=s.y/gridSize; i<w.y-s.y/gridSize; i++){
		v.position.y = i*(int)gridSize;
		v.position.x = s.x;
		vert.append(v);
		v.position.x = w.x;
		vert.append(v);
	}
	window.draw(vert);
}