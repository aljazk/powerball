#ifndef POLYGON_H
#define POLYGON_H

#include <math.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cfloat>
#include "../Normal.hpp"

class Polygon{
		std::vector < sf::Vector2f > points;
		sf::Vector2f position;
	public:
		Polygon();
		Polygon(std::vector< sf::Vector2f >);
		void addPoint(float,float);
		void addPoint(sf::Vector2f);
		void setPoints(std::vector< sf::Vector2f >);
		void setPoints(std::vector< float >, std::vector < float >);
		void draw(sf::RenderWindow &window);
		void getVert(sf::VertexArray &);
		
		std::vector< float > getX();
		std::vector< float > getY();
		void getNormals(std::vector< float > &, std::vector< float > &);
		sf::Vector2f getClosestPoint(const float, const float);
		
		bool colliding;
		unsigned int object_id;
		
		void setPosition(float, float);
		void transfer(float, float);
};

#endif