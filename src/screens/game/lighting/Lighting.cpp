#include "Lighting.hpp"

Lighting::Lighting(){
	if (!texture.loadFromFile("images/light.png"))
	{
		std::cout << "Cannot load texture images/light.png" << std::endl;
	}
	texture.setSmooth(true);
	
	quality = 1;
	texture_size_x = 1280/quality;
	texture_size_y = 720/quality;
	dark.create(texture_size_x, texture_size_y);
	dark.setSmooth(true);
	
	static_light.create(texture_size_x, texture_size_y);
	static_light.setSmooth(true);
	
	light.create(texture_size_x, texture_size_y);
	light.setSmooth(true);
	
	fullScreenVertex.setPrimitiveType(sf::Quads);
	sf::Vertex a;
	a.position.x = 0;
	a.position.y = 0;
	a.texCoords.x = 0;
	a.texCoords.y = 0;
	fullScreenVertex.append(a);
	a.position.x = 1280;
	a.position.y = 0;
	a.texCoords.x = texture_size_x;
	a.texCoords.y = 0;
	fullScreenVertex.append(a);
	a.position.x = 1280;
	a.position.y = 720;
	a.texCoords.x = texture_size_x;
	a.texCoords.y = texture_size_y;
	fullScreenVertex.append(a);
	a.position.x = 0;
	a.position.y = 720;
	a.texCoords.x = 0;
	a.texCoords.y = texture_size_y;
	fullScreenVertex.append(a);
	
	qualityVertex.setPrimitiveType(sf::Quads);
	a.position.x = 0;
	a.position.y = 0;
	a.texCoords.x = 0;
	a.texCoords.y = 0;
	qualityVertex.append(a);
	a.position.x = texture_size_x;
	a.position.y = 0;
	a.texCoords.x = texture_size_x;
	a.texCoords.y = 0;
	qualityVertex.append(a);
	a.position.x = texture_size_x;
	a.position.y = texture_size_y;
	a.texCoords.x = texture_size_x;
	a.texCoords.y = texture_size_y;
	qualityVertex.append(a);
	a.position.x = 0;
	a.position.y = texture_size_y;
	a.texCoords.x = 0;
	a.texCoords.y = texture_size_y;
	qualityVertex.append(a);
}

void Lighting::setPosition(const float x, const float y){
	lights[0].setPosition(x,y);
}

void Lighting::addLight(const Light &new_light){
	lights.push_back(new_light);
}

void Lighting::addStaticLight(const Light &new_light){
	Light light_ = new_light;
	sf::VertexArray vert(sf::Quads);
	states.texture = &light.getTexture();
	states.blendMode = sf::BlendAdd;
	light.clear(sf::Color::Black);
	light_.getVert(vert);
	light.draw(vert, &texture);
	vert.clear();
	shadows(vert, light_.getPosition());
	light.draw(vert);
	static_light.draw(qualityVertex, states);
	static_light.display();
}

void Lighting::shadows(sf::VertexArray &vert, const sf::Vector2f light_position){
	sf::Vertex v;
	v.color = sf::Color::Black;
	std::vector<sf::Vector2f> wall;
	wall.push_back(sf::Vector2f(550,350));
	wall.push_back(sf::Vector2f(600,350));
	wall.push_back(sf::Vector2f(600,400));
	wall.push_back(sf::Vector2f(550,400));
	Polygon poly(wall);
	wall.push_back(sf::Vector2f(550,350));
	for(unsigned int i=0; i<wall.size()-1; i++){
		v.position.x = wall[i].x / quality;
		v.position.y = wall[i].y / quality;
		vert.append(v);
	}
	//sf::VertexArray test(sf::Quads);
	unsigned int dots = 6;
	unsigned int actual = dots;
	for(unsigned int i=0; i<dots; i++){
		float r = 10;
		float lposx = light_position.x + r * cos(atan(1)*8 / dots * i);
		float lposy = light_position.y + r * sin(atan(1)*8 / dots * i);
		//check if light is inside the wall
		Circle c(lposx, lposy, 0);
		if(!Collision::check(poly, c)){
			/*
			v.color = sf::Color::Red;
			v.position.x = lposx;
			v.position.y = lposy;
			test.append(v);
			v.position.x = lposx+1;
			v.position.y = lposy;
			test.append(v);
			v.position.x = lposx+1;
			v.position.y = lposy+1;
			test.append(v);
			v.position.x = lposx;
			v.position.y = lposy+1;
			test.append(v);
			*/
		} else {
			actual--;
			continue;
		}
		
		for(unsigned int i=0; i<wall.size()-1; i++){
			v.position.x = wall[i].x / quality;
			v.position.y = wall[i].y / quality;
			vert.append(v);
			v.position.x = wall[i+1].x / quality;
			v.position.y = wall[i+1].y / quality;
			vert.append(v);
			float npx, npy;
			npx = wall[i+1].x + (wall[i+1].x - lposx ) * 100000;
			npy = wall[i+1].y + (wall[i+1].y - lposy ) * 100000;
			v.position = sf::Vector2f(npx/quality, npy/quality);
			vert.append(v);
			npx = wall[i].x + (wall[i].x - lposx ) * 100000;
			npy = wall[i].y + (wall[i].y - lposy ) * 100000;
			v.position = sf::Vector2f(npx/quality, npy/quality);
			vert.append(v);
		}
	}
	for(unsigned int i=4; i<vert.getVertexCount(); i++){
		unsigned int darkness = 200/actual;
		//std::cout << "actual dots: " << actual << "\nshadow darkness: " << darkness << std::endl;
		vert[i].color = sf::Color(0,0,0,darkness+55);
	}
	/*
	for(unsigned int i=0; i<test.getVertexCount(); i++){
		vert.append(test[i]);
	}
	*/
}

void Lighting::draw(sf::RenderWindow &window){
	sf::VertexArray vert(sf::Quads);
	dark.clear(sf::Color::Black);
	states.texture = &light.getTexture();
	states.blendMode = sf::BlendAdd;
	for(unsigned int i=0; i<lights.size(); i++){
		light.clear(sf::Color::Black);
		lights[i].getVert(vert);
		light.draw(vert, &texture);
		vert.clear();
		shadows(vert, lights[i].getPosition());
		light.draw(vert);
		dark.draw(qualityVertex, states);
	}
	states.texture = &static_light.getTexture();
	dark.draw(qualityVertex, states);
	dark.display();
	states.blendMode = sf::BlendMultiply;
	states.texture = &dark.getTexture();
	window.draw(fullScreenVertex, states);
}