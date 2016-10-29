#ifndef GIFTWRAPPING_H
#define GIFTWRAPPING_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cmath>

class GiftWrapping{
		std::vector<sf::Vector2f> point;
		std::vector<unsigned int> convex_hull;
		unsigned int getStartPoint();
		static unsigned int getStartPoint(const std::vector<sf::Vector2f> &);
		int orientation(const unsigned int, const unsigned int, const unsigned int);
		static int orientation(const sf::Vector2f, const sf::Vector2f, const sf::Vector2f);
		void wrap();
		static std::vector<unsigned int> wrap(const std::vector<sf::Vector2f> &);
	public:
		GiftWrapping();
		void setPoints(const std::vector<sf::Vector2f>);
		void setPoints(const std::vector<float>, const std::vector<float>);
		void addPoint(const sf::Vector2f);
		void addPoint(const float, const float);
		void draw(sf::RenderWindow &);
		
		std::vector<sf::Vector2f> getConvexHull();
		static std::vector<sf::Vector2f> getConvexHull(const std::vector<sf::Vector2f> &);
		

};

#endif