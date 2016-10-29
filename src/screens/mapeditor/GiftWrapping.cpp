#include "GiftWrapping.hpp"

GiftWrapping::GiftWrapping(){

}

unsigned int GiftWrapping::getStartPoint(){
	float small_x = point[0].x;
	unsigned int id = 0;
	for(unsigned int i=1; i<point.size(); i++){
		if(point[i].x < small_x){
			small_x = point[i].x;
			id = i;
		}
	}
	return id;
}

unsigned int GiftWrapping::getStartPoint(const std::vector<sf::Vector2f> &points){
	float small_x = points[0].x;
	unsigned int id = 0;
	for(unsigned int i=1; i<points.size(); i++){
		if(points[i].x < small_x){
			small_x = points[i].x;
			id = i;
		}
	}
	return id;
}

int GiftWrapping::orientation(const unsigned int id_1, const unsigned int id_2, const unsigned int id_3){ // p q r
	int val = (point[id_2].y - point[id_1].y) * (point[id_3].x - point[id_2].x) - (point[id_2].x - point[id_1].x) * (point[id_3].y - point[id_2].y);
	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}

int GiftWrapping::orientation(const sf::Vector2f p1, const sf::Vector2f p2, const sf::Vector2f p3){
	int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}

void GiftWrapping::wrap(){
	std::vector<unsigned int> ids;
	ids.push_back(getStartPoint());
	bool loop = true;
	while(loop){
		unsigned int id = ids[ids.size()-1];
		unsigned int m_id = 0;
		if (id == 0) m_id = 1;
		for(unsigned int i=0; i<point.size(); i++){
			if (orientation(id, i, m_id) == 2){
                m_id = i;
			}
		}
		if(m_id == ids[0]){
			break;
		}
		ids.push_back(m_id);
	}
	convex_hull = ids;
}

std::vector<unsigned int> GiftWrapping::wrap(const std::vector<sf::Vector2f> &points){
	std::vector<unsigned int> ids;
	ids.push_back(getStartPoint(points));
	bool loop = true;
	while(loop){
		unsigned int id = ids[ids.size()-1];
		unsigned int m_id = 0;
		if (id == 0) m_id = 1;
		for(unsigned int i=0; i<points.size(); i++){
			if (orientation(points[id], points[i], points[m_id]) == 2){
                m_id = i;
			}
		}
		if(m_id == ids[0]){
			break;
		}
		ids.push_back(m_id);
	}
	return ids;
}

void GiftWrapping::setPoints(const std::vector<sf::Vector2f> new_points){
	for(unsigned int i=0; i<new_points.size(); i++){
		point.push_back(new_points[i]);
	}
}

void GiftWrapping::setPoints(const std::vector<float> np_x, const std::vector<float> np_y){
	for(unsigned int i=0; i<np_x.size(); i++){
		point.push_back(sf::Vector2f(np_x[i], np_y[i]));
	}
}

void GiftWrapping::addPoint(const sf::Vector2f new_point){
	point.push_back(new_point);
}

void GiftWrapping::addPoint(const float nx, const float ny){
	point.push_back(sf::Vector2f(nx, ny));
}

void GiftWrapping::draw(sf::RenderWindow & window){
	wrap();
	sf::VertexArray vert(sf::Points);
	sf::Vertex v;
	v.color = sf::Color::Red;
	for(unsigned int i=0; i<point.size(); i++){
		v.position = point[i];
		vert.append(v);
	}
	window.draw(vert);
	vert.clear();
	vert.setPrimitiveType(sf::LinesStrip);
	v.color = sf::Color::White;
	for(unsigned int i=0; i<convex_hull.size(); i++){
		v.position = point[convex_hull[i]];
		vert.append(v);
	}
	v.position = point[convex_hull[0]];
	vert.append(v);
	window.draw(vert);
}

std::vector<sf::Vector2f> GiftWrapping::getConvexHull(){
	wrap();
	std::vector<sf::Vector2f> return_hull;
	for(unsigned int i=0; i<convex_hull.size(); i++){
		return_hull.push_back(point[convex_hull[i]]);
	}
	return return_hull;
}

std::vector<sf::Vector2f> GiftWrapping::getConvexHull(const std::vector<sf::Vector2f> &points){
	std::vector<unsigned int> hull = wrap(points);
	std::vector<sf::Vector2f> return_hull;
	for(unsigned int i=0; i<hull.size(); i++){
		return_hull.push_back(points[hull[i]]);
	}
	return return_hull;
	
}