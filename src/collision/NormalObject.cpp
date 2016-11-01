#include "NormalObject.hpp"

NormalObject::NormalObject(){
	set(0,0,0,0, 0);
}

NormalObject::NormalObject(const std::vector<float> px, const std::vector<float> py, float nx, float ny){
	set(px, py, nx, ny);
}

NormalObject::NormalObject(float px, float py, float r, float nx, float ny){
	set(px, py, r, nx, ny);
}
/*
void NormalObject::set(const std::vector<float> px, const std::vector<float> py){
	min = 0, max = 0;
	unsigned int min_id, max_id;
	for(unsigned int i=0; i<px.size(); i++){
		float l = sqrt(pow(px[i],2) + pow(py[i],2));
		if (l < min || min == 0){
			min = l;
			min_id = i;
		} 
		if (l > max || max == 0){
			max = l;
			max_id = i;
		}
	}
	min_x = px[min_id];
	min_y = py[min_id];
	max_x = px[max_id];
	max_y = py[max_id];
	min = sqrt(pow(min_x,2) + pow(min_y,2));
	max = sqrt(pow(max_x,2) + pow(max_y,2));
	//std::cout << "min: " << min << " max: " << max << "\n";
}
*/
void NormalObject::set(const std::vector<float> px, const std::vector<float> py, float nx, float ny){
	min = INT_MAX, max = INT_MIN;
	unsigned int min_id, max_id;
	for(unsigned int i=0; i<px.size(); i++){
		float l = px[i] * nx + py[i] * ny;
		//std::cout << px[i]*nx << " + " << py[i]+ny << " = " << l << "\n";
		//std::cout << l << "\n";
		if (l < min){
			min = l;
			min_id = i;
		} 
		if (l > max){
			max = l;
			max_id = i;
		}
	}
	min_x = px[min_id];
	min_y = py[min_id];
	max_x = px[max_id];
	max_y = py[max_id];
	//std::cout << "min: " << min_x << " " << min_y << std::endl;
	//std::cout << "max: " << min_x << " " << min_y << std::endl;
	min = min_x*nx + min_y*ny;
	max = max_x*nx + max_y*ny;
	//std::cout << "min: " << min << " max: " << max << "\n";
}

void NormalObject::set(float px, float py, float r, float nx, float ny){
	min = INT_MAX, max = INT_MIN;
	
	min_x = px - r * nx;
	min_y = py - r * ny;
	max_x = px + r * nx;
	max_y = py + r * ny;
	
	//std::cout << "min: " << min_x << " " << min_y << std::endl;
	//std::cout << "max: " << min_x << " " << min_y << std::endl;
	min = min_x*nx + min_y*ny;
	max = max_x*nx + max_y*ny;
	//std::cout << "min: " << min << " max: " << max << "\n";
}

void NormalObject::getVert(sf::VertexArray &vert){
	sf::Vertex v;
	v.color = sf::Color::Red;
	v.position = sf::Vector2f(min_x, min_y);
	vert.append(v);
	v.position = sf::Vector2f(max_x, max_y);
	vert.append(v);
}